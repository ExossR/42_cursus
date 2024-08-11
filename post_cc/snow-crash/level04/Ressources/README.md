# LEVEL04

We can see there is a level04.pl file with +x permission
When executing, it displays `content-type: text/html`
When displaying the content of the file, it shows that it is accessible on localhost:4747
Also, you can understand on the script that it runs the command

If you try to access to localhost:4747 with parameter x = [your command], it will run in the terminal, the command.
Hence, `curl 'localhost:4747?x=$(getflag)'` will give the flag !
