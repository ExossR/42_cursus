# Level00

Once i am connected to the virtual machine, the first reflex is to check the files in the home directory. I can do this with the command `ls`.
Nothing much appears except some .bashrc etc..

Then i can start looking for files in the root directory. I can do this with the command `ls /`.
You can see that you have access to it. Then i can start looking for some files including flag00.
Using `find -name flag00 2>/dev/null`, you dont get anything at all.

Then you can use `find -user flag00 2>/dev/null` to display all the files owned by user flag00.
You will see 2 files, that are in reality the same file.
`> ./usr/sbin/john`
`> ./rofs/usr/sbin/john`

When you `cat` any of them, you get the string `cdiiddwpgswtgt`.
If you try it it doesn't work, maybe it's encrypted.
It uses only characters from the alphabet so i thought it would be a caesar cipher.
Using [https://www.dcode.fr/caesar-cipher](https://www.dcode.fr/caesar-cipher) to decrypt it, you get all the possible strings with it, and the one we are looking for (the first one), is `nottoohardhere`.
