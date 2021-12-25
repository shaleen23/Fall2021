# CPSC 351 - Assignment 1

|     Members      |                 Email                 |
| :--------------: | :-----------------------------------: |
|  Mike Ploythai   |    mikeploythai@csu.fullerton.edu     |
|  Shaleen Mathur  |   shaleenmathur26@csu.fullerton.edu   |
|    Benson Lee    |       blee71@csu.fullerton.edu        |
|  Jose Hernandez  | josellhernandez1113@csu.fullerton.edu |
| Julio Santamaria |  santamariajulio64@csu.fullerton.edu  |

## Details

```
Language: C++

EXECUTION INSTRUCTIONS
======================
- Compile source code with g++ or clang++
- Run via terminal with ./{name}.{extension}

EXECUTION TIMES
===============
- Serial Downloader
    > real    1m14.457s
    > user    0m0.201s
    > sys     0m2.300s
- Parallel Downloader
    > real    1m25.395s
    > user    0m0.491s
    > sys     0m3.980s

ANSWERS
=======
1. Real time is the actual time it took to finish the whatever the program is doing. User time is the time the CPU took to execute the process. Sys time is the time the CPU took inside the kernel

2. Sys time is longer because of how it allows the process to be take action in kernel mode, which allows for the program to make use of higher privileges

3. The serial downloader finishes faster because there's not too much going on compared to the parallel downloader, which downloads all files at once utilizing more bandwidth

4. The serial downloader still finishes faster compared to the parallel downloader
```

## Extra Credit?

no
