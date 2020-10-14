################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/PES_ASSIGNMENT4_1.c \
../source/State_machine.c \
../source/Timer.c \
../source/Touch.c \
../source/mtb.c \
../source/pwm.c \
../source/semihost_hardfault.c 

OBJS += \
./source/PES_ASSIGNMENT4_1.o \
./source/State_machine.o \
./source/Timer.o \
./source/Touch.o \
./source/mtb.o \
./source/pwm.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/PES_ASSIGNMENT4_1.d \
./source/State_machine.d \
./source/Timer.d \
./source/Touch.d \
./source/mtb.d \
./source/pwm.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\board" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\source" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\drivers" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\CMSIS" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\utilities" -I"D:\MCUXpressoIDE_11.2.0_4120\PES_ASSIGNMENT4_1\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


