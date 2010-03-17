TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
# Build an IOC support library

LIBRARY_IOC += Hp53181AGpib

# devHp53181AGpib.dbd will be created and installed
DBD += Hp53181AGpib.dbd

# The following are compiled and added to the Support library
Hp53181AGpib_SRCS    += Hp53181AGpib.c

#add a definition for each support application used by this module

Hp53181AGpib_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

