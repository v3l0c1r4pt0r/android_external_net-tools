android_external_net-tools
==========================

Configuration tools for Linux networking

Overview
--------
This repository is an approach to provide native, full-featured version of
net-tools for Android based devices. As of now it is possible to compile following tools:
- arp - manipulate the system ARP cache
- hostname - show or set system host name
- ifconfig - configure a network interface
- netstat - Print network connections, routing tables, interface statistics, masquerade connections, and multicast memberships
- rarp - manipulate the system RARP table
- route - show / manipulate the IP routing table

Following tools still doesn't work:
- slattach
- plipconfig
- nameif

This repo provides all tools available in net-tools package. However it was meant to provide netstat for Android
because busybox implementation is really limited. 

Installation
------------
- At first you need to set CC, AR and RANLIB variables e.g.:
```
export CC=arm-linux-androidebi-gcc
export AR=arm-linux-androidebi-ar
export RANLIB=arm-linux-androidebi-ranlib
```
- Then configure with:
```
make config
```
You can use default values since they were modified to be compatible with Android
- Next you can compile using make with name of the tool as argument e.g.:
```
make ifconfig
```
It is not possible to
compile them all since compilation will terminate on hostname and compile only ifconfig.

Issues
------
- ifconfig is failing at i.e. changing MAC address probably due to lack of getgrnam() function
in bionic libc
- hostname: domainname always returns error

You can report any other issues using github and I will try to fix them.
