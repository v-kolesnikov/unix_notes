#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/resource.h>
#include <unistd.h>

void write_pid(char *file_path)
{
    FILE *file = fopen(file_path, "w");
    fprintf(file, "%d\n", getpid());
    fflush(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }

    rlim_t fd;
    struct rlimit flim;

    if (getppid() != 1) {
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);

        if (fork() != 0) {
            exit(0);
        }

        setsid();
        write_pid(argv[1]);
    }

    getrlimit(RLIMIT_NOFILE, &flim);

    for (fd = 0; fd < flim.rlim_max; fd++) {
        close(fd);
    }

    chdir("/");

    openlog("Daemon skeleton", LOG_PID | LOG_CONS, LOG_DAEMON);
    syslog(LOG_INFO, "Daemon started...");
    closelog();

    while(1) {
        pause();
    }
}
