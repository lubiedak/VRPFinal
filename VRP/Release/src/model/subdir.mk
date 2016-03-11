################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/Criteria.cpp \
../src/model/Cycle.cpp \
../src/model/Node.cpp \
../src/model/Problem.cpp 

OBJS += \
./src/model/Criteria.o \
./src/model/Cycle.o \
./src/model/Node.o \
./src/model/Problem.o 

CPP_DEPS += \
./src/model/Criteria.d \
./src/model/Cycle.d \
./src/model/Node.d \
./src/model/Problem.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++0x -pthread -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


