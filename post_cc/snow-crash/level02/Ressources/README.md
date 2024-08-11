# LEVEL 02

When logging in, you can notice a level02.pcap file. This file is a network capture file, which means it contains all the packets that were sent and received by the machine. You can open this file with Wireshark, a network protocol analyzer.
Using `scp -P 22222 level02@localhost:~/level02.pcap .` you can download the file to your machine and open it with Wireshark.

Now that you have the file, you can open is using Wireshark, and if you browse the packets, at some point you will notice "Password: " in the data of a packet.
If you look at the next packets, you see each character on the data part of the packets.

You then get:
`ft_wandr...NDRel.L0L.`

If you try this password, it won't work.
Then you must understand what the dots are.
The ascii code is 7F, which is the delete character.
Hence you must delete the characters before the dots.

You get:
`ft_waNDReL0L`

And it works !
