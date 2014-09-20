LOCAL_PATH := $(call my-dir)

#########################

include $(CLEAR_VARS)

HWOBJS	 = hw.c loopback.c slip.c ether.c ax25.c ppp.c arcnet.c tr.c tunnel.c frame.c sit.c rose.c ash.c \
	fddi.c hippi.c hdlclapb.c strip.c irda.c ec_hw.c x25.c eui64.c ib.c
AFOBJS	 = unix.c inet.c inet6.c ax25.c ipx.c ddp.c ipx.c netrom.c af.c rose.c econet.c x25.c
AFGROBJS = inet_gr.c inet6_gr.c ipx_gr.c ddp_gr.c netrom_gr.c ax25_gr.c rose_gr.c getroute.c x25_gr.c
AFSROBJS = inet_sr.c inet6_sr.c netrom_sr.c ipx_sr.c setroute.c x25_sr.c
ACTOBJS  = slip_ac.c ppp_ac.c activate.c
VARIA	 = getargs.c masq_info.c proc.c util.c nstrcmp.c interface.c sockets.c

ifeq ($(HAVE_IP_TOOLS),1)
VARIA	+= util-ank.c
endif

LOCAL_SRC_FILES :=  $(sort $(VARIA) $(AFOBJS) $(HWOBJS) \
		$(AFGROBJS) $(AFSROBJS) $(ACTOBJS))

LOCAL_MODULE := net-tools

LOCAL_C_INCLUDES := include bionic-fixup .

LOCAL_CFLAGS := -O2 -g -W -Wall -include bionic-fixup/Xprotoent.h
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libcutils

include $(BUILD_STATIC_LIBRARY)

