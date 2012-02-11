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
	${OBJECTDIR}/StandardSharedCXXExample1.o \
	${OBJECTDIR}/cpp_plugin.o \
	${OBJECTDIR}/StandardSharedCXXExample2.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_cxx_shared_example_plugin.so

../../xtractorfan/dist/Debug/GNU-Linux-x86/std_cxx_shared_example_plugin.so: ${OBJECTFILES}
	${MKDIR} -p ../../xtractorfan/dist/Debug/GNU-Linux-x86
	${LINK.cc} -shared -o ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_cxx_shared_example_plugin.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/StandardSharedCXXExample1.o: StandardSharedCXXExample1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I../../include -I../../include/linux32 -I../.. -I.. -fPIC  -o ${OBJECTDIR}/StandardSharedCXXExample1.o StandardSharedCXXExample1.cpp

${OBJECTDIR}/cpp_plugin.o: cpp_plugin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I../../include -I../../include/linux32 -I../.. -I.. -fPIC  -o ${OBJECTDIR}/cpp_plugin.o cpp_plugin.cpp

${OBJECTDIR}/StandardSharedCXXExample2.o: StandardSharedCXXExample2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I../../include -I../../include/linux32 -I../.. -I.. -fPIC  -o ${OBJECTDIR}/StandardSharedCXXExample2.o StandardSharedCXXExample2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} ../../xtractorfan/dist/Debug/GNU-Linux-x86/std_cxx_shared_example_plugin.so

# Subprojects
.clean-subprojects:
