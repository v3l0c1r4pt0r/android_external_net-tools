/*
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "properties"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sockets.h"
#include <errno.h>
#include <assert.h>

#include "properties.h"

// #ifdef HAVE_LIBC_SYSTEM_PROPERTIES

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>


static int send_prop_msg(prop_msg *msg)
{
    int s;
    int r;
    
    s = socket_local_client(PROP_SERVICE_NAME, 
                            ANDROID_SOCKET_NAMESPACE_RESERVED,
                            SOCK_STREAM);
    if(s < 0) return -1;
    
    while((r = send(s, msg, sizeof(prop_msg), 0)) < 0) {
        if((errno == EINTR) || (errno == EAGAIN)) continue;
        break;
    }

    if(r == sizeof(prop_msg)) {
        r = 0;
    } else {
        r = -1;
    }

    close(s);
    return r;
}

int property_set(const char *key, const char *value)
{
    prop_msg msg;
    unsigned resp;

    if(key == 0) return -1;
    if(value == 0) value = "";
    
    if(strlen(key) >= PROP_NAME_MAX) return -1;
    if(strlen(value) >= PROP_VALUE_MAX) return -1;
    
    msg.cmd = PROP_MSG_SETPROP;
    strcpy((char*) msg.name, key);
    strcpy((char*) msg.value, value);

    return send_prop_msg(&msg);
}

// #elif defined(HAVE_SYSTEM_PROPERTY_SERVER)
// 
// /*
//  * The Linux simulator provides a "system property server" that uses IPC
//  * to set/get/list properties.  The file descriptor is shared by all
//  * threads in the process, so we use a mutex to ensure that requests
//  * from multiple threads don't get interleaved.
//  */
// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <sys/un.h>
// #include <pthread.h>
// 
// /*
//  * Perform one-time initialization.
//  */
// static void init(void)
// {
//     assert(gPropFd == -1);
// 
//     gPropFd = connectToServer(SYSTEM_PROPERTY_PIPE_NAME);
//     if (gPropFd < 0) {
//         //LOGW("not connected to system property server\n");
//     } else {
//         //LOGV("Connected to system property server\n");
//     }
// }
// 
// int property_set(const char *key, const char *value)
// {
//     char sendBuf[1+PROPERTY_KEY_MAX+PROPERTY_VALUE_MAX];
//     char recvBuf[1];
//     int result = -1;
// 
//     //LOGV("PROPERTY SET [%s]: [%s]\n", key, value);
// 
//     pthread_once(&gInitOnce, init);
//     if (gPropFd < 0)
//         return -1;
// 
//     if (strlen(key) >= PROPERTY_KEY_MAX) return -1;
//     if (strlen(value) >= PROPERTY_VALUE_MAX) return -1;
// 
//     memset(sendBuf, 0xdd, sizeof(sendBuf));    // placate valgrind
// 
//     sendBuf[0] = (char) kSystemPropertySet;
//     strcpy(sendBuf+1, key);
//     strcpy(sendBuf+1+PROPERTY_KEY_MAX, value);
// 
//     pthread_mutex_lock(&gPropertyFdLock);
//     if (write(gPropFd, sendBuf, sizeof(sendBuf)) != sizeof(sendBuf)) {
//         pthread_mutex_unlock(&gPropertyFdLock);
//         return -1;
//     }
//     if (read(gPropFd, recvBuf, sizeof(recvBuf)) != sizeof(recvBuf)) {
//         pthread_mutex_unlock(&gPropertyFdLock);
//         return -1;
//     }
//     pthread_mutex_unlock(&gPropertyFdLock);
// 
//     if (recvBuf[0] != 1)
//         return -1;
//     return 0;
// }
// 
// #endif
