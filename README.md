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

Installation with ndk-build
---------------------------
Alternative way to compile the project is to use ndk-build script that is provided by your NDK installation.
While executing ndk-build you have to set two variables:

- NDK_PROJECT_PATH - should point to main directory of the project
- APP_BUILD_SCRIPT - should be Android.mk (it is relative to project path)

It can be done i.e. by typing:
```
$NDK/ndk-build NDK_PROJECT_PATH=`pwd` APP_BUILD_SCRIPT=Android.mk
```
when CWD is main directory of a project and $NDK points to your NDK installation.

When using ndk-build you don't have to configure the project since there is precofigured config.h.

Issues
------
- ifconfig is failing at i.e. changing MAC address probably due to lack of getgrnam() function
in bionic libc
- hostname cannot set hostname at the moment; domainname always returns error

You can report any other issues using github and I will try to fix them.
