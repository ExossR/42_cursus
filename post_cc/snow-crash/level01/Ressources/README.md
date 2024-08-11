# LEVEL 01

When logging in, you wont find much information in the home directory. However, after some exploration, if you cat the /etc/passwd file, you will notice that there is only one username whose password is displayed. The username is flag01 and the password is 42hDRfypTqqnw.

So what to do with the password ?

If you look for tools to crack password on the internet, you will find a lot of them. I tried the first one i found, which is hashcat.

I download the sources file, built it, and used it with the dictionnary already present. What it will do is compare the hash of the password with the hash of the dictionnary. If it finds a match, it will display the password. You might try to test few encodings, the default one used by hashcat is traditional DES. It will find the password in few milliseconds.
`hashcat 42hDRfypTqqnw example.dict`

The password found it abcdefg !
