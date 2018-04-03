This program written in C language to copy file using the POSIX 
API/gcc compiler, and the file write will repeatedly use a buffer
of size 27 bytes to the output file.



The command line I used in this program:
printf(); - Print out the string to show user.
scanf();  - Ask user for the input.
peeror(); - Print the error for user.
exit();	  - exit the program.
close();  - close the file
write();  - write the input file to output file.



Users can use following command line to run the program:
Use command line "gcc filecopy.c -o fc" to create execute file.
Use command line "./fc" to execute the program.
Use command line "rm fc" to clean the program.



The program is execute as following:
- Welcome to the File Copy Program by <yourname>! 
- Enter the name of the file to copy from:
- <type in file name & hit return>
- Enter the name of the file to copy to:
- <type in the file name & hit return>
- File Copy Successful, <number> bytes copied



When I use diff command to compared two files, and the output is
Show the input file and output file is identical:
diff -s file1 file2
Files file1 and file2 are identical



I use "strace" utility to traces all of the system calls used
during the execution in Linux. 
The table below is the output of the system calls used:

% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 18.50    0.000252          17        15         6 open
 12.41    0.000169          24         7           read
  9.32    0.000127           8        15           mmap
  8.66    0.000118          15         8           fstat
  7.64    0.000104          17         6         3 stat
  6.24    0.000085           9         9           close
  5.58    0.000076          11         7           rt_sigprocmask
  5.51    0.000075           9         8           rt_sigaction
  4.11    0.000056          11         5           brk
  2.28    0.000031           4         8           mprotect
  2.13    0.000029          15         2           munmap
  1.98    0.000027           9         3           lseek
  1.98    0.000027          27         1           execve
  1.98    0.000027           9         3         1 fcntl
  1.76    0.000024          24         1         1 access
  1.40    0.000019          10         2           getrlimit
  1.32    0.000018          18         1           getgid
  1.32    0.000018          18         1           geteuid
  1.25    0.000017          17         1           getegid
  0.73    0.000010          10         1         1 ioctl
  0.73    0.000010          10         1           dup2
  0.73    0.000010          10         1           getpgrp
  0.66    0.000009           9         1           getpid
  0.66    0.000009           9         1           uname
  0.66    0.000009           9         1           getppid
  0.44    0.000006           6         1           getuid
  0.00    0.000000           0         1           arch_prctl
------ ----------- ----------- --------- --------- ----------------
100.00    0.001362                   111        12 total

We can see the information for the program execution:
- Total execution time is 0.001362 seconds.
- Total call 111 times.
- Total errors 12.