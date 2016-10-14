################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Deck.cpp \
../src/GoFish.cpp \
../src/GoFishGame.cpp \
../src/Hand.cpp \
../src/LinkedList.cpp \
../src/Node.cpp \
../src/Player.cpp \
../src/Stack.cpp \
../src/card.cpp 

OBJS += \
./src/Deck.o \
./src/GoFish.o \
./src/GoFishGame.o \
./src/Hand.o \
./src/LinkedList.o \
./src/Node.o \
./src/Player.o \
./src/Stack.o \
./src/card.o 

CPP_DEPS += \
./src/Deck.d \
./src/GoFish.d \
./src/GoFishGame.d \
./src/Hand.d \
./src/LinkedList.d \
./src/Node.d \
./src/Player.d \
./src/Stack.d \
./src/card.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


