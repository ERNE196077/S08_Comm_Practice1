################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 41
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include SSM/ZTC/Source/subdir.mk
-include SSM/TS/Source/subdir.mk
-include SSM/CommUtil/subdir.mk
-include PLM/Source/UART/subdir.mk
-include PLM/Source/Touchpad/subdir.mk
-include PLM/Source/TempSensor/subdir.mk
-include PLM/Source/TMR/subdir.mk
-include PLM/Source/Sound/subdir.mk
-include PLM/Source/SPI/subdir.mk
-include PLM/Source/RST/subdir.mk
-include PLM/Source/NVM/subdir.mk
-include PLM/Source/Led/subdir.mk
-include PLM/Source/LPM/subdir.mk
-include PLM/Source/Keyboard/subdir.mk
-include PLM/Source/IIC/subdir.mk
-include PLM/Source/FunctionLib/subdir.mk
-include PLM/Source/Display/subdir.mk
-include PLM/Source/Common/Sys/subdir.mk
-include PLM/Source/CMT/subdir.mk
-include PLM/Source/Accelerometer/subdir.mk
-include MacPhy/Phy/MC1323X/subdir.mk
-include Application/Source/subdir.mk
-include Application/Init/subdir.mk
-include Application/Configure/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
S08_Coordinator.abs \

EXECUTABLES_QUOTED += \
"S08_Coordinator.abs" \

EXECUTABLES_OS_FORMAT += \
S08_Coordinator.abs \

BURNER_OUTPUT_OUTPUTS += \
S08_Coordinator.abs.s19 \

BURNER_OUTPUT_OUTPUTS_QUOTED += \
"S08_Coordinator.abs.s19" \

BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
S08_Coordinator.abs.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: pre-build main-build

# Main-build Target
main-build: S08_Coordinator.abs S08_Coordinator.abs.s19
else
all: pre-build main-build

# Main-build Target
main-build: S08_Coordinator.abs
endif

# Tool invocations
S08_Coordinator.abs: $(OBJS) $(USER_OBJS) pre.prm | pre-build
	@echo 'Building target: $@'
	@echo 'Executing target #42 $@'
	@echo 'Invoking: Linker'
	"$(HC08ToolsEnv)/linker" -ArgFile"S08_Coordinator.args" -O"S08_Coordinator.abs"
	@echo 'Finished building target: $@'
	@echo ' '

S08_Coordinator.abs.s19: $(BBL_SRCS) $(EXECUTABLES) | pre-build
	@echo 'Executing target #43 $@'
	@echo 'Invoking: Burner'
	"$(HC08ToolsEnv)/burner" -ArgFile"S08_Coordinator.abs.args" -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) "./*/*/*.obj" "./*/*/*/*.obj" "./*/*/*/*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(S_UPPER_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(BURNER_OUTPUT_OUTPUTS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*.d" "./*/*/*/*.d" "./*/*/*/*/*.d"  $(ProjDirPath)/S08_Coordinator/S08_Coordinator.abs $(ProjDirPath)/S08_Coordinator/S08_Coordinator.abs.args $(ProjDirPath)/S08_Coordinator/S08_Coordinator.args $(ProjDirPath)/S08_Coordinator/S08_Coordinator.map $(ProjDirPath)/S08_Coordinator/S08_Coordinator.s19
	-@echo ' '

pre-build:
	-@echo 'Precompile the .prm file'
	-"C:\Freescale\CW MCU v10.7\eclipse\../MCU/prog/chc08.exe" -ArgFile"PLM\Source\Common\Sys\crt0.args" "C:/Users/ernesto/Documents/Workspace/S08_Coordinator/S08_Coordinator\PLM\PRM\Linker_MC13234C_far_banked.prm" -LpX -Lp=pre.prm
	-@echo ' '

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: pre.prm 

# Additional tool dependencies as separate targets to avoid errors while using parallel builds when pre-build steps are generating those dependencies.
pre.prm:
	

warning-messages: 

