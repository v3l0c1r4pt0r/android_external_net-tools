#include <stdint.h>
#include <errno.h>
#include <sys/utsname.h>
#include <string.h>

#define setprotoent(arg) {}
#define endprotoent() {}
#define getprotoent() NULL

typedef uint32_t in_addr_t;

static inline int sethostname( const char* __name, size_t __len ) {
    errno = EPERM;
    return -1;
}

static inline int getdomainname( char* __name, size_t __len ) {
    struct utsname n;
    if (uname(&n) < 0)
    {
        //should not happen
        errno = EPERM;
        return -1;
    }
    strncpy(__name, n.domainname, __len);
    return 0;
}

static inline int setdomainname( const char* __name, size_t __len ) {
    errno = EPERM;
    return -1;
}
