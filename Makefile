#-------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error Please set DEVKITARM in your environment. export DEVKITARM=/path/to/devkitARM)
endif

include $(DEVKITARM)/base_tools

#-------------------------------------------------------------------------------

ifeq ($(strip $(ROM_CODE)),)
ROM_CODE := BPRE
endif

export BUILD := build/$(ROM_CODE)
export GAME := $(BUILD)/rom.gba
export SRC := src
export RESOURCES := resources
export RELOCATABLE := $(BUILD)/linked.o

export ARMIPS ?= armips
export LD := $(PREFIX)ld

export ASFLAGS := -mthumb
	
export INCLUDES := -I $(SRC) -I pokeagb/build/include
export WARNINGFLAGS :=	-Wall -Wno-discarded-array-qualifiers \
	-Wno-int-conversion
export CFLAGS := -mthumb -mno-thumb-interwork -mcpu=arm7tdmi -mtune=arm7tdmi \
	-march=armv4t -mlong-calls -fno-builtin $(WARNINGFLAGS) $(INCLUDES) \
	-O -finline 
	
LD_FILES := linker.ld  $(ROM_CODE).ld  pokeagb/build/linker/$(ROM_CODE).ld
export LDFLAGS := -r $(foreach f,$(LD_FILES),-T $f)

#-------------------------------------------------------------------------------
	
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))


# Generated
IMAGES=$(call rwildcard,images,*.png)

# Sources
HEADERS := $(call rwildcard,$(SRC),*.h)
C_SRC := $(call rwildcard,$(SRC),*.c)
S_SRC := $(call rwildcard,$(SRC),*.s)
OTHER_SRC := $(call rwildcard,$(RESOURCES),*.s)

# Binaries
C_OBJ := $(C_SRC:%=$(BUILD)/%.o)
S_OBJ := $(S_SRC:%=$(BUILD)/%.o)
OTHER_OBJ := $(OTHER_SRC:%=$(BUILD)/%.o)

ALL_OBJ := $(C_OBJ) $(S_OBJ) $(OTHER_OBJ)

#-------------------------------------------------------------------------------

.PHONY: all clean

all: main.s $(RELOCATABLE)
	@echo -e "Creating ROM"
	$(ARMIPS) main.s -sym offsets.txt -strequ input_game $(ROM_CODE).gba -strequ relocatable_obj $(RELOCATABLE) -strequ output_game $(GAME) -equ rom_code $(ROM_CODE)

clean:
	rm -rf build

$(RELOCATABLE): $(ALL_OBJ) $(LD_FILES)
	@echo -e "Linking ELF binary $@"
	@$(LD) $(LDFLAGS) -o $@ $(ALL_OBJ)

$(BUILD)/%.c.o: %.c $(HEADERS)
	@echo -e "Compiling $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BUILD)/%.s.o: %.s $(HEADERS)
	@echo -e "Assembling $<"
	@mkdir -p $(@D)
	@$(AS) $(ASFLAGS) -o $@ $< 
	
	
	
