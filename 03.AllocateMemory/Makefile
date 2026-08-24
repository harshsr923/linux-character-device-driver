# Module name
MODULE_NAME := scull

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

SRC_DIR := src
INC_DIR := include
OBJ_DIR := object
BUILD_DIR := build

# Automatically find all C source files
SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ := $(patsubst $(SRC_DIR)/%.c,$(SRC_DIR)/%.o,$(SRC))

obj-m += $(MODULE_NAME).o

$(MODULE_NAME)-objs := $(OBJ)

ccflags-y := -I$(PWD)/$(INC_DIR)

.PHONY: all install uninstall clean

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	@mkdir -p $(OBJ_DIR) $(BUILD_DIR)
	@mv -f $(SRC_DIR)/*.o $(OBJ_DIR)/ 2>/dev/null || true
	@mv -f $(MODULE_NAME).ko $(BUILD_DIR)/ 2>/dev/null || true
	@rm -f $(MODULE_NAME).mod $(MODULE_NAME).mod.c Module.symvers modules.order
	@rm -f $(SRC_DIR)/.*.cmd $(SRC_DIR)/*.mod $(SRC_DIR)/.*.d

install: all
	sudo insmod $(BUILD_DIR)/$(MODULE_NAME).ko

uninstall:
	sudo rmmod $(MODULE_NAME)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -rf $(OBJ_DIR) $(BUILD_DIR)
	@rm -f $(SRC_DIR)/*.o
	@rm -f $(SRC_DIR)/.*.cmd $(SRC_DIR)/*.mod $(SRC_DIR)/.*.d
	@rm -f $(MODULE_NAME).ko $(MODULE_NAME).mod.c
	@rm -f Module.symvers modules.order
