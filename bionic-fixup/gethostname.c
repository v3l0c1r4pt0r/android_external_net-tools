#include <errno.h>
#include <sys/utsname.h>
#include <string.h>
#include <sys/system_properties.h>

#include "gethostname.h"
#include "properties.h"

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
    if(property_set(HOSTNAME_PROP, __name))
    {
        errno = EPERM;
        return -1;
    }
    else
        return 0;
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
