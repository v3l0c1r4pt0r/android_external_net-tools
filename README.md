android_external_net-tools
==========================

Configuration tools for Linux networking

Overview
--------
This repository is an approach to provide native, full-featured version of
net-tools for Android based devices. As of now it is possible to compile following tools:
- arp - manipulate the system ARP cache
- ifconfig - configure a network interface
- rarp - manipulate the system RARP table
- route - show / manipulate the IP routing table

Following tools still doesn't work:
- hostname
- netstat
- slattach
- plipconfig
- nameif

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