# LEVEL05

Again, `ls -la` gives no special output.
Howver, `find -user flag05` gives out 2 files, one binary, which is `/usr/sbin/openarenaserver`

You can't execute it, but you can read it. It says that it executes all the files in the the folder /opt/openarenaserver
Then, we can try to create a script that calls the getflag command `echo 'getflag' > /opt/openarenaserver/flag.sh'

After waiting a bit, the script just disappear without doing anything... Hence it must have called it, and cleared the directory, like a cron task.

If we instead do `echo 'getflag > /tmp/flag05' > /opt/openarenaserver/flag.sh`
Then, if you wait a bit, a flag05 file will appear and the flag will be inside of it.
