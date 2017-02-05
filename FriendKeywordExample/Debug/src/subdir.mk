################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ComplexNumber.cpp \
../src/ComplexNumberPolar.cpp \
../src/FriendKeywordExample.cpp 

OBJS += \
./src/ComplexNumber.o \
./src/ComplexNumberPolar.o \
./src/FriendKeywordExample.o 

CPP_DEPS += \
./src/ComplexNumber.d \
./src/ComplexNumberPolar.d \
./src/FriendKeywordExample.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


