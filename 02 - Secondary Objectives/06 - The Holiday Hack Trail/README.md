# 2. Secondary Objectives
## 2.6. The Holiday Hack Trail
### 2.6.1. Description
I don’t know what happened here but I think part of the conversation with Minty Candycane is missing, speaking with her:
> One is about web application penetration testing. Good luck, and don't get dysentery!

The Holiday Hack Trail Initial page:
![The Holiday Hack Trail Initial page]()

Store page:
![The Holiday Hack Trail Store page]()
	
### 2.6.2. Solution
#### 2.6.2.1. Easy
The parameters are passed via the URL with GET requests, it is possible to alter the distance parameter to 8000 to reach the end. The altered URL will look similar to:
hhc://trail.hhc/trail/?difficulty=0&**distance=8000**&money=5000&pace=0&curmonth=7&curday=1&reindeer=2&runners=2&ammo=100&meds=20&food=400&name0=John&health0=100&cond0=0&causeofdeath0=&deathday0=0&deathmonth0=0&name1=Sally&health1=100&cond1=0&causeofdeath1=&deathday1=0&deathmonth1=0&name2=Anna&health2=100&cond2=0&causeofdeath2=&deathday2=0&deathmonth2=0&name3=Kendra&health3=100&cond3=0&causeofdeath3=&deathday3=0&deathmonth3=0

At this point the interface will show that the distance remaining is 0 as per picture below:
![easy last step]()

Pressing the “GO” button again will take to the winning page:
![easy winning page]()

#### 2.6.2.2. Medium
Here the parameters are sent via POST request, but are injectable in the same manner as the Easy difficulty level. Below the output obtained by sending the altered request with curl:
curl 'https://trail.elfu.org/trail/' -H 'Connection: keep-alive' -H 'Cache-Control: max-age=0' -H 'Origin: https://trail.elfu.org' -H 'Upgrade-Insecure-Requests: 1' -H 'Content-Type: application/x-www-form-urlencoded' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36' -H 'Sec-Fetch-User: ?1' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9' -H 'Sec-Fetch-Site: same-origin' -H 'Sec-Fetch-Mode: nested-navigate' -H 'Referer: https://trail.elfu.org/trail/' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.9,it-IT;q=0.8,it;q=0.7' -H 'Cookie: trail-mix-cookie=7f7127a10e92b3a5e77ad1db87cf9ba532463bd4' --data 'pace=2&playerid=JebediahSpringfield&action=go&difficulty=1&money=3000&**distance=8000**&curmonth=8&curday=2&name0=Chris&health0=100&cond0=0&cause0=&deathday0=0&deathmonth0=0&name1=Emmanuel&health1=100&cond1=0&cause1=&deathday1=0&deathmonth1=0&name2=Chloe&health2=100&cond2=0&cause2=&deathday2=0&deathmonth2=0&name3=Jen&health3=100&cond3=0&cause3=&deathday3=0&deathmonth3=0&reindeer=2&runners=2&ammo=50&meds=10&food=184&hash=HASH' --compressed

This resource can be found at <a href='https://trail.elfu.org/fin/?reason=victory&amp;name0=Chris&amp;death0=notdeadyet&amp;name1=Emmanuel&amp;death1=notdeadyet&amp;name2=Chloe&amp;death2=notdeadyet&amp;name3=Jen&amp;death3=notdeadyet&amp;curday=3&amp;curmonth=8&amp;money=3000&amp;reindeer=2&amp;alivecount=4&amp;difficulty=1&amp;hash=91ac54832b5d59c195e196a3ae959e6b&amp;victorytoken={ hash:"f3e41a22416c2397460403fa82d40307f4379da95d41d5e366b55a1e775c5d41", resourceId: "JebediahSpringfield"}'>https://trail.elfu.org/fin/?reason=victory&amp;name0=Chris&amp;death0=notdeadyet&amp;name1=Emmanuel&amp;death1=notdeadyet&amp;name2=Chloe&amp;death2=notdeadyet&amp;name3=Jen&amp;death3=notdeadyet&amp;curday=3&amp;curmonth=8&amp;money=3000&amp;reindeer=2&amp;alivecount=4&amp;difficulty=1&amp;hash=91ac54832b5d59c195e196a3ae959e6b&amp;victorytoken={ hash:"f3e41a22416c2397460403fa82d40307f4379da95d41d5e366b55a1e775c5d41", resourceId: "JebediahSpringfield"}</a>.

Visiting the URL mentioned in the response, below web page is shown:
![medium winning page]()

#### 2.6.2.3. Hard
At hard level parameters are sent via POST requests and each contains an undocumented hash value. Considering that in the Easy level a verification hash was calculated from the number of points, I thought that this hash may have been a numeric value representing the current points acquired. The decrypt tool from md5online.org confirmed that this value is numeric but it was much lower than what I expected.

I noticed that the first “GO” request had always the hash of 1626, I thought that this value was a checksum made up of values in page and I tried to figure out which of these were involved. Checking the difference with a second “GO” request it was possible to identify the below list of parameters involved in the hash creation:
 * money
 * distance
 * curmonth
 * curday
 * reindeer
 * runners
 * ammo
 * meds
 * food

Below the output obtained by submitting a tampered “GO” request with a valid hash via curl:
curl 'https://trail.elfu.org/trail/' -H 'Connection: keep-alive' -H 'Cache-Control: max-age=0' -H 'Origin: https://trail.elfu.org' -H 'Upgrade-Insecure-Requests: 1' -H 'Content-Type: application/x-www-form-urlencoded' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36' -H 'Sec-Fetch-User: ?1' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9' -H 'Sec-Fetch-Site: same-origin' -H 'Sec-Fetch-Mode: nested-navigate' -H 'Referer: https://trail.elfu.org/trail/' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.9,it-IT;q=0.8,it;q=0.7' -H 'Cookie: trail-mix-cookie=e543662c928fc61549bbfe167729d528f7a270ea' --data 'pace=0&playerid=02554611-d73c-4881-baa7-9549350ec50b&action=go&difficulty=2&money=1500&**distance=8000**&curmonth=9&curday=1&name0=Sam&health0=100&cond0=0&cause0=&deathday0=0&deathmonth0=0&name1=Sally&health1=100&cond1=0&cause1=&deathday1=0&deathmonth1=0&name2=Joseph&health2=100&cond2=0&cause2=&deathday2=0&deathmonth2=0&name3=Evie&health3=100&cond3=0&cause3=&deathday3=0&deathmonth3=0&reindeer=2&runners=2&ammo=10&meds=2&food=100&**hash=649d45bf179296e31731adfd4df25588**' --compressed

This resource can be found at <a href='https://trail.elfu.org/fin/?reason=victory&amp;name0=Sam&amp;death0=notdeadyet&amp;name1=Sally&amp;death1=notdeadyet&amp;name2=Joseph&amp;death2=notdeadyet&amp;name3=Evie&amp;death3=notdeadyet&amp;curday=2&amp;curmonth=9&amp;money=1500&amp;reindeer=2&amp;alivecount=4&amp;difficulty=2&amp;hash=57ec46350ce6dbd9881127dd6d102cfb&amp;victorytoken={ hash:"4f112f9623bbac3e927d0c92be2fece33473bce3ed35383ae979c214d39fe43e", resourceId: "02554611-d73c-4881-baa7-9549350ec50b"}'>https://trail.elfu.org/fin/?reason=victory&amp;name0=Sam&amp;death0=notdeadyet&amp;name1=Sally&amp;death1=notdeadyet&amp;name2=Joseph&amp;death2=notdeadyet&amp;name3=Evie&amp;death3=notdeadyet&amp;curday=2&amp;curmonth=9&amp;money=1500&amp;reindeer=2&amp;alivecount=4&amp;difficulty=2&amp;hash=57ec46350ce6dbd9881127dd6d102cfb&amp;victorytoken={ hash:"4f112f9623bbac3e927d0c92be2fece33473bce3ed35383ae979c214d39fe43e", resourceId: "02554611-d73c-4881-baa7-9549350ec50b"}</a>.

Visiting the URL mentioned in the response, below web page is shown:
![hard winning page]()

### 2.6.3. Afterwords
Speaking again with Minty Candycane:
>You made it - congrats! Have you played with the key grinder in my room? Check it out! It turns out: if you have a good image of a key, you can physically copy it. Maybe you'll see someone hopping around with a key here on campus. Sometimes you can find it in the Network tab of the browser console. Deviant has a great talk on it at this year's Con. He even has a collection of key bitting templates for common vendors like Kwikset, Schlage, and Yale.