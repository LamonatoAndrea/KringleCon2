# 1. Primary Objectives
## 1.11. Open the Sleigh Shop Door
### 1.11.1. Description
Visit Shinny Upatree in the Student Union and help solve their problem. What is written on the paper you retrieve for Shinny? For hints on achieving this objective, please visit the Student Union and talk with Kent Tinseltooth.
### 1.11.2. Solution
Here I had to speak with Kent Tinseltooth to get the hint:
	Oh thank you! It's so nice to be back in my own head again. Er, alone.
	By the way, have you tried to get into the crate in the Student Union? It has an interesting set of locks.
	There are funny rhymes, references to perspective, and odd mentions of eggs! 
	And if you think the stuff in your browser looks strange, you should see the page source...
	Special tools? No, I don't think you'll need any extra tooling for those locks.
	BUT - I'm pretty sure you'll need to use Chrome's developer tools for that one.
	Or sorry, you're a Firefox fan?
	Yeah, Safari's fine too - I just have an ineffible hunger for a physical Esc key.
	Edge? That's cool. Hm? No no, I was thinking of an unrelated thing.
	Curl fan? Right on! Just remember: the Windows one doesn't like double quotes.
	Old school, huh? Oh sure - I've got what you need right here...

Basically, it was pointing out something to be searched in the source code of the page, so with the developer console I searched for “crate” and found the below HTML code:
```html
<a href="​ http://sleighworkshopdoor.elfu.org​ ">
	<div class="crate">
		<div class="side"></div>
		<div class="front"></div>
		<div class="top"></div>
	</div>
</a>
```
Clicking on the link takes to another webpage asking to crack all the locks, once they are all open the flag is shown.
#### 1.11.2.1. Lock 1
The lock states “You don't need a clever riddle to open the console and scroll a little.”, so just opening the Developer Tools console and scrolling shown the code **​ A1JW3R3C ​** to open the lock.
#### 1.11.2.2. Lock 2
The lock states “Some codes are hard to spy, perhaps they'll show up on pulp with dye?”. Dye made me think about ink and therefore I tried to print the web page, uncovering code ​**YNAMHIY9​** to open the lock.
#### 1.11.2.3. Lock 3
The lock states “This code is still unknown; it was fetched but never shown.”. The fact it was fetched made me think something was retrieved via network and I confirmed it finding https://sleighworkshopdoor.elfu.org/images/2ae0072d-b73d-4f20-a049-fd89f1f43855.png​ was being downloaded multiple times. The image contains the code **​ LA19Y6DG​** to open the lock.
#### 1.11.2.4. Lock 4
The lock states “Where might we keep the things we forage? Yes, of course: Local barrels!”. Here the hint was “local barrels” so looking at the Local Storage I could see a key value pair as follows: `(‘🛢 🛢 🛢’, ‘N1ZTG1O1’)`. The code in the local storage ​**N1ZTG1O1​** that opens the lock.
#### 1.11.2.5. Lock 5
The lock states “Did you notice the code in the title? It may very well prove vital.”. Looking at the title tag there was a lot of spaces and then the code:
```html
<title>Crack the Crate                                                  O8KFNFK6</title>
```
The code ​ **O8KFNFK6​** opens the lock.
#### 1.11.2.6. Lock 6
The lock states “In order for this hologram to be effective, it may be necessary to increase your
perspective.”. As perspective is a visual thing, I went looking at the CSS of the image next to the lock and noticed the hologram class has a perspective property:
```css
.hologram {
	perspective: 15px;
	width: 150px;
	height: 100px;
	border-radius: 20px;
	transition: perspective 5s;
}
```
Random fuzzying on the perspective property I increased it to 1000000px and the code became clear in the web page. The code ​**418USNG8​** opens the lock.
#### 1.11.2.7. Lock 7
The lock states “The font you're seeing is pretty slick, but this lock's code was my first pick.”. Following the font hint, I went looking at the CSS of the text, noticing that the instructions class had a weird font family:
```css
.instructions {
	font-family: ​ 'D6W0YH5Z'​ , 'Beth Ellen', cursive;
}
```
The code ​ **D6W0YH5Z​** opens the lock.
#### 1.11.2.8. Lock 8
The lock states “In the event that the .eggs go bad, you must figure out who will be sad.”. Searching for the eggs class, I identified the below piece of HTML code:
```html
<span class="eggs">.eggs</span>
```
Digging further on related Event Listeners I could see that the VERONICA window was triggered:
```
▼ spoil
	▼ span.eggs
		► handler: ()=>window[‘VERONICA’]=’sad’
		  once: false
		  passive: false
		  useCapture: false
```
The code ​**VERONICA​** opens the lock.
#### 1.11.2.9. Lock 9
The lock states “This next code will be unredacted, but only when all the chakras are :active.”. Looking at the source code of this sentence, I noticed the presence of some span named “chakra” and I forced their state to active uncovering the code over them.
The code ​ **O90SJFZ8** ​ opens the lock.
#### 1.11.2.10. Lock 10
The lock states “Oh, no! This lock's out of commission! Pop off the cover and locate what's missing.”.
Following the “pop off the cover” hint I noticed a div of class cover and deleted it with Developer Tools:
```html
<div class="cover">
	<button data-id="10" disabled="disabled">Unlock</button>
</div>
```

I tried inserting the code printed on the PCB without success, having a better look at it I noticed like if a gnome was missing, so I searched “gnome” in the HTML code with Developer Tools, noticing that a div with component and gnome classes assigned. Searching for other elements with class component I found two divs: swab and macaroni.

I tried copy-paste them inside the lock without success until I removed already existing ones, below the source code obtained for this lock after moving components into it:
```html
<li>
	<div class="lock c10 unlocked">
		<div class="component macaroni" data-code="A33"></div>
		<div class="component gnome" data-code="XJ0"></div>
		<div class="component swab" data-code="J39"></div>
		<input type="text" maxlength="8" data-id="10" disabled="">
		<button class="switch" data-id="10" disabled=""></button>
		<span class="led-indicator locked"></span>
		<span class="led-indicator unlocked"></span>
	</div>
</li>
```
Clicking the button with the code on PCB written into the lock unlocked it as per picture below:
![pcb image](https://github.com/LamonatoAndrea/KringleCon2/blob/master/01%20-%20Primary%20Objectives/11%20-%20Open%20the%20Sleigh%20Shop%20Door/pcb_image.png)
P.S.: This lock was done in another moment with respect to previous ones.
### 1.11.3. Flag
The flag is: ​**The Tooth Fairy​**.