################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
drivers/ili9341_240x320x262K.obj: ../drivers/ili9341_240x320x262K.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --include_path="C:/ti/TivaWare" --define=ccs="ccs" --define=PART_TM4C123GH6PGE --define=TARGET_IS_BLIZZARD_RA1 --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/ili9341_240x320x262K.pp" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


