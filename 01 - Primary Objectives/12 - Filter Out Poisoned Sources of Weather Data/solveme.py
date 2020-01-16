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