#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sig_hndlr(int signo) {
    signal(SIGINT, sig_hndlr);
    printf("Received signal SIGINT %d\n", signo);
    fflush(stdout);
}

int main() {
    signal(SIGINT, sig_hndlr);
    signal(SIGUSR1, SIG_DFL);
    signal(SIGUSR2, SIG_IGN);

    while(1) {
        pause();
    }
}
