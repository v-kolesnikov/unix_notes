#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return -1;
    }

    int fd_src;
    int fd_dst;

    char * addr_src;
    char * addr_dst;

    struct stat filestat;

    fd_src = open(argv[1], O_RDONLY);
    fd_dst = open(argv[2], O_RDWR | O_CREAT);

    fstat(fd_src, &filestat);

    lseek(fd_dst, filestat.st_size - 1, SEEK_SET);
    write(fd_dst, "", 1);

    addr_src = mmap((char *)0, filestat.st_size,
                    PROT_READ, MAP_SHARED, fd_src, 0);

    addr_dst = mmap((char *)0, filestat.st_size,
                    PROT_READ | PROT_WRITE, MAP_SHARED, fd_dst, 0);

    memcpy(addr_dst, addr_src, filestat.st_size);

    chmod(argv[2], filestat.st_mode);

    return 0;
}
