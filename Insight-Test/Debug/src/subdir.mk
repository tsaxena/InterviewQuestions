################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Insight-Test.cpp \
../src/card.cpp \
../src/dealer.cpp \
../src/deck.cpp \
../src/game.cpp \
../src/generic-player.cpp \
../src/hand.cpp \
../src/player.cpp 

OBJS += \
./src/Insight-Test.o \
./src/card.o \
./src/dealer.o \
./src/deck.o \
./src/game.o \
./src/generic-player.o \
./src/hand.o \
./src/player.o 

CPP_DEPS += \
./src/Insight-Test.d \
./src/card.d \
./src/dealer.d \
./src/deck.d \
./src/game.d \
./src/generic-player.d \
./src/hand.d \
./src/player.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


