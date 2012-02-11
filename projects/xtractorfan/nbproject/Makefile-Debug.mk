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
OBJECTDIR=build/Debug/GNU-Linux-x86

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
LDLIBSOPTIONS=-lapr-1 -laprutil-1 -ldl -lapr-1 -laprutil-1 ../object_model/dist/Debug/GNU-Linux-x86/libobject_model.a ../plugin_framework/dist/Debug/GNU-Linux-x86/libplugin_framework.a ../utils/dist/Debug/GNU-Linux-x86/libutils.a ../portability/dist/Debug/GNU-Linux-x86/libportability.a ../plugins/std_cxx_static_example_plugin/dist/Debug/GNU-Linux-x86/libstd_cxx_static_example_plugin.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/xtractorfan

dist/Debug/GNU-Linux-x86/xtractorfan: ../object_model/dist/Debug/GNU-Linux-x86/libobject_model.a

dist/Debug/GNU-Linux-x86/xtractorfan: ../plugin_framework/dist/Debug/GNU-Linux-x86/libplugin_framework.a

dist/Debug/GNU-Linux-x86/xtractorfan: ../utils/dist/Debug/GNU-Linux-x86/libutils.a

dist/Debug/GNU-Linux-x86/xtractorfan: ../portability/dist/Debug/GNU-Linux-x86/libportability.a

dist/Debug/GNU-Linux-x86/xtractorfan: ../plugins/std_cxx_static_example_plugin/dist/Debug/GNU-Linux-x86/libstd_cxx_static_example_plugin.a

dist/Debug/GNU-Linux-x86/xtractorfan: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o dist/Debug/GNU-Linux-x86/xtractorfan ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/AppManager.o: AppManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I.. -I. -o ${OBJECTDIR}/AppManager.o AppManager.cpp

${OBJECTDIR}/Dummy.o: Dummy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I.. -I. -o ${OBJECTDIR}/Dummy.o Dummy.cpp

${OBJECTDIR}/xTractorFan.o: xTractorFan.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -I.. -I. -o ${OBJECTDIR}/xTractorFan.o xTractorFan.cpp

# Subprojects
.build-subprojects:
	cd ../object_model && ${MAKE}  -f Makefile CONF=Debug
	cd ../plugin_framework && ${MAKE}  -f Makefile CONF=Debug
	cd ../utils && ${MAKE}  -f Makefile CONF=Debug
	cd ../portability && ${MAKE}  -f Makefile CONF=Debug
	cd ../plugins/std_cxx_static_example_plugin && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/xtractorfan

# Subprojects
.clean-subprojects:
	cd ../object_model && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../plugin_framework && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../utils && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../portability && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../plugins/std_cxx_static_example_plugin && ${MAKE}  -f Makefile CONF=Debug clean
