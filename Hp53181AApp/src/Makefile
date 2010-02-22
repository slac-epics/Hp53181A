TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
# Build an IOC support library

LIBRARY_IOC += devHp53181AGpib

DBD += devHp53181AGpib.dbd

# The following are compiled and added to the Support library
devHp53181AGpib_SRCS    += devHp53181AGpib.c

devHp53181AGpib_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

