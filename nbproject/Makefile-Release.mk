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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/940413165/action.o \
	${OBJECTDIR}/_ext/940413165/action_is_dir.o \
	${OBJECTDIR}/_ext/940413165/action_is_episode.o \
	${OBJECTDIR}/_ext/940413165/action_is_file.o \
	${OBJECTDIR}/_ext/940413165/action_is_movie.o \
	${OBJECTDIR}/_ext/940413165/action_is_video.o \
	${OBJECTDIR}/_ext/940413165/action_metadata_base.o \
	${OBJECTDIR}/_ext/940413165/action_metadata_tmdb.o \
	${OBJECTDIR}/_ext/940413165/action_mime.o \
	${OBJECTDIR}/_ext/940413165/action_move.o \
	${OBJECTDIR}/_ext/940413165/action_scan_directory.o \
	${OBJECTDIR}/_ext/940413165/basic_tree.o \
	${OBJECTDIR}/_ext/940413165/curl_wrapper.o \
	${OBJECTDIR}/_ext/940413165/engine.o \
	${OBJECTDIR}/_ext/940413165/item.o \
	${OBJECTDIR}/_ext/940413165/metadata.o \
	${OBJECTDIR}/_ext/940413165/metafield.o \
	${OBJECTDIR}/_ext/940413165/metafield_description.o \
	${OBJECTDIR}/_ext/940413165/synchronizer.o \
	${OBJECTDIR}/_ext/940413165/worker.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medange

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medange: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medange ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/940413165/action.o: /home/thomas/development/cpp/medange/action.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action.o /home/thomas/development/cpp/medange/action.cpp

${OBJECTDIR}/_ext/940413165/action_is_dir.o: /home/thomas/development/cpp/medange/action_is_dir.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_is_dir.o /home/thomas/development/cpp/medange/action_is_dir.cpp

${OBJECTDIR}/_ext/940413165/action_is_episode.o: /home/thomas/development/cpp/medange/action_is_episode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_is_episode.o /home/thomas/development/cpp/medange/action_is_episode.cpp

${OBJECTDIR}/_ext/940413165/action_is_file.o: /home/thomas/development/cpp/medange/action_is_file.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_is_file.o /home/thomas/development/cpp/medange/action_is_file.cpp

${OBJECTDIR}/_ext/940413165/action_is_movie.o: /home/thomas/development/cpp/medange/action_is_movie.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_is_movie.o /home/thomas/development/cpp/medange/action_is_movie.cpp

${OBJECTDIR}/_ext/940413165/action_is_video.o: /home/thomas/development/cpp/medange/action_is_video.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_is_video.o /home/thomas/development/cpp/medange/action_is_video.cpp

${OBJECTDIR}/_ext/940413165/action_metadata_base.o: /home/thomas/development/cpp/medange/action_metadata_base.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_metadata_base.o /home/thomas/development/cpp/medange/action_metadata_base.cpp

${OBJECTDIR}/_ext/940413165/action_metadata_tmdb.o: /home/thomas/development/cpp/medange/action_metadata_tmdb.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_metadata_tmdb.o /home/thomas/development/cpp/medange/action_metadata_tmdb.cpp

${OBJECTDIR}/_ext/940413165/action_mime.o: /home/thomas/development/cpp/medange/action_mime.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_mime.o /home/thomas/development/cpp/medange/action_mime.cpp

${OBJECTDIR}/_ext/940413165/action_move.o: /home/thomas/development/cpp/medange/action_move.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_move.o /home/thomas/development/cpp/medange/action_move.cpp

${OBJECTDIR}/_ext/940413165/action_scan_directory.o: /home/thomas/development/cpp/medange/action_scan_directory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/action_scan_directory.o /home/thomas/development/cpp/medange/action_scan_directory.cpp

${OBJECTDIR}/_ext/940413165/basic_tree.o: /home/thomas/development/cpp/medange/basic_tree.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/basic_tree.o /home/thomas/development/cpp/medange/basic_tree.cpp

${OBJECTDIR}/_ext/940413165/curl_wrapper.o: /home/thomas/development/cpp/medange/curl_wrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/curl_wrapper.o /home/thomas/development/cpp/medange/curl_wrapper.cpp

${OBJECTDIR}/_ext/940413165/engine.o: /home/thomas/development/cpp/medange/engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/engine.o /home/thomas/development/cpp/medange/engine.cpp

${OBJECTDIR}/_ext/940413165/item.o: /home/thomas/development/cpp/medange/item.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/item.o /home/thomas/development/cpp/medange/item.cpp

${OBJECTDIR}/_ext/940413165/metadata.o: /home/thomas/development/cpp/medange/metadata.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/metadata.o /home/thomas/development/cpp/medange/metadata.cpp

${OBJECTDIR}/_ext/940413165/metafield.o: /home/thomas/development/cpp/medange/metafield.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/metafield.o /home/thomas/development/cpp/medange/metafield.cpp

${OBJECTDIR}/_ext/940413165/metafield_description.o: /home/thomas/development/cpp/medange/metafield_description.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/metafield_description.o /home/thomas/development/cpp/medange/metafield_description.cpp

${OBJECTDIR}/_ext/940413165/synchronizer.o: /home/thomas/development/cpp/medange/synchronizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/synchronizer.o /home/thomas/development/cpp/medange/synchronizer.cpp

${OBJECTDIR}/_ext/940413165/worker.o: /home/thomas/development/cpp/medange/worker.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/940413165
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/940413165/worker.o /home/thomas/development/cpp/medange/worker.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medange

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
