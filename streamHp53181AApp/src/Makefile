TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
# Build an IOC support library
LIBRARY_IOC += Hp53181AStream

# devHp53181AStream.dbd will be created and installed
DBD += Hp53181AStream.dbd

# Hp53181AStream.dbd will be made up from these files:
Hp53181AStream_DBD += base.dbd

# streams:
#Hp53181AStream_DBD += aaiRecord.dbd
#Hp53181AStream_DBD += aaoRecord.dbd
Hp53181AStream_DBD += asyn.dbd
Hp53181AStream_DBD += asynRecord.dbd
Hp53181AStream_DBD += stream.dbd
Hp53181AStream_DBD += drvAsynIPPort.dbd
Hp53181AStream_DBD += drvVxi11.dbd
Hp53181AStream_DBD += drvAsynSerialPort.dbd

# The following are compiled and added to the Support library
Hp53181AStream_SRCS    += Hp53181AStream.c

#add a definition for each support application used by this module
Hp53181AStream_LIBS += stream
Hp53181AStream_LIBS += asyn

#NOTES:
#      1)It is not possible to build sncExample both as a component of streamHp53181A
#        and standalone. You must choose only one.
#      2)To build sncExample SNCSEQ must be defined in <top>/configure/RELEASE

#The following builds sncExample as a component of freqCount
#streamHp53181A_SRCS += sncExample.stt
#streamHp53181A_LIBS += seq pv

Hp53181AStream_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

