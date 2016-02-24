################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/solver/CycleConnector.cpp \
../src/solver/CycleCreator.cpp \
../src/solver/CyclesSet.cpp \
../src/solver/PermutationGen.cpp \
../src/solver/ProgressLogger.cpp \
../src/solver/Solution.cpp 

OBJS += \
./src/solver/CycleConnector.o \
./src/solver/CycleCreator.o \
./src/solver/CyclesSet.o \
./src/solver/PermutationGen.o \
./src/solver/ProgressLogger.o \
./src/solver/Solution.o 

CPP_DEPS += \
./src/solver/CycleConnector.d \
./src/solver/CycleCreator.d \
./src/solver/CyclesSet.d \
./src/solver/PermutationGen.d \
./src/solver/ProgressLogger.d \
./src/solver/Solution.d 


# Each subdirectory must supply rules for building sources it contributes
src/solver/%.o: ../src/solver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


