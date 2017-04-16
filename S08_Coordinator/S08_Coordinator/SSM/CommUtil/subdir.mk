################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../SSM/CommUtil/CommUtil.c" \

C_SRCS += \
../SSM/CommUtil/CommUtil.c \

OBJS += \
./SSM/CommUtil/CommUtil_c.obj \

OBJS_QUOTED += \
"./SSM/CommUtil/CommUtil_c.obj" \

C_DEPS += \
./SSM/CommUtil/CommUtil_c.d \

C_DEPS_QUOTED += \
"./SSM/CommUtil/CommUtil_c.d" \

OBJS_OS_FORMAT += \
./SSM/CommUtil/CommUtil_c.obj \


# Each subdirectory must supply rules for building sources it contributes
SSM/CommUtil/CommUtil_c.obj: ../SSM/CommUtil/CommUtil.c | pre-build
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"SSM/CommUtil/CommUtil.args" -ObjN="SSM/CommUtil/CommUtil_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

SSM/CommUtil/%.d: ../SSM/CommUtil/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


