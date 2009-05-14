#Makefile at top of application tree
TOP = .
include $(TOP)/configure/CONFIG

DIRS += configure
DIRS += Hp53181AApp

include $(TOP)/configure/RULES_TOP
