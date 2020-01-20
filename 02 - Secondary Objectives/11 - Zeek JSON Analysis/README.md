# 2. Secondary Objectives
## 2.11. Zeek JSON Analysis
### 2.11.1. Description
I think for some reason my whole first chat with Wunorse Openslae is missing...or never existed at all :)

Zeek JSON Analysis motd:
```
Some JSON files can get quite busy.
There's lots to see and do.
Does C&C lurk in our data?
JQ's the tool for you!

-Wunorse Openslae

Identify the destination IP address with the longest connection duration
using the supplied Zeek logfile. Run runtoanswer to submit your answer.

elf@4278cf5385ef:~$
```
### 2.11.2. Solution
```bash
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
```
### 2.11.3. Afterwords
Speaking again with Wunorse Openslae:
>That's got to be the one - thanks! Hey, you know what? We've got a crisis here. You see, Santa's flight route is planned by a complex set of machine learning algorithms which use available weather data. All the weather stations are reporting severe weather to Santa's Sleigh. I think someone might be forging intentionally false weather data! I'm so flummoxed I can't even remember how to login! Hmm... Maybe the Zeek http.log could help us. I worry about LFI, XSS, and SQLi in the Zeek log - oh my! And I'd be shocked if there weren't some shell stuff in there too. I'll bet if you pick through, you can find some naughty data from naughty hosts and block it in the firewall. If you find a log entry that definitely looks bad, try pivoting off other unusual attributes in that entry to find more bad IPs. The sleigh's machine learning device (SRF) needs most of the malicious IPs blocked in order to calculate a good route. Try not to block many legitimate weather station IPs as that could also cause route calculation failure. Remember, when looking at JSON data, jq is the tool for you!
