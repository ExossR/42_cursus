# LEVEL09

When arriving, again you get a binary and a token file. The binary expects an argument. When trying with token, you get tpmhr.
if you pass the content of the file, you won't get much interesting either

after some various tries, you will notice:
```sh
level09@SnowCrash:~$ ./level09 a
a
level09@SnowCrash:~$ ./level09 ab
ac
level09@SnowCrash:~$ ./level09 abc
ace
level09@SnowCrash:~$ ./level09 abcd
aceg
level09@SnowCrash:~$ ./level09 abcde
acegi
level09@SnowCrash:~$ ./level09 abcde
acegi
level09@SnowCrash:~$ ./level09 abcdef
acegik
level09@SnowCrash:~$ ./level09 abcdefg
acegikm
level09@SnowCrash:~$ ./level09 abcdefgh
acegikmo
```

On the string, the actual output character is the input char + index of the char
We can do a little script to decode the content of token file (decode.py)

we have to use %256 to make sure the results bytes are chars normal chars

we get f3iji1ju5yuevaus41q1afiuqñ.

You should not take account of n, since it's the \n decoded char which we dont use.
Then we can log as flag09 !
