import re

regex = re.compile("<Event.*?<EventID Qualifiers=\"\">(4624)<\/EventID>.*?<Data Name=\"TargetUserName\">(.*?)<\/Data>.*?<\/Event>", re.MULTILINE | re.DOTALL)

logs = open("Security.evtx.xml", "r", encoding="ISO-8859-1").read()

logons = re.findall(regex, logs)
for logon in logons:
	print (logon)
