################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/Cycle_test.cpp \
../src/test/ProblemTest.cpp \
../src/test/RandomProblemGenerator.cpp \
../src/test/Tester.cpp 

OBJS += \
./src/test/Cycle_test.o \
./src/test/ProblemTest.o \
./src/test/RandomProblemGenerator.o \
./src/test/Tester.o 

CPP_DEPS += \
./src/test/Cycle_test.d \
./src/test/ProblemTest.d \
./src/test/RandomProblemGenerator.d \
./src/test/Tester.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/%.o: ../src/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


