#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

/* The prototypes */
void parent();
void child1();
void child2();
void child3();
void child4();
void child5();
void child6();
void child7();

/**
 * The function called by the FIRST child.
 */
void child1() {
    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());

    // TODO: Fill me in
    pid_t pid_a, pid_b;

    pid_b = fork();

    if (pid_b == 0) {
        child2();
    } else {
        pid_a = fork();

        if (pid_a == 0) {
            child3();
        }
    }
}

/**
 * The function called by the SECOND child.
 */
void child2() {
    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());

    // TODO: Fill me in
    pid_t pid_a, pid_b;

    pid_b = fork();

    if (pid_b == 0) {
        child4();

        if (wait(NULL) < 0) {
            exit(-1);
        }

        exit(0);
    } else {
        pid_a = fork();

        if (pid_a == 0) {
            child5();

            if (wait(NULL) < 0) {
                exit(-1);
            }

            exit(0);
        }
    }
}

/**
 * The function called by the THIRD child.
 */
void child3() {
    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());

    pid_t pid_a, pid_b;

    pid_b = fork();

    if (pid_b == 0) {
        child6();

        if (wait(NULL) < 0) {
            exit(-1);
        }

        exit(0);
    } else {
        pid_a = fork();

        if (pid_a == 0) {
            child7();

            if (wait(NULL) < 0) {
                exit(-1);
            }

            exit(0);
        }
    }
}

/**
 * The function called by the FOURTH child.
 */
void child4() {

    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());
}

/**
 * The function called by the FIFTH child.
 */
void child5() {

    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());
}

/**
 * The function called by the SIXTH child.
 */
void child6() {

    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());
}

/**
 * The function called by the SEVENTH child.
 */
void child7() {

    fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(),
            getppid());
}

/**
 * The function called by the parent
 */
void parent() {
    fprintf(stderr, "I am the original parent; my process ID is pid=%d\n",
            getpid());

    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork Failed\n";
        exit(-1);
    } else if (pid == 0) {
        child1();
    }
}

/**
 * The main function
 */
int main() { parent(); }
