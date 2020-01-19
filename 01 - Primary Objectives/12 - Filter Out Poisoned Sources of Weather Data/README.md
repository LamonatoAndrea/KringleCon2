# 1. Primary Objectives
## 1.12. Filter Out Poisoned Sources of Weather Data
### 1.12.1. Description
Use the data supplied in the Zeek JSON logs to identify the IP addresses of attackers poisoning Santa's flight mapping software. Block the 100 offending sources of information to guide Santa's sleigh through the attack. Submit the Route ID ("RID") success value that you're given. For hints on achieving this objective, please visit the Sleigh Shop and talk with Wunorse Openslae.
### 1.12.2. Solution
The first issue with this challenge was to find out the password to access the portal, after some
unsuccessful tests with SQLi attacks, I imported logs inside a local Splunk instance to do some quick queries that led me to a README.md file, that also matched the info in the PDF decrypted from challenge 10. This file contains admin credentials:
	admin 924158F9522B3744F5FCD4D10FAC4356

Following the hint from Wunorse Openslae:
	I worry about LFI, XSS, and SQLi in the Zeek log - oh my!
	And I'd be shocked if there weren't some shell stuff in there too.
	I'll bet if you pick through, you can find some naughty data from naughty hosts and block it in the firewall.
	If you find a log entry that definitely looks bad, try pivoting off other unusual attributes in that entry to find more bad IPs.

I filtered with Splunk until I obtained 75 unique malicious IPs and found strange entries in the user agent field, therefore I decided to write a little script to dig further on this field. Initially I had 291 unique malicious IPs, so I implemented a threshold to include user agents, obtaining a total of 110 entries then, when submitted as Deny via the GUI to the SRF provided the Route ID.

### 1.12.3. JQ Solution
Not being a huge JQ fan, I resolved the challenge with python at first. For the sake of the challenge, I decided to develop also a JQ filter to get the solution that can be found in attachment 1.12.5.5. The filter can be provided to jq as file with the command:
```bash
jq -r -f $jqFilter $http_log
```
### 1.12.4. Flag
The flag is: ​ **0807198508261964​** .
### 1.12.5. Attachments
#### 1.12.5.1. Splunk query to get README.md
```splunk
*
status_code="200"
NOT uri="*js*" NOT uri="*css*" NOT uri="*img*" NOT uri="*station*" NOT uri="*logout*"
NOT resp_mime_types="*json*" NOT resp_mime_types="*font*"
| stats count by uri
```
#### 1.12.5.2. Output of the Splunk query

| uri | count |
|--|--|
| / | 451 |
| /README.md | 1 |
| /apidocs.pdf | 448 |

#### 1.12.5.3. README.md
````
# Sled-O-Matic - Sleigh Route Finder Web API
### Installation
```
sudo apt install python3-pip
sudo python3 -m pip install -r requirements.txt
```
#### Running:
`python3 ./srfweb.py`
#### Logging in:
You can login using the default admin pass:
`admin 924158F9522B3744F5FCD4D10FAC4356`
However, it's recommended to change this in the sqlite db to something custom.
````
#### 1.12.5.4. solveme.py
```python
import json

##
# ATTACK RECON STRINGS
## 
# SQLi
recon_sqli = "'"
# XSS
recon_xss = "<script"
# LFI
recon_lfi = "pass"
# Shellshock
recon_ss = ":; };"
##
# USER AGENT INCLUDE TRESHOLD
##
treshold_ua = 3

##
# LOAD DATA
##
logs = json.loads(open("http.log", "r").read())

##
# Find attacks
##
malicious_ips = []
malicious_userAgents = {}
for log in logs:
	if (recon_sqli in log['username']   or # SQLi - Username 
		recon_xss  in log['username']   or # XSS  - Username 
		recon_lfi  in log['username']   or # LFI  - Username 
		recon_ss   in log['username']   or # SS   - Username 
		recon_sqli in log['uri']        or # SQLi - URI
		recon_xss  in log['uri']        or # XSS  - URI
		recon_lfi  in log['uri']        or # LFI  - URI
		recon_ss   in log['uri']        or # SS   - URI
		recon_sqli in log['user_agent'] or # SQLi - User agent
		recon_xss  in log['user_agent'] or # XSS  - User agent
		recon_lfi  in log['user_agent'] or # LFI  - User agent
		recon_ss   in log['user_agent'] or # SS   - User agent
		recon_sqli in log['host']       or # SQLi - Host
		recon_xss  in log['host']       or # XSS  - Host
		recon_lfi  in log['host']       or # LFI  - Host
		recon_ss   in log['host']       ): # SS   - Host
			if not log['id.orig_h'] in malicious_ips:
				malicious_ips.append(log['id.orig_h'])
			if not log['user_agent'] in malicious_userAgents:
				malicious_userAgents[log['user_agent']] = 1
			else:
				malicious_userAgents[log['user_agent']] += 1

print ("Got {} unique malicious IPs".format(len(malicious_ips)))
print ("Got {} unique malicious User Agents".format(len(malicious_userAgents)))

##
# PIVOT USER AGENTS
##
malicious_userAgents_recount = {}
for log in logs:
	if (log['user_agent'] in malicious_userAgents and
		not log['id.orig_h'] in malicious_ips):

		if not log['user_agent'] in malicious_userAgents_recount:
			malicious_userAgents_recount[log['user_agent']] = 1
		else:
			malicious_userAgents_recount[log['user_agent']] += 1

for log in logs:
	if (log['user_agent'] in malicious_userAgents_recount and
		malicious_userAgents_recount[log['user_agent']] < treshold_ua and
		not log['id.orig_h'] in malicious_ips):
		malicious_ips.append(log['id.orig_h'])

##
# OUTPUT
##
print ("Got {} unique malicious IPs after pivoting User agents".format(len(malicious_ips)))
print ("")
print ("##")
print ("# PRINT SORTED DATA")
print ("##")
malicious_ips.sort() # If NOT sorted DOESN'T work
print ("{}".format(",".join(malicious_ips)))
```
#### 1.12.5.5. solveme.py output
```
Got 75 unique malicious IPs
Got 72 unique malicious User Agents
Got 110 unique malicious IPs after pivoting User agents

##
# PRINT SORTED DATA
##
0.216.249.31,1.185.21.112,10.122.158.57,10.155.246.29,102.143.16.184,103.235.93.133,104.179.109.113,106.132.195.153,106.93.213.219,111.81.145.191,116.116.98.205,118.196.230.170,118.26.57.38,121.7.186.163,123.127.233.97,126.102.12.53,129.121.121.48,13.39.153.254,131.186.145.73,132.45.187.177,135.203.243.43,135.32.99.116,140.60.154.239,142.128.135.10,148.146.134.52,150.45.133.97,150.50.77.238,158.171.84.209,168.66.108.62,169.242.54.5,173.37.160.150,180.57.20.247,185.19.7.133,186.28.46.179,187.152.203.243,187.178.169.123,19.235.69.221,190.245.228.38,193.228.194.36,194.143.151.224,2.230.60.70,2.240.116.254,200.75.228.240,203.68.29.5,211.229.3.254,217.132.156.225,22.34.153.164,220.132.33.81,223.149.180.133,225.191.220.138,226.102.56.13,226.240.188.154,227.110.45.126,229.133.163.235,229.229.189.246,23.49.177.78,230.246.50.221,231.179.108.238,233.74.78.199,238.143.78.114,249.237.77.152,249.34.9.16,249.90.116.138,25.80.197.172,250.22.86.40,250.51.219.47,252.122.243.212,253.182.102.55,253.65.40.39,254.140.181.172,27.88.56.114,28.169.41.122,29.0.183.220,31.116.232.143,31.254.228.4,33.132.98.193,34.129.179.28,34.155.174.167,37.216.249.50,42.103.246.250,42.127.244.30,42.16.149.112,42.191.112.181,44.164.136.41,44.74.106.131,45.239.232.245,48.66.193.176,49.161.8.58,50.154.111.0,52.39.201.107,53.160.218.44,56.5.47.137,61.110.82.125,65.153.114.120,66.116.147.181,68.115.251.76,69.221.145.150,75.215.214.65,75.73.228.192,79.198.89.109,80.244.147.207,81.14.204.154,83.0.8.119,84.147.231.129,84.185.44.166,87.195.80.126,9.206.212.33,92.213.148.0,95.166.116.45,97.220.93.190
```
#### 1.12.5.6. JQ filter
```jq
. as $original

| [
    $original[]
    | select (
              (.uri        | contains("'"))       or
              (.uri        | contains("<script")) or
              (.uri        | contains("pass"))    or
              (.uri        | contains(":; };"))   or
              (.username   | contains("'"))       or
              (.username   | contains("<script")) or
              (.username   | contains("pass"))    or
              (.username   | contains(":; };"))   or
              (.user_agent | contains("'"))       or
              (.user_agent | contains("<script")) or
              (.user_agent | contains("pass"))    or
              (.user_agent | contains(":; };"))   or
              (.host       | contains("'"))       or
              (.host       | contains("<script")) or
              (.host       | contains("pass"))    or
              (.host       | contains(":; };"))
             )
] as $malicious

| [ 
    $original[]
    | select ([.user_agent] | inside([$malicious[].user_agent]))
] 
| group_by(.user_agent)
| map ({user_agent: .[].user_agent, count: length}) 
| unique_by (.user_agent)
| [
    .[]
    | select (.count < 3)
] as $malicious_ua

| [
   $original[]
   | select (
             ([.user_agent] | inside([$malicious_ua[].user_agent])) and 
             ([."id.orig_h"] | inside([$malicious[]."id.orig_h"]) | not)
            )
] 
| unique_by(."id.orig_h")
| [.[]."id.orig_h"] as $malicious_ua_ips

| [$malicious[]."id.orig_h"] as $malicious_ips

| $malicious_ips + $malicious_ua_ips
| sort
| .[]
```