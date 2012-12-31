################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../id1.cpp \
../id10.cpp \
../id11.cpp \
../id12.cpp \
../id13.cpp \
../id14.cpp \
../id16.cpp \
../id17.cpp \
../id18.cpp \
../id2.cpp \
../id21.cpp \
../id22.cpp \
../id3.cpp \
../id4.cpp \
../id5.cpp \
../id7.cpp \
../id8.cpp \
../id9.cpp 

OBJS += \
./id1.o \
./id10.o \
./id11.o \
./id12.o \
./id13.o \
./id14.o \
./id16.o \
./id17.o \
./id18.o \
./id2.o \
./id21.o \
./id22.o \
./id3.o \
./id4.o \
./id5.o \
./id7.o \
./id8.o \
./id9.o 

CPP_DEPS += \
./id1.d \
./id10.d \
./id11.d \
./id12.d \
./id13.d \
./id14.d \
./id16.d \
./id17.d \
./id18.d \
./id2.d \
./id21.d \
./id22.d \
./id3.d \
./id4.d \
./id5.d \
./id7.d \
./id8.d \
./id9.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


