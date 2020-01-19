# 1. Primary Objectives
## 1.3. Windows Log Analysis: Evaluate Attack Outcome
### 1.3.1. Description
We're seeing attacks against the Elf U domain! Using the event log data, identify the user account that the attacker compromised using a password spray attack. Bushy Evergreen is hanging out in the train station and may be able to help you out.
### 1.3.2. Solution
The Security.evtx.zip contains a Security.evtx file of a Microsoft system that can be converted to an XML file using python-evtx module and the evtx_dump.py script from its github.

From the XML with just a few python lines and a regex I extracted successful 4624 logon events
identifying below 2 potential users:
* pminstix
* supatree

### 1.3.3. Flag
The flag is: ​**supatree​**.

### 1.3.4. Attachments
#### 1.3.4.1. get4624.py
```python
import re

regex = re.compile("<Event.*?<EventID Qualifiers=\"\">(4624)<\/EventID>.*?<Data Name=\"TargetUserName\">(.*?)<\/Data>.*?<\/Event>", re.MULTILINE | re.DOTALL)

logs = open("Security.evtx.xml", "r", encoding="ISO-8859-1").read()

logons = re.findall(regex, logs)
for logon in logons:
	print (logon)
```
#### 1.3.4.2. get4624.py output
```
('4624', 'pminstix')
('4624', 'DC1$')
('4624', 'pminstix')
('4624', 'DC1$')
('4624', 'supatree')
('4624', 'DC1$')
[...omissis...]
('4624', 'DC1$')
('4624', 'supatree')
('4624', 'DC1$')
('4624', 'DC1$')
```