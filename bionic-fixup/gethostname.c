#include <errno.h>
#include <sys/utsname.h>
#include <string.h>

// int property_get(const char *key, char *value, const char *default_value)
// {
//     int len;
// 
//     len = __system_property_get(key, value);
//     if(len > 0) {
//         return len;
//     }
//     
//     if(default_value) {
//         len = strlen(default_value);
//         memcpy(value, default_value, len + 1);
//     }
//     return len;
// }

static int sethostname( const char* __name, size_t __len ) {
    errno = EPERM;
    return -1;
}

static int getdomainname( char* __name, size_t __len ) {
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

static int setdomainname( const char* __name, size_t __len ) {
    errno = EPERM;
    return -1;
}
