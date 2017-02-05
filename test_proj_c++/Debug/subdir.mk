################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hello_world.cpp 

OBJS += \
./hello_world.o 

CPP_DEPS += \
./hello_world.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin\lib\gcc\i686-pc-cygwin\4.9.2\include\c++" -I"C:\cygwin\lib\gcc\i686-pc-cygwin\4.9.2\include\c++\i686-pc-cygwin" -I"C:\cygwin\lib\gcc\i686-pc-cygwin\4.9.2\include\c++\backward" -I"C:\cygwin\lib\gcc\i686-pc-cygwin\4.9.2\include" -I"C:\cygwin\lib\gcc\i686-pc-cygwin\4.9.2\include-fixed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


