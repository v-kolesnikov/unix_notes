#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int fd;

    fd = creat("my_file", S_IRUSR | S_IWUSR | S_IXUSR);
    system("ls -l my_file");

    fchmod(fd, S_IRWXU | S_ISUID);
    system("ls -l my_file");

    fchmod(fd, S_IRWXU | S_IXOTH | S_ISVTX);
    system("ls -l my_file");

    fchmod(fd, S_IRWXU | S_ISGID | S_IXGRP);
    system("ls -l my_file");

    return 0;
}
