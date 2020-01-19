# 1. Primary Objectives
## 1.6. Splunk
### 1.6.1. Description
Access https://splunk.elfu.org/ as elf with password elfsocks. What was the message for Kent that the adversary embedded in this attack? The SOC folks at that link will help you along! For hints on achieving this objective, please visit the Laboratory in Hermey Hall and talk with Prof. Banas.
### 1.6.2. Solution
Searching for banas as free text search in Splunk prompts lot of logs containing email details, by further digging on them I extracted the receiver, sender, subject, body and attachment file dir for eventual download with the below query:
```splunk
results{}.workers.smtp.to=*banas* | table results{}.workers.smtp.to,
results{}.workers.smtp.from, results{}.workers.smtp.subject,
results{}.workers.smtp.body, results{}.archivers.filedir.path
```
An email from bradly buttercups <​ bradly.buttercups@eifu.org​ > caught my attention because of the body that pointed out to a zip password and requires to enable content:
```
professor banas, i have completed my assignment. please open the attached zip file with
password 123456789 and then open the word document to view it. you will have to click
"enable editing" then "enable content" to see it. this was a fun assignment. i hope you
like it! --bradly buttercups
```
At this point I downloaded all the attachment files with below curl command:
``` bash
curl 'https://elfu-soc.s3.amazonaws.com/stoQ%20Artifacts$PATH$NAME’ -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36' -H 'Sec-Fetch-User: ?1' --compressed > $NAME
```
Going through files it is possible to find the message to Kent in file ff1ea6f13be3faabd0da728f514deb7fe3577cc4.
### 1.6.3. Flag
The flag is: ​**Kent you are so unfair. And we were going to make you the king of the Winter Carnival.​**.
### 1.6.4. Attachments
#### 1.6.4.1. List of attachment files
```
/home/ubuntu/archive/7/f/6/3/a/7f63ace9873ce7326199e464adfdaad76a4c4e16
/home/ubuntu/archive/9/b/b/3/d/9bb3d1b233ee039315fd36527e0b565e7d4b778f
/home/ubuntu/archive/c/6/e/1/7/c6e175f5b8048c771b3a3fac5f3295d2032524af
/home/ubuntu/archive/b/e/7/b/9/be7b9b92a7acd38d39e86f56e89ef189f9d8ac2d
/home/ubuntu/archive/1/e/a/4/4/1ea44e753bd217e0edae781e8b5b5c39577c582f
/home/ubuntu/archive/e/e/b/4/0/eeb40799bae524d10d8df2d65e5174980c7a9a91
/home/ubuntu/archive/1/8/f/3/3/18f3376a0ce18b348c6d0a4ba9ec35cde2cab300
/home/ubuntu/archive/f/2/a/8/0/f2a801de2e254e15840460f4a53e568f6622c48b
/home/ubuntu/archive/1/0/7/4/0/1074061aa9d9649d294494bb0ae40217b9c7a2d9
/home/ubuntu/archive/8/6/c/4/d/86c4d8a2f37c6b4709273561700640a6566491b1
/home/ubuntu/archive/a/2/b/b/1/a2bb14afe8161ee9bd4a6ea10ef5a9281e42cd09
/home/ubuntu/archive/4/0/d/c/1/40dc1e00e2663cb33f8c296cdb0cd52fa07a87b6
/home/ubuntu/archive/f/5/c/b/a/f5cba8a650d6ada98d170f1b22098d93b8ff8879
/home/ubuntu/archive/0/2/b/6/7/02b67cad55d2684115a7de04d0458a3af46b12c6
/home/ubuntu/archive/1/7/6/1/2/1761214092f5c0e375ab3bc58a8687134b7f2582
/home/ubuntu/archive/b/7/7/0/f/b770f3a79423882bdae4240e995c0885770022ef
/home/ubuntu/archive/9/d/7/a/b/9d7abf0ee4effcecad80c8bbfb276079a05b4342
/home/ubuntu/archive/e/9/2/1/1/e9211c706be234c20d3c02123d85fea50ae638fd
/home/ubuntu/archive/f/f/1/e/a/ff1ea6f13be3faabd0da728f514deb7fe3577cc4
/home/ubuntu/archive/7/f/6/3/a/7f63ace9873ce7326199e464adfdaad76a4c4e16
/home/ubuntu/archive/9/b/b/3/d/9bb3d1b233ee039315fd36527e0b565e7d4b778f
/home/ubuntu/archive/c/6/e/1/7/c6e175f5b8048c771b3a3fac5f3295d2032524af
```