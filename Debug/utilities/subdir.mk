################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_debug_console.c 

OBJS += \
./utilities/fsl_debug_console.o 

C_DEPS += \
./utilities/fsl_debug_console.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\board" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\source" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\startup" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\CMSIS" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\drivers" -I"C:\Users\user\Documents\MCUXpressoIDE_11.3.1_5262\workspace\Piano\utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


