################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Address.cpp \
../src/ContactBook.cpp \
../src/ContactClassDefine.cpp \
../src/RunBook.cpp 

OBJS += \
./src/Address.o \
./src/ContactBook.o \
./src/ContactClassDefine.o \
./src/RunBook.o 

CPP_DEPS += \
./src/Address.d \
./src/ContactBook.d \
./src/ContactClassDefine.d \
./src/RunBook.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


