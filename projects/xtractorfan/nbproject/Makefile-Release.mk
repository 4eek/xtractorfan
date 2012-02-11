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
include xtractorfan-Makefile.mk

# Object Directory
OBJECTDIR=build/Release/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AppManager.o \
	${OBJECTDIR}/Dummy.o \
	${OBJECTDIR}/xTractorFan.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lapr-1 -laprutil-1 -ldl -lapr-1 -laprutil-1 ../object_model/dist/Release/GNU-Linux-x86/libobject_model.a ../plugin_framework/dist/Release/GNU-Linux-x86/libplugin_framework.a ../utils/dist/Release/GNU-Linux-x86/libutils.a ../plugins/std_cxx_static_example/dist/Release/GNU-Linux-x86/libstd_cxx_static_example.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/xtractorfan

dist/Release/GNU-Linux-x86/xtractorfan: ../object_model/dist/Release/GNU-Linux-x86/libobject_model.a

dist/Release/GNU-Linux-x86/xtractorfan: ../plugin_framework/dist/Release/GNU-Linux-x86/libplugin_framework.a

dist/Release/GNU-Linux-x86/xtractorfan: ../utils/dist/Release/GNU-Linux-x86/libutils.a

dist/Release/GNU-Linux-x86/xtractorfan: ../plugins/std_cxx_static_example/dist/Release/GNU-Linux-x86/libstd_cxx_static_example.a

dist/Release/GNU-Linux-x86/xtractorfan: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/xtractorfan ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/AppManager.o: AppManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -o ${OBJECTDIR}/AppManager.o AppManager.cpp

${OBJECTDIR}/Dummy.o: Dummy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -o ${OBJECTDIR}/Dummy.o Dummy.cpp

${OBJECTDIR}/xTractorFan.o: xTractorFan.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I.. -o ${OBJECTDIR}/xTractorFan.o xTractorFan.cpp

# Subprojects
.build-subprojects:
	cd ../object_model && ${MAKE}  -f Makefile CONF=Release
	cd ../plugin_framework && ${MAKE}  -f Makefile CONF=Release
	cd ../utils && ${MAKE}  -f Makefile CONF=Release
	cd ../plugins/std_cxx_static_example && ${MAKE}  -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/xtractorfan

# Subprojects
.clean-subprojects:
	cd ../object_model && ${MAKE}  -f Makefile CONF=Release clean
	cd ../plugin_framework && ${MAKE}  -f Makefile CONF=Release clean
	cd ../utils && ${MAKE}  -f Makefile CONF=Release clean
	cd ../plugins/std_cxx_static_example && ${MAKE}  -f Makefile CONF=Release clean
