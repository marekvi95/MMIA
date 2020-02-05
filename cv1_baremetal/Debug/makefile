################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
cv1_baremetal.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
cv1_baremetal.list \

OBJCOPY_BIN += \
cv1_baremetal.bin \


# All Target
all: cv1_baremetal.elf secondary-outputs

# Tool invocations
cv1_baremetal.elf: $(OBJS) $(USER_OBJS) D:\xvitul00\MMIA\cv1_baremetal\STM32F030R8TX_FLASH.ld
	arm-none-eabi-gcc -o "cv1_baremetal.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\xvitul00\MMIA\cv1_baremetal\STM32F030R8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="cv1_baremetal.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

cv1_baremetal.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "cv1_baremetal.list"
	@echo 'Finished building: $@'
	@echo ' '

cv1_baremetal.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "cv1_baremetal.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
