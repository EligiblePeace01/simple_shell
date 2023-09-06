# simple_shell
Group Project


INTRODUCTION

Peace Enwere and Aymane Bahla, two Software Engineering students at ALX SE, worked together on the basic shell project, which allowed us to simulate the functioning of a shell and included some of its most crucial features, like Handle PATH and Handle command lines with arguments.

DESCRIPTION 📖

ALX SE Shell (hsh), is a simple program of the line commands. This simple shell recreates basic and some more complex functionalities to result in our own Shell. This shell si developed in the programming language c. This shell takes the keyboard commands and delivers them to the system to be executed. some built-in commands implement: exit, env, help, cd.
Requirements 📋

Simple_shell is designed to run in the Ubuntu 20.04 LTS linux environment and to be compiled using the gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


TESTING
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

List of allowed functions and system calls

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

AUTHORS
Peace Enwere 
Aymane Bahla
