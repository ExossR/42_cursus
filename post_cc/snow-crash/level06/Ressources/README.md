# LEVEL06

The script `level06.php` performs the following operations:

1. It defines two functions, `y()` and `x()`.
2. `x()` reads from a file whose path is supplied via command line arguments, then processes its content through several `preg_replace()` calls.
3. The critical vulnerability is in this line:
   ```php
   preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
   ```
    The e modifier causes PHP to evaluate the replacement string as PHP code after processing it with the y() function.
4. The y() function replaces . with " x " and @ with " y", but these transformations are circumvented in the exploit since they would disrupt the execution.


The payload is crafted to leverage the e modifier's behavior by injecting PHP code that the server executes. The steps to exploit this vulnerability are as follows:

Create a text file with the payload:
```sh
echo '[x {${exec(getflag)}}]' > /tmp/test.txt
```
- `[x ...]` matches the pattern required by the preg_replace() to trigger the code evaluation.
- `{${exec(getflag)}}` injects PHP code to execute the getflag command.

Execute the script with the crafted file as input:
```sh
./level06 /tmp/test.txt
```

and you get the flag
