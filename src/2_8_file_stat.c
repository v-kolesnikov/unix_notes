#ifdef __APPLE__
#  define NLINK_FORMAT "%hu"
#  define INODE_FORMAT "%llu"
#  define SSIZE_FORMAT "%llu"
#elif __linux__
#  define NLINK_FORMAT "%lu"
#  define INODE_FORMAT "%lu"
#  define SSIZE_FORMAT "%lu"
#else
#  error "Unsupported platform"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }

    struct stat s;
    char *ptype;

    lstat(argv[1], &s);

    if (S_ISREG(s.st_mode)) { ptype = "Normal file"; }
    else if(S_ISLNK(s.st_mode)) { ptype = "Catalog"; }
    else if(S_ISLNK(s.st_mode)) { ptype = "Symlink"; }
    else if(S_ISCHR(s.st_mode)) { ptype = "Symbol device"; }
    else if(S_ISBLK(s.st_mode)) { ptype = "Block device"; }
    else if(S_ISSOCK(s.st_mode)) { ptype = "Socket"; }
    else if(S_ISFIFO(s.st_mode)) { ptype = "FIFO"; }
    else { ptype = "Unknown type"; }

    printf("type = %s\n", ptype);
    printf("perm = %o\n", s.st_mode);
    printf("inode = " INODE_FORMAT "\n", s.st_ino);
    printf("nlink = " NLINK_FORMAT "\n", s.st_nlink);
    printf("dev = (%d, %d)\n", major(s.st_dev), minor(s.st_dev));
    printf("UID = %d\n", s.st_uid);
    printf("GID = %d\n", s.st_gid);
    printf("rdev = (%d, %d)\n", major(s.st_rdev), minor(s.st_rdev));
    printf("size = " SSIZE_FORMAT "\n", s.st_size);
    printf("atime = %s", ctime(&s.st_atime));
    printf("mtime = %s", ctime(&s.st_mtime));
    printf("ctime = %s", ctime(&s.st_ctime));

    return 0;
}
