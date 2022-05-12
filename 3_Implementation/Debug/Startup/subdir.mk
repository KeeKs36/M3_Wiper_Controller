################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f407vgtx.s 

C_SRCS += \
../Startup/Startup_c.c 

OBJS += \
./Startup/Startup_c.o \
./Startup/startup_stm32f407vgtx.o 

S_DEPS += \
./Startup/startup_stm32f407vgtx.d 

C_DEPS += \
./Startup/Startup_c.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o Startup/%.su: ../Startup/%.c Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/Startup_c.d ./Startup/Startup_c.o ./Startup/Startup_c.su ./Startup/startup_stm32f407vgtx.d ./Startup/startup_stm32f407vgtx.o

.PHONY: clean-Startup

