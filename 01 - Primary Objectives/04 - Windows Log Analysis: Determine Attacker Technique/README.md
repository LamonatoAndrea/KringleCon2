# 1. Primary Objectives
## 1.4. Windows Log Analysis: Determine Attacker Technique
### 1.4.1. Description
Using these normalized Sysmon logs, identify the tool the attacker used to retrieve domain password hashes from the lsass.exe process. For hints on achieving this objective, please visit Hermey Hall and talk with SugarPlum Mary.
### 1.4.2. Solution
The sysmon-data.json.zip contains the sysmon-data.json file with sysmon logs in JSON format.
Searching for “lsass” takes to process PID 3440:
```json
{
	"command_line": "C:\\Windows\\system32\\cmd.exe",
	"event_type": "process",
	"logon_id": 999,
	"parent_process_name": "lsass.exe",
	"parent_process_path": "C:\\Windows\\System32\\lsass.exe",
	"pid": 3440,
	"ppid": 632,
	"process_name": "cmd.exe",
	"process_path": "C:\\Windows\\System32\\cmd.exe",
	"subtype": "create",
	"timestamp": 132186398356220000,
	"unique_pid": "{7431d376-dedb-5dd3-0000-001027be4f00}",
	"unique_ppid": "{7431d376-cd7f-5dd3-0000-001013920000}",
	"user": "NT AUTHORITY\\SYSTEM",
	"user_domain": "NT AUTHORITY",
	"user_name": "SYSTEM"
}
```
Digging further on lsass PID, I searched for process spawned from it identifying a common ntdsutil command line used to dump passwords on Windows systems:
```json
{
	"command_line": "ntdsutil.exe \"ac i ntds\" ifm \"create full c:\\hive\" q q",
	"event_type": "process",
	"logon_id": 999,
	"parent_process_name": "cmd.exe",
	"parent_process_path": "C:\\Windows\\System32\\cmd.exe",
	"pid": 3556,
	"ppid": 3440,
	"process_name": "ntdsutil.exe",
	"process_path": "C:\\Windows\\System32\\ntdsutil.exe",
	"subtype": "create",
	"timestamp": 132186398470300000,
	"unique_pid": "{7431d376-dee7-5dd3-0000-0010f0c44f00}",
	"unique_ppid": "{7431d376-dedb-5dd3-0000-001027be4f00}",
	"user": "NT AUTHORITY\\SYSTEM",
	"user_domain": "NT AUTHORITY",
	"user_name": "SYSTEM"
}
```
### 1.4.3. Flag
The flag is: ​**ntdsutil​**.