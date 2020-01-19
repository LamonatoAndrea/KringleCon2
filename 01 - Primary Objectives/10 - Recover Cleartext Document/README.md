# 1. Primary Objectives
## 1.10. Recover Cleartext Document
### 1.10.1. Description
The Elfscrow Crypto tool is a vital asset used at Elf University for encrypting SUPER SECRET documents. We can't send you the source, but we do have debug symbols that you can use. Recover the plaintext content for this encrypted document. We know that it was encrypted on December 6, 2019, between 7pm and 9pm UTC. What is the middle line on the cover page? (Hint: it's five words) For hints on achieving this objective, please visit the NetWars room and talk with Holly Evergreen.
### 1.10.2. Solution
After running the code on Windows machine I could see that the output was:
* Printing a message, suggesting to not use the --insecure flag as it would be potentially traced with Wireshark or similar tools
* Printing the a timestamp as seed
* Printing the key

I went straight to run the code to encrypt a random text file using the --insecure flag and seeing that the program was sending out the key and receiving a UUID and that during decryption it was sending out the UUID and receiving the key.

As per the description it looked like the timestamp was important I decided to analyze better ”Seed” output.

Once EXE and PDB files were imported with Ghidra, three functions appeared more interesting than the others:
* _super_secure_srand__YAXH_Z
* super_secure_random
* _generate_key__YAXQAE_Z

In detail, the key is created by super_secure_random starting from the current epoch cycling 8 times on some operations.

Considering the file was encrypted on December 6, 2019 between 7pm and 9pm, it means that in epoch there are 7200 keys and I wrote a little C program to produce all the possible keys.
Once I had all possible keys, I wrote two more python scripts, one as a little web service returning the POST body as response and the other for iterating elfscrow --decrypt execution over all keys.

After all the potential decryption were executed I found that the key b5ad6a321240fbec outputted a PDF file inside which I found the flag for the challenge.
### 1.10.3. Flag
The flag is: **Machine Learning Sleigh Route Finder​**.
### 1.10.4. Attachments
#### 1.10.4.1. GenerateKeys.c
```c
#include <time.h>
#include <stdio.h>
#include <uchar.h>
int main(int argc, char** argv) {
    time_t seed = 1575658800;
    time_t temp_seed;
    int i;

    while (seed < 1575666000) {
        time_t this_seed = seed;
        i = 0;
        while (i < 8) {
            this_seed = this_seed * 0x343fd + 0x269ec3;
            temp_seed = this_seed >> 0x10 & 0x7fff;
            printf("%x", (unsigned char)temp_seed);
            i++;
        }
        printf("\n");
        seed++;
    }

    return 0;
}
```
#### 1.10.4.2. webService.py
```python
import http.server
import socketserver

ROUTES = [('/api/retrieve')]

class Handler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        body = self.rfile.read(int(self.headers['Content-Length']))
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(body)
        return

print('Server listening on port 80...')
httpd = socketserver.TCPServer(('', 80), Handler)
httpd.serve_forever()
```
#### 1.10.4.3. decryptAll.py
```python
import os
import subprocess

i = 0
for line in open("C:\\Users\\Andrea\\Desktop\\Kringlecon 2019\\keys.txt", "r").readlines():
    line = line.replace("\n", "").replace("\r", "")
    print ("Line [{}] [{}]".format(i, line))
    subprocess.call ("elfscrow.exe --insecure --decrypt --id={0} ElfUResearchLabsSuperSledOMaticQuickStartGuideV1.2.pdf.enc decrypted\\{0}.pdf >> dec_log.txt 2>&1 ".format(line), shell=True)
    i += 1
```
#### 1.10.4.4. Run of file command on decrypted files
```bash
$ file *    
109b75283baebf4.pdf:  data
12febee4703f2b49.pdf: data
18abe427a8a9e45.pdf:  data
1d405684dba68321.pdf: data
1e387de7294fcc74.pdf: data
281c677ff935b4b.pdf:  data
3029e66fc4b57be.pdf:  data
5afd2b9117aa2a6.pdf:  data
65c80dec675e67.pdf:   data
6734f7607fc2642.pdf:  data
68e96526b546cacb.pdf: data
7425175da91da785.pdf: data
83ca93836a7c5e.pdf:   data
95bc3e8440937ad3.pdf: data
9a80dcca6def16cf.pdf: data
9b1b55262118f0e2.pdf: data
9fb3909cbdfb114d.pdf: data
a675f0fbd311f4a1.pdf: data
aa6dccac453dc2db.pdf: data
b5ad6a321240fbec.pdf: PDF document, version 1.3
b75fecaa6f98631e.pdf: data
c1524b8db138be9.pdf:  data
c54f138dfc8fe79a.pdf: data
c93587bec0384f2.pdf:  data
d0ae95ca24186577.pdf: data
ddcb1f7c43886383.pdf: data
e39c39fa1fe8946a.pdf: data
e88c3bfdfbcabf7.pdf:  data
ef242ad29e22504a.pdf: data
f0ae9b63f49eaba.pdf:  data
f2f1a2b47ed4a2f3.pdf: data
f91889b6e0c2ab34.pdf: data
fae060fcc3c71ea0.pdf: data
faed6c286938dad.pdf:  data
```