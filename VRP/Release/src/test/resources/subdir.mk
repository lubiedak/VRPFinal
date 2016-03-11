################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/resources/ProblemsForTest.cpp 

OBJS += \
./src/test/resources/ProblemsForTest.o 

CPP_DEPS += \
./src/test/resources/ProblemsForTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/resources/%.o: ../src/test/resources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++0x -pthread -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


