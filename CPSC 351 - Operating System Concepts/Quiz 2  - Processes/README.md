# CPSC 351-08 Quiz 2

<b>Group Members</b>

```
Mike Ploythai - mikeploythai@csu.fullerton.edu

Shaleen Mathur - shaleenmathur26@csu.fullerton.edu

Benson Lee - blee71@csu.fullerton.edu

Jose Hernandez - josellhernandez1113@csu.fullerton.edu
```

<b>Steps to execute program</b>

- Compile in the terminal with g++
```
$ g++ -o processes.cpp -o processes
```
- Run via terminal
```
$ ./processes
```
- Resulting output example:
```
I am the original parent; my process ID is pid=3913
I am child pid=3914; my parent is pid=3913
I am child pid=3915; my parent is pid=3914
I am child pid=3916; my parent is pid=3914
I am child pid=3917; my parent is pid=3915
I am child pid=3918; my parent is pid=3916
I am child pid=3919; my parent is pid=3915
I am child pid=3920; my parent is pid=3916
```