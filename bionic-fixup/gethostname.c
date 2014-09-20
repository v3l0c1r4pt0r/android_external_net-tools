#include <errno.h>
#include <sys/utsname.h>
#include <string.h>
#include <sys/system_properties.h>

#include "gethostname.h"

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

int gethostname(char* name, size_t namelen)
{
    char key[] = HOSTNAME_PROP;
    char value[PROPERTY_VALUE_MAX];
    int len = __system_property_get(key, value);
    if(len == 0)
      return -1;
    strncpy(name, value, namelen);
    return 0;
}

int sethostname( const char* __name, size_t __len ) {
    //TODO: implement with usage of net.hostname
    errno = EPERM;
    return -1;
}

int getdomainname( char* __name, size_t __len ) {
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

int setdomainname( const char* __name, size_t __len ) {
    errno = EPERM;
    return -1;
}
