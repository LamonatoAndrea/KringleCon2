# 2. Secondary Objectives
## 2.9. Mongo Pilfer
### 2.9.1. Description
Speaking with Holly Evergreen:
>Hey! It's me, Holly Evergreen! My teacher has been locked out of the quiz database and can't remember the right solution. Without access to the answer, none of our quizzes will get graded. Can we help get back in to find that solution? I tried lsof -i, but that tool doesn't seem to be installed. I think there's a tool like ps that'll help too. What are the flags I need? Either way, you'll need to know a teensy bit of Mongo once you're in. Pretty please find us the solution to the quiz!

Mongo Pilfer motd:
```
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
```
### 2.9.2. Solution
```bash
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
```
### 2.9.3. Afterwords
Speaking again with Holly Evergreen:
>Woohoo! Fantabulous! I'll be the coolest elf in class. On a completely unrelated note, digital rights management can bring a hacking elf down. That ElfScrow one can really be a hassle. It's a good thing Ron Bowes is giving a talk on reverse engineering! That guy knows how to rip a thing apart. It's like he breathes opcodes!