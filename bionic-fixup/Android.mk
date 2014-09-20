LOCAL_PATH := $(call my-dir)

#########################

include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  gethostname.c

LOCAL_MODULE := fixup

LOCAL_C_INCLUDES := include

LOCAL_CFLAGS := -O2 -g -W -Wall
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libcutils

include $(BUILD_STATIC_LIBRARY)

