#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/static_plugin.o \
	${OBJECTDIR}/StandardStaticExample.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a

dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${RM} dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a
	${AR} rv dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a ${OBJECTFILES} 
	$(RANLIB) dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a

${OBJECTDIR}/static_plugin.o: static_plugin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -DPF_PLATFORM_LINUX -DAPR_DECLARE_STATIC -DAPU_DECLARE_STATIC -I../../include -I../../include/linux32 -I../.. -I.. -o ${OBJECTDIR}/static_plugin.o static_plugin.cpp

${OBJECTDIR}/StandardStaticExample.o: StandardStaticExample.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -DPF_PLATFORM_LINUX -DAPR_DECLARE_STATIC -DAPU_DECLARE_STATIC -I../../include -I../../include/linux32 -I../.. -I.. -o ${OBJECTDIR}/StandardStaticExample.o StandardStaticExample.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/libstd_cxx_static_example_plugin.a

# Subprojects
.clean-subprojects:
