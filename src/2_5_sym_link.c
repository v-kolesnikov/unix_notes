#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSZ 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
    }

    char buf[BUFSZ + 1];

    int nread;
    int fd;

    printf("Read symbolic link\n");

    nread = readlink(argv[1], buf, BUFSZ);

    if (nread < 0) {
        perror("readlink");
        exit(1);
    }

    buf[nread] = '\0';

    printf("Symbolic link:\n %s\n", buf);

    printf("Read file\n");

    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        perror("open");
        exit(2);
    }

    nread = read(fd, buf, BUFSZ);

    if (nread < 0) {
        perror("read");
        exit(3);
    }

    buf[nread] = '\0';

    printf("Target file:\n %s\n", buf);

    close(fd);

    return 0;
}
