#ifdef __APPLE__
#  define RLIM_T_FORMAT "%-15llu"
#elif __linux__
#  define RLIM_T_FORMAT "%-15lu"
#else
#  error "Unsupported platform"
#endif

#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

void disp_limit(int resource, char *rname) {
    struct rlimit rlm;

    getrlimit(resource, &rlm);

    printf("%-15s ", rname);

    if (rlm.rlim_cur == RLIM_INFINITY) {
        printf("%-15s", "infinite ");
    } else {
        printf(RLIM_T_FORMAT, rlm.rlim_cur);
    }

    if (rlm.rlim_max == RLIM_INFINITY) {
        printf("%-15s\n", "infinite");
    } else {
        printf(RLIM_T_FORMAT, rlm.rlim_max);
        printf("\n");
	}
}

int main() {
    disp_limit(RLIMIT_CORE, "RLIMIT_CORE");
    disp_limit(RLIMIT_CPU, "RLIMIT_CPU");
    disp_limit(RLIMIT_DATA, "RLIMIT_DATA");
    disp_limit(RLIMIT_FSIZE, "RLIMIT_FSIZE");
    disp_limit(RLIMIT_NOFILE, "RLIMIT_NOFILE");
    disp_limit(RLIMIT_STACK, "RLIMIT_STACK");

/* BSD */
#ifdef RLIMIT_NPROC
    disp_limit(RLIMIT_NPROC, "RLIMIT_NPROC");
#endif

/* BSD */
#ifdef RLIMIT_RSS
    disp_limit(RLIMIT_RSS, "RLIMIT_RSS");
#endif

/* BSD */
#ifdef RLIMIT_MEMLOCK
    disp_limit(RLIMIT_MEMLOCK, "RLIMIT_MEMLOCK");
#endif

/* System V */
#ifdef RLIMIT_VMEM
    disp_limit(RLIMIT_VMEM, "RLIMIT_VMEM");
#endif

    return 0;
}
