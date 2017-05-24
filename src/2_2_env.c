#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[]) {
    printf("Count of arguments passed to progamm %s: %d\n", argv[0], argc - 1);
    printf("Max memory for storage agruments: %ld\n", sysconf(_SC_ARG_MAX));

    for (int i = 1; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    for (int i = 0; i < 8; ++i) {
        if (environ[i] != NULL) {
            printf("environ[%d] : %s\n", i, environ[i]);
        }
    }

    return 0;
}
