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
	${OBJECTDIR}/wrapper_plugin.o \
	${OBJECTDIR}/StandardWrapperExample2.o \
	${OBJECTDIR}/StandardWrapperExample1.o

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
	${MAKE}  -f nbproject/Makefile-Release.mk ../../xtractorfan/dist/Release/GNU-Linux-x86/std_wrapper_example_plugin.so

../../xtractorfan/dist/Release/GNU-Linux-x86/std_wrapper_example_plugin.so: ${OBJECTFILES}
	${MKDIR} -p ../../xtractorfan/dist/Release/GNU-Linux-x86
	${LINK.cc} -shared -o ../../xtractorfan/dist/Release/GNU-Linux-x86/std_wrapper_example_plugin.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/wrapper_plugin.o: wrapper_plugin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -I../.. -I../../include -I../../include/linux32 -fPIC  -o ${OBJECTDIR}/wrapper_plugin.o wrapper_plugin.cpp

${OBJECTDIR}/StandardWrapperExample2.o: StandardWrapperExample2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -I../.. -I../../include -I../../include/linux32 -fPIC  -o ${OBJECTDIR}/StandardWrapperExample2.o StandardWrapperExample2.cpp

${OBJECTDIR}/StandardWrapperExample1.o: StandardWrapperExample1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -I../.. -I../../include -I../../include/linux32 -fPIC  -o ${OBJECTDIR}/StandardWrapperExample1.o StandardWrapperExample1.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} ../../xtractorfan/dist/Release/GNU-Linux-x86/std_wrapper_example_plugin.so

# Subprojects
.clean-subprojects:
