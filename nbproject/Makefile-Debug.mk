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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/StandardGravityBehaviour.o \
	${OBJECTDIR}/Physics.o \
	${OBJECTDIR}/InGame.o \
	${OBJECTDIR}/App.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/TimeBehaviour.o \
	${OBJECTDIR}/StandardPhysics.o \
	${OBJECTDIR}/StandardMagnetismBehaviour.o \
	${OBJECTDIR}/LevelObject.o \
	${OBJECTDIR}/GameState.o \
	${OBJECTDIR}/Running.o \
	${OBJECTDIR}/Vector2D.o \
	${OBJECTDIR}/CollisionHandler.o \
	${OBJECTDIR}/Pause.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/PhysicsApplyableObject.o \
	${OBJECTDIR}/Options.o \
	${OBJECTDIR}/StandardTimeBehaviour.o \
	${OBJECTDIR}/Level.o \
	${OBJECTDIR}/ForceBehaviour.o \
	${OBJECTDIR}/PlayerObject.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/magbounce

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/magbounce: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/magbounce ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/StandardGravityBehaviour.o: StandardGravityBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/StandardGravityBehaviour.o StandardGravityBehaviour.cpp

${OBJECTDIR}/Physics.o: Physics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Physics.o Physics.cpp

${OBJECTDIR}/InGame.o: InGame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/InGame.o InGame.cpp

${OBJECTDIR}/App.o: App.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/App.o App.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/TimeBehaviour.o: TimeBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/TimeBehaviour.o TimeBehaviour.cpp

${OBJECTDIR}/StandardPhysics.o: StandardPhysics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/StandardPhysics.o StandardPhysics.cpp

${OBJECTDIR}/StandardMagnetismBehaviour.o: StandardMagnetismBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/StandardMagnetismBehaviour.o StandardMagnetismBehaviour.cpp

${OBJECTDIR}/LevelObject.o: LevelObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LevelObject.o LevelObject.cpp

${OBJECTDIR}/GameState.o: GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameState.o GameState.cpp

${OBJECTDIR}/Running.o: Running.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Running.o Running.cpp

${OBJECTDIR}/Vector2D.o: Vector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vector2D.o Vector2D.cpp

${OBJECTDIR}/CollisionHandler.o: CollisionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CollisionHandler.o CollisionHandler.cpp

${OBJECTDIR}/Pause.o: Pause.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Pause.o Pause.cpp

${OBJECTDIR}/Menu.o: Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/PhysicsApplyableObject.o: PhysicsApplyableObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PhysicsApplyableObject.o PhysicsApplyableObject.cpp

${OBJECTDIR}/Options.o: Options.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Options.o Options.cpp

${OBJECTDIR}/StandardTimeBehaviour.o: StandardTimeBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/StandardTimeBehaviour.o StandardTimeBehaviour.cpp

${OBJECTDIR}/Level.o: Level.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Level.o Level.cpp

${OBJECTDIR}/ForceBehaviour.o: ForceBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ForceBehaviour.o ForceBehaviour.cpp

${OBJECTDIR}/PlayerObject.o: PlayerObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PlayerObject.o PlayerObject.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/magbounce

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
