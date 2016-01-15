################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/input/ArgParser.cpp \
../src/input/FileDirChecker.cpp 

OBJS += \
./src/input/ArgParser.o \
./src/input/FileDirChecker.o 

CPP_DEPS += \
./src/input/ArgParser.d \
./src/input/FileDirChecker.d 


# Each subdirectory must supply rules for building sources it contributes
src/input/%.o: ../src/input/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


