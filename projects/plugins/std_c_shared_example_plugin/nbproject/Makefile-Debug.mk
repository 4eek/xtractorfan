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
OBJECTDIR=build/Debug/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/StandardSharedCExample.o \
	${OBJECTDIR}/c_plugin.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_c_shared_example_plugin.so

../../xtractorfan/dist/Debug/GNU-Linux-x86/std_c_shared_example_plugin.so: ${OBJECTFILES}
	${MKDIR} -p ../../xtractorfan/dist/Debug/GNU-Linux-x86
	${LINK.c} -shared -o ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_c_shared_example_plugin.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/StandardSharedCExample.o: StandardSharedCExample.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -DPF_PLATFORM_LINUX -DAPR_DECLARE_STATIC -DAPU_DECLARE_STATIC -I../../include -I../../include/linux32 -I../.. -I.. -fPIC  -o ${OBJECTDIR}/StandardSharedCExample.o StandardSharedCExample.c

${OBJECTDIR}/c_plugin.o: c_plugin.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -DPF_PLATFORM_LINUX -DAPR_DECLARE_STATIC -DAPU_DECLARE_STATIC -I../../include -I../../include/linux32 -I../.. -I.. -fPIC  -o ${OBJECTDIR}/c_plugin.o c_plugin.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_c_shared_example_plugin.so

# Subprojects
.clean-subprojects:
