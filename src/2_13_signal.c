#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void (*mysignal (int signo, void (*hndlr)(int)))(int) {
    struct sigaction act, oact;

    act.sa_handler = hndlr;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (signo != SIGALRM) {
        act.sa_flags |= SA_RESTART;
	}

    if (sigaction(signo, &act, &oact) < 0) {
        return(SIG_ERR);
    }

    return(oact.sa_handler);
}

static void sig_hndlr(int signo) {
    mysignal(SIGINT, sig_hndlr);
    printf("Received signal SIGINT %d\n", signo);
    fflush(stdout);
}

int main() {
    mysignal(SIGINT, sig_hndlr);
    mysignal(SIGUSR1, SIG_DFL);
    mysignal(SIGUSR2, SIG_IGN);

    while(1) {
        pause();
    }
}
