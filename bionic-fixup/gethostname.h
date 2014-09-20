#ifndef __GETHOSTNAME_H
#define __GETHOSTNAME_H

#define PROPERTY_KEY_MAX   32
#define PROPERTY_VALUE_MAX  92

#define HOSTNAME_PROP "net.hostname"

int gethostname(char* name, size_t namelen);
int sethostname( const char* __name, size_t __len );
int getdomainname( char* __name, size_t __len );
int setdomainname( const char* __name, size_t __len );

#endif
