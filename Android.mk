MY_LOCAL_PATH := $(call my-dir)

LOCAL_PATH := $(MY_LOCAL_PATH)

#########################

include $(call all-subdir-makefiles)

LOCAL_PATH := $(MY_LOCAL_PATH)

include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  hostname.c

LOCAL_MODULE := hostname

LOCAL_C_INCLUDES := include . lib bionic-fixup

LOCAL_CFLAGS := -O2 -g -W -Wall -fno-strict-aliasing -include bionic-fixup/Xprotoent.h
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libcutils

LOCAL_STATIC_LIBRARIES := fixup dnet

include $(BUILD_EXECUTABLE)
