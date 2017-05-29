#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

#define MAXARG 100
#define MAXENV 100
#define MAXNAME 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        exit(1);
    }

    struct passwd *pw;

    /* char logname[MAXNAME]; */
    /* char *arg[MAXARG]; */
    /* char *envir[MAXENV]; */

    pw = getpwnam(argv[1]);

    if (pw == 0) {
        exit(2);
        /* retry(); */
    }

    else {
        setuid(pw->pw_uid);
        setgid(pw->pw_gid);
        execve(pw->pw_shell, (char *const *)argv[2], environ);
    }

    return 0;
}
