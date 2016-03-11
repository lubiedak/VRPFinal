################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/io/ArgParser.cpp \
../src/io/FileDirChecker.cpp \
../src/io/ProblemLoader.cpp 

OBJS += \
./src/io/ArgParser.o \
./src/io/FileDirChecker.o \
./src/io/ProblemLoader.o 

CPP_DEPS += \
./src/io/ArgParser.d \
./src/io/FileDirChecker.d \
./src/io/ProblemLoader.d 


# Each subdirectory must supply rules for building sources it contributes
src/io/%.o: ../src/io/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


