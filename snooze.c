#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>  
#include <signal.h>
#include <errno.h>
#include <string.h>

void handler(int sig)
{
    return;
}

void snooze(unsigned int secs) {
    unsigned int rc = sleep(secs);
    printf("Slept for %d of %d secs.\n", secs-rc, secs);
    return;
}

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "usage: %s <secs>\n", argv[0]);
        exit(0);
    }
    if (signal(SIGINT, handler) == SIG_ERR)
        unix_error("siganl error\n");
    snooze(atoi(argv[1]));
    exit(0);
}