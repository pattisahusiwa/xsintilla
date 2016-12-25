export MAKEFLAGS 	   += --silent
export SCIVERSION 		= 371
export APPNAME 			= xsintilla

export ROOTDIR 			= .
export SCIDIR 			= $(ROOTDIR)/scintilla
export BUILDROOT 		= $(ROOTDIR)/build
export LIBROOT 			= $(ROOTDIR)/lib
export SRCROOT 			= $(ROOTDIR)/src
export LIBXOJO 			= $(ROOTDIR)/libxojo
export LIBXSINTILLA 	= $(ROOTDIR)/libxsintilla
export MODULES 			= $(ROOTDIR)/modules

##
# plugin directories definition
export PLUGINSDKDIR 	= $(ROOTDIR)/PluginsSDK
export SDKGLUECODEDIR 	= $(PLUGINSDKDIR)/GlueCode
export SDKINCLUDEDIR 	= $(PLUGINSDKDIR)/Includes
export PREFIXHEADER 	= $(SDKINCLUDEDIR)/LinuxHeader.h

all: makedir
	$(MAKE) -f linux32.mk
	@echo "******"
	@echo "******"
#	$(MAKE) -f linux64.mk
	@echo "******"
	@echo "DONE."
makedir:
	mkdir -p $(BUILDROOT)
	mkdir -p $(LIBROOT)

clean:
	$(MAKE) -f linux32.mk clean
	$(MAKE) -f linux64.mk clean
