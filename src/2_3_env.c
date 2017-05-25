#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *term;

    size_t buf_size = 200;

    char buf[buf_size];
    char var[buf_size];

    if ((term = getenv("TERM")) == NULL) {
        printf("Variable TERM is not defined, enter value: ");
        fgets(buf, buf_size, stdin);
        sprintf(var, "TERM=%s", buf);
    } else {
        printf("TERM=%s. Change? [y/buf_size] ", getenv("TERM"));
        fgets(buf, buf_size, stdin);
        if (buf[0] == 'Y' || buf[0] == 'y') {
            printf("TERM=");
            fgets(buf, buf_size, stdin);
            sprintf(var, "TERM=%s", buf);
            putenv(var);
            printf("new %s\n", var);
        }
    }

    return 0;
}
