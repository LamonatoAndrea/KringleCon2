# 2. Secondary Objectives
## 2.3. Xmas Cheer Laser
### 2.3.1. Description
Speaking with Sparkle Redberry:
	I'm Sparkle Redberry and Imma chargin' my laser! Problem is: the settings are off. Do you know any PowerShell? It'd be GREAT if you could hop in and recalibrate this thing. It spreads holiday cheer across the Earth ... when it's working!

Xmas Cheer Laser motd:
```powershell
WARNGING: ctrl + c restricted in this terminal - Do not use endless loops
Type exit to exit PowerShell.

PowerShell 6.2.3
Copyright (c) Microsoft Corporation. All rights reserved.

https://aka.ms/pscore6-docs
Type 'help' to get help.

🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲
🗲                                                                                🗲
🗲 Elf University Student Research Terminal - Christmas Cheer Laser Project       🗲
🗲 ------------------------------------------------------------------------------ 🗲
🗲 The research department at Elf University is currently working on a top-secret 🗲
🗲 Laser which shoots laser beams of Christmas cheer at a range of hundreds of    🗲
🗲 miles. The student research team was successfully able to tweak the laser to   🗲
🗲 JUST the right settings to achieve 5 Mega-Jollies per liter of laser output.   🗲
🗲 Unfortunately, someone broke into the research terminal, changed the laser     🗲
🗲 settings through the Web API and left a note behind at /home/callingcard.txt.  🗲
🗲 Read the calling card and follow the clues to find the correct laser Settings. 🗲
🗲 Apply these correct settings to the laser using it's Web API to achieve laser  🗲
🗲 output of 5 Mega-Jollies per liter.                                            🗲
🗲                                                                                🗲
🗲 Use (Invoke-WebRequest -Uri http://localhost:1225/).RawContent for more info.  🗲
🗲                                                                                🗲
🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲🗲 

PS /home/elf>
```
### 2.3.2. Solution
```powershell
PS /home/elf> history

  Id CommandLine
  -- -----------
   1 Get-Help -Name Get-Process
   2 Get-Help -Name Get-*
   3 Set-ExecutionPolicy Unrestricted
   4 Get-Service | ConvertTo-HTML -Property Name, Status > C:\services.htm
   5 Get-Service | Export-CSV c:\service.csv
   6 Get-Service | Select-Object Name, Status | Export-CSV c:\service.csv
   7 (Invoke-WebRequest http://127.0.0.1:1225/api/angle?val=65.5).RawContent
   8 Get-EventLog -Log "Application"
   9 I have many name=value variables that I share to applications system wide. At a command…
  10 gci ENV:
  11 gci ENV:riddle

PS /home/elf> Get-History -Id 9 | %{$_.CommandLine}
I have many name=value variables that I share to applications system wide. At a command I will reveal my secrets once you Get my Child Items.

PS /home/elf> gci ENV:

Name                           Value
----                           -----
_                              /bin/su
DOTNET_SYSTEM_GLOBALIZATION_I… false
HOME                           /home/elf
HOSTNAME                       0fce02098487
LANG                           en_US.UTF-8
LOGNAME                        elf
MAIL                           /var/mail/elf
PATH                           /opt/microsoft/powershell/6:/usr/local/sbin:/usr/local/bin:/u…
PSModuleAnalysisCachePath      /var/cache/microsoft/powershell/PSModuleAnalysisCache/ModuleA…
PSModulePath                   /home/elf/.local/share/powershell/Modules:/usr/local/share/po…
riddle                         Squeezed and compressed I am hidden away. Expand me from my p…
SHELL                          /home/elf/elf
SHLVL                          1
TERM                           xterm
USER                           elf
USERDOMAIN                     laserterminal
USERNAME                       elf
username                       elf

PS /home/elf> gci ENV:riddle | %{$_.Value}
Squeezed and compressed I am hidden away. Expand me from my prison and I will show you the way. Recurse through all /etc and Sort on my LastWriteTime to reveal im the newest of all.

PS /home/elf> gci /etc -recurse | %{ $out=""; $out+=$_.LastWriteTime.tostring(“yyyy-MM-dd_HH:MM”); $out+=" "; $out+=$_.FullName; echo $out >> out3.txt }  

PS /home/elf> type out3.txt | sort                                                            
2009-02-02_23:02 /etc/dpkg/origins/debian                
[...omissis...]
2019-12-23_14:12 /etc/apt/archive
2019-12-23_14:12 /etc/hostname
2019-12-23_14:12 /etc/hosts
2019-12-23_14:12 /etc/mtab
2019-12-23_14:12 /etc/resolv.conf

PS /home/elf> Expand-Archive /etc/apt/archive

PS /home/elf/archive/refraction> dir


    Directory: /home/elf/archive/refraction

Mode                LastWriteTime         Length Name
----                -------------         ------ ----
------           11/7/19 11:57 AM            134 riddle
------           11/5/19  2:26 PM        5724384 runme.elf

PS /home/elf/archive/refraction> chmod +x ./runme.elf
PS /home/elf/archive/refraction> ./runme.elf
refraction?val=1.867

PS /home/elf/archive/refraction> type riddle
Very shallow am I in the depths of your elf home. You can find my entity by using my md5 identity:

25520151A320B5B0D21561F92C8F6224

PS /home/elf/depths> gci -Recurse | %{ Get-FileHash -Path $_.FullName -Algorithm MD5 | %{ if ($_.Hash -eq "25520151A320B5B0D21561F92C8F6224") { echo $_.Path } } }
/home/elf/depths/produce/thhy5hll.txt

PS /home/elf/depths> type /home/elf/depths/produce/thhy5hll.txt
temperature?val=-33.5

I am one of many thousand similar txt's contained within the deepest of /home/elf/depths. Finding me will give you the most strength but doing so will require Piping all the FullName's to Sort Length.

PS /home/elf/depths> gci -Recurse | sort { $_.FullName.length } | %{ $_.fullname} | select -last 1 
/home/elf/depths/larger/cloud/behavior/beauty/enemy/produce/age/chair/unknown/escape/vote/long/writer/behind/ahead/thin/occasionally/explore/tape/wherever/practical/therefore/cool/plate/ice/play/truth/potatoes/beauty/fourth/careful/dawn/adult/either/burn/end/accurate/rubbed/cake/main/she/threw/eager/trip/to/soon/think/fall/is/greatest/become/accident/labor/sail/dropped/fox/0jhj5xz6.txt

PS /home/elf/depths> type /home/elf/depths/larger/cloud/behavior/beauty/enemy/produce/age/chair/unknown/escape/vote/long/writer/behind/ahead/thin/occasionally/explore/tape/wherever/practical/therefore/cool/plate/ice/play/truth/potatoes/beauty/fourth/careful/dawn/adult/either/burn/end/accurate/rubbed/cake/main/she/threw/eager/trip/to/soon/think/fall/is/greatest/become/accident/labor/sail/dropped/fox/0jhj5xz6.txt
Get process information to include Username identification. Stop Process to show me you're skilled and in this order they must be killed:

bushy
alabaster
minty
holly

Do this for me and then you /shall/see .

PS /home/elf/depths> Get-Process -IncludeUserName

     WS(M)   CPU(s)      Id UserName                       ProcessName
     -----   ------      -- --------                       -----------
     26.96     1.90       6 root                           CheerLaserServi
    188.20   136.17      31 elf                            elf
      3.26     0.03       1 root                           init
      0.77     0.00      23 bushy                          sleep
      0.77     0.00      25 alabaster                      sleep
      0.72     0.00      28 minty                          sleep
      0.72     0.00      29 holly                          sleep
      3.45     0.00      30 root                           su

PS /home/elf/depths> Stop-Process -Id 23
PS /home/elf/depths> Stop-Process -Id 25
PS /home/elf/depths> Stop-Process -Id 28
PS /home/elf/depths> Stop-Process -Id 29

PS /home/elf/depths> type /shall/see
Get the .xml children of /etc - an event log to be found. Group all .Id's and the last thing will be in the Properties of the lonely unique event Id.

PS /home/elf> Get-Childitem /etc -recurse  -filter "*.xml"


    Directory: /etc/systemd/system/timers.target.wants

Mode                LastWriteTime         Length Name
----                -------------         ------ ----
--r---          11/18/19  7:53 PM       10006962 EventLog.xml

PS /home/elf> get-content /etc/systemd/system/timers.target.wants/EventLog.xml | Select-String -Pattern '<I32 N=\"Id\"'  | Group-Object

Count Name                      Group
----- ----                      -----
    1       <I32 N="Id">1</I32> {      <I32 N="Id">1</I32>}
   39       <I32 N="Id">2</I32> {      <I32 N="Id">2</I32>,       <I32 N="Id">2</I32>,      …
  179       <I32 N="Id">3</I32> {      <I32 N="Id">3</I32>,       <I32 N="Id">3</I32>,      …
    2       <I32 N="Id">4</I32> {      <I32 N="Id">4</I32>,       <I32 N="Id">4</I32>}
  905       <I32 N="Id">5</I32> {      <I32 N="Id">5</I32>,       <I32 N="Id">5</I32>,      …
   98       <I32 N="Id">6</I32> {      <I32 N="Id">6</I32>,       <I32 N="Id">6</I32>,      …

PS /home/elf> get-content /etc/systemd/system/timers.target.wants/EventLog.xml | Select-String -Pattern '<I32 N="Id">1</I32>' | %{ $_.LineNumber }
68753

PS /home/elf> get-content /etc/systemd/system/timers.target.wants/EventLog.xml | select -skip 68744 | select-string -Pattern "^  <\/Obj>" | %{ $_.LineNumber } | select -first 10
234
325
416
507
598
689
780
871
962
1053

PS /home/elf> get-content /etc/systemd/system/timers.target.wants/EventLog.xml | select -skip 68744 -first 234                                                                  
  <Obj RefId="1800">
    <TN RefId="1800">
      <T>System.Diagnostics.Eventing.Reader.EventLogRecord</T>
      <T>System.Diagnostics.Eventing.Reader.EventRecord</T>
      <T>System.Object</T>
    </TN>
    <ToString>System.Diagnostics.Eventing.Reader.EventLogRecord</ToString>
    <Props>
      <I32 N="Id">1</I32>
      [...omissis...]
      <Obj RefId="18016">
        <TNRef RefId="1806" />
        <ToString>System.Diagnostics.Eventing.Reader.EventProperty</ToString>
        <Props>
          <S N="Value">C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -c "`$correct_gases_postbody = @{`n    O=6`n    H=7`n    He=3`n    N=4`n    Ne=22`n    Ar=11`n    Xe=10`n    F=20`n    Kr=8`n    Rn=9`n}`n"</S>
        </Props>
      </Obj>
      [...omissis..]

PS /home/elf> (Invoke-WebRequest -Uri http://localhost:1225/).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:04:35 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 860

<html>
<body>
<pre>
----------------------------------------------------
Christmas Cheer Laser Project Web API
----------------------------------------------------
Turn the laser on/off:
GET http://localhost:1225/api/on
GET http://localhost:1225/api/off

Check the current Mega-Jollies of laser output
GET http://localhost:1225/api/output

Change the lense refraction value (1.0 - 2.0):
GET http://localhost:1225/api/refraction?val=1.0

Change laser temperature in degrees Celsius:
GET http://localhost:1225/api/temperature?val=-10

Change the mirror angle value (0 - 359):
GET http://localhost:1225/api/angle?val=45.1

Change gaseous elements mixture:
POST http://localhost:1225/api/gas
POST BODY EXAMPLE (gas mixture percentages):
O=5&H=5&He=5&N=5&Ne=20&Ar=10&Xe=10&F=20&Kr=10&Rn=10
----------------------------------------------------
</pre>
</body>
</html>

PS /home/elf/archive/refraction> (Invoke-WebRequest -Uri http://localhost:1225/api/temperature?val=-33.5).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:23:59 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 82

Updated Laser Temperature - Check /api/output if 5 Mega-Jollies per liter reached.
PS /home/elf/archive/refraction> (Invoke-WebRequest -Uri http://localhost:1225/api/refraction?val=1.867).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:24:01 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 87

Updated Lense Refraction Level - Check /api/output if 5 Mega-Jollies per liter reached.
PS /home/elf/archive/refraction> $postParams = @{O=6; H=7; He=3; N=4; Ne=22; Ar=11; Xe=10; F=20; Kr=8; Rn=9}
PS /home/elf/archive/refraction> (Invoke-WebRequest -Uri http://localhost:1225/api/gas -Method POST -Body $postParams).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:24:06 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 81

Updated Gas Measurements - Check /api/output if 5 Mega-Jollies per liter reached.

PS /home/elf/archive/refraction> (Invoke-WebRequest http://127.0.0.1:1225/api/angle?val=65.5).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:25:50 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 77

Updated Mirror Angle - Check /api/output if 5 Mega-Jollies per liter reached.

PS /home/elf/archive/refraction> (Invoke-WebRequest -Uri http://localhost:1225/api/on).RawContent    
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:27:38 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 32

Christmas Cheer Laser Powered On
PS /home/elf/archive/refraction> (Invoke-WebRequest -Uri http://localhost:1225/api/output).RawContent
HTTP/1.0 200 OK                                                                              
Server: Werkzeug/0.16.0                                                                      
Server: Python/3.6.9                                                                          
Date: Mon, 23 Dec 2019 17:27:43 GMT                                                          
Content-Type: text/html; charset=utf-8
Content-Length: 200

Success! - 5.34 Mega-Jollies of Laser Output Reached!
```
### 2.3.3. Afterwords
Speaking again with Sparkle Redberry:
	You got it - three cheers for cheer! For objective 5, have you taken a look at our Zeek logs? Something's gone wrong. But I hear someone named Rita can help us. Can you and she figure out what happened?