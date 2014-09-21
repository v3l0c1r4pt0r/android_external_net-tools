#
# bionic-fixup/Makefile	Makefile for the bionic-fixup function collection
#
# Author:	Fred N. van Kempen, <waltje@uwalt.nl.mugnet.org>
#		Copyright 1993 MicroWalt Corporation
#
# Modified by:	v3l0c1r4pt0r, <v3l0c1r4pt0r@gmail.com>
#
#		This program is free software; you can redistribute it
#		and/or  modify it under  the terms of  the GNU General
#		Public  License as  published  by  the  Free  Software
#		Foundation;  either  version 2 of the License, or  (at
#		your option) any later version.
#


# Default Name
BIONIC_NAME = fixup

OBJS	= socket_local_client.o properties.o gethostname.o


# This can be overwritten by the TOPLEVEL Makefile
TOPDIR=..
CFLAGS += -I$(TOPDIR) -I$(TOPDIR)/include -include bionic-fixup/Xprotoent.h -DHAVE_SYS_SOCKET_H # -DHAVE_LIBC_SYSTEM_PROPERTIES # -fPIC

.SUFFIXES: .a

all:	lib$(BIONIC_NAME).a

lib$(BIONIC_NAME).a:	Makefile $(TOPDIR)/config.h $(OBJS)
			@echo Building $@
			@rm -f $@
			@$(AR) rcs $@ $(OBJS)

clean:
		rm -f *.o *~ *.orig lib$(BIONIC_NAME).a

clobber:	clean

# End of lib/Makefile.
