# Checking the heap memory in linux systems

The hello_wait.c code offers two options for you to start an execution and halt the code, so to check the computer memory.

Pick one and then, on a terminal, execute the following commands:

```shell
ps aux | grep hello_wait.out
```

This will bring the lines related to the `hello_wait.out` process. In the second column of this return, we'll have the `PID`, pick the one that relates to the `./hello_wait.out` execution.

example:

```shell
felipe    754919  0.0  0.0   2776  1408 ?        tNs  16:03   0:00 ./hello_wait.out
felipe    755224  0.0  0.0  19020  2432 pts/6    SN+  16:03   0:00 grep --color=auto --exclude-dir=.bzr --exclude-dir=CVS --exclude-dir=.git --exclude-dir=.hg --exclude-dir=.svn --exclude-dir=.idea --exclude-dir=.tox hello_wait.out
```

In the provided example, it will be `754919`. With this data we can look within the corresponding `/proc/[pid]` folder where we will have the components of the linux (virtual memory)[https://www.baeldung.com/cs/physical-vs-virtual-memory] data - for more technical and accurate info look in the linux (man page for proc)[https://man7.org/linux/man-pages/man5/proc.5.html]. First we will look withing the  `/proc/[pid]/maps` file, where we have the memory addresses used by the process:

```shell
cat /proc/754919/maps
```

This will bring a result like the following:

```shell
555555554000-555555555000 r--p 00000000 08:01 48637675                   /home/my_user/hello_wait.out
555555555000-555555556000 r-xp 00001000 08:01 48637675                   /home/my_user/hello_wait.out
555555556000-555555557000 r--p 00002000 08:01 48637675                   /home/my_user/hello_wait.out
555555557000-555555558000 r--p 00002000 08:01 48637675                   /home/my_user/hello_wait.out
555555558000-555555559000 rw-p 00003000 08:01 48637675                   /home/my_user/hello_wait.out
555555559000-55555557a000 rw-p 00000000 00:00 0                          [heap]
7ffff7c00000-7ffff7c28000 r--p 00000000 103:02 14157122                  /usr/lib/x86_64-linux-gnu/libc.so.6
7ffff7c28000-7ffff7dbd000 r-xp 00028000 103:02 14157122                  /usr/lib/x86_64-linux-gnu/libc.so.6
7ffff7dbd000-7ffff7e15000 r--p 001bd000 103:02 14157122                  /usr/lib/x86_64-linux-gnu/libc.so.6
7ffff7e15000-7ffff7e19000 r--p 00214000 103:02 14157122                  /usr/lib/x86_64-linux-gnu/libc.so.6
7ffff7e19000-7ffff7e1b000 rw-p 00218000 103:02 14157122                  /usr/lib/x86_64-linux-gnu/libc.so.6
7ffff7e1b000-7ffff7e28000 rw-p 00000000 00:00 0 
7ffff7fa2000-7ffff7fa5000 rw-p 00000000 00:00 0 
7ffff7fbb000-7ffff7fbd000 rw-p 00000000 00:00 0 
7ffff7fbd000-7ffff7fc1000 r--p 00000000 00:00 0                          [vvar]
7ffff7fc1000-7ffff7fc3000 r-xp 00000000 00:00 0                          [vdso]
7ffff7fc3000-7ffff7fc5000 r--p 00000000 103:02 14157118                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffff7fc5000-7ffff7fef000 r-xp 00002000 103:02 14157118                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffff7fef000-7ffff7ffa000 r--p 0002c000 103:02 14157118                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffff7ffb000-7ffff7ffd000 r--p 00037000 103:02 14157118                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffff7ffd000-7ffff7fff000 rw-p 00039000 103:02 14157118                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffffffdd000-7ffffffff000 rw-p 00000000 00:00 0                          [stack]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]
```

This file provides us with the start and ending address used in the memory for the process. In our case, we wan't to find the data placed in the heap, so we will get the starting address related to it `555555559000`.

With this address we can look into this process mem file `/proc/[pid]/mem`. Through the mem file we have access to the process memory pages (a page points to a memory map that points to an actual address either in the physical memory or to a disk storage).

To do so we'll use the `dd` (data duplicator) utility, it is an linux application used for coping and converting data in low level contexts. For this, we'll need to convert the address we retrieved into a decimal value, which we'll pass as a parameter to the dd utility:

```shell
echo $((16#555555559000))
```

The previous command passes uses an an arithmetic expansion (the `$((calculation))`) - an operation that allows us to get calculated values, on shell, without having to declare then in a variable first - to get the decimal value of the base 16 number we have (the `original_base#value`).

We'll have a the following return:

```shell
93824992251904
```

with this we can compose our dd call:

```shell
sudo dd bs=1 skip="93824992251904" count=1024 if="/proc/754919/mem" status=none | hexdump -C
```

let's break down the command:

- `dd`: The command itself, which invokes the dd utility;
- `bs=1`: This option sets the block size to 1 byte. In this case, it means that dd will read and write data in chunks of 1 byte at a time;
- `skip="93824992251904"`: This option specifies the number of blocks to skip before starting the copying process. In this case, it skips 93,824,992,251,904 blocks. Since the block size is set to 1 byte, this effectively means it skips 93,824,992,251,904 bytes (or 93.8 TB) of data.
- `count=1024`: This option determines the number of blocks to be copied. Here, it is set to 1024 blocks, meaning 1024 bytes will be copied. this value can be adjusted to the desired size we want to dump, for instance, if we wan´t all the data on the heap for this process, we could set it to **135168** which is the decimal difference between the initial and the final addresses used for the process heap (seen in the `maps` file earlier);
- `if="/proc/754919/mem"`: This option sets the input file from which dd will read the data. In this case, it is set to **"/proc/754919/mem"**, indicating that dd will read from the memory of the process with the PID 754919;
- `status=none`: This option suppresses the output of the status information, so you won't see any progress or statistics about the copying process;
- `hexdump -C`: hexdump is a command-line utility that displays the contents of a file or input data in hexadecimal format. The `-C` option is used to format the output in a more readable way, displaying both the hexadecimal values and their corresponding ASCII characters.

By adjusting `count` parameter to 2048 we will have the following return, in this case:

```shell
00000000  00 00 00 00 00 00 00 00  91 02 00 00 00 00 00 00  |................|
00000010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000290  00 00 00 00 00 00 00 00  11 04 00 00 00 00 00 00  |................|
000002a0  64 61 74 61 3a 20 2f 68  6f 6d 65 2f 62 75 6c 6b  |data: /home/bulk|
[...]
00000320  79 2f 68 65 6c 6c 6f 5f  77 61 69 74 2e 6f 75 74  |y/hello_wait.out|
00000330  0a 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000340  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
000006a0  00 00 00 00 00 00 00 00  21 00 00 00 00 00 00 00  |........!.......|
000006b0  68 65 6c 6c 6f 20 66 72  6f 6d 20 74 68 65 20 68  |hello from the h|
000006c0  65 61 70 21 00 00 00 00  41 09 02 00 00 00 00 00  |eap!....A.......|
000006d0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000800
```
And there, between addresses 6b0 and 6c0 we have the data our code allocated in the heap.

When running the code in debug mode, we can also see the heap starting address associated to the `pointerToHeap` variable - in this case it is 5555555596b0, which we could also convert to decimal pass a precise interval to the dd skip parameter.
