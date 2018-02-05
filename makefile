#
# makefile
# Makefile for μTest
#

SRC_DIR := src/
TEST_DIR := test/
BUILD_DIR := build/
BUILD_OBJ := build/obj/
PRODUCT_TEST := $(BUILD_DIR)tester
PRODUCT_DOCS := $(BUILD_DIR)docs/
DOX_CONFIG := dox.conf

SRC := $(wildcard $(SRC_DIR)*.c)
SRC_TEST := $(wildcard $(TEST_DIR)*.c)

VPATH := $(VPATH) $(SRC_DIR) $(TEST_DIR)

CFLAGS := -Wall -Werror -I$(SRC_DIR)
COMPILE := gcc $(CFLAGS) -c 
LINK := gcc $(CFLAGS)
DEPEND := gcc $(CFLAGS) -M

.PHONY: docs test clean
.DEFAULT: test

test: $(PRODUCT_TEST)
docs: $(PRODUCT_DOCS)
	
$(PRODUCT_DOCS): $(DOX_CONFIG) $(SRC)
	mkdir -p $@
	doxygen $(DOX_CONFIG)
	
$(PRODUCT_TEST): $(BUILD_OBJ)test.o $(BUILD_OBJ)utest.o
	$(LINK) $^ -o $@

$(BUILD_OBJ)%.o: %.c $(BUILD_OBJ)
	$(COMPILE) $< -o $@
	
$(BUILD_OBJ)%.o: $(SRC_TEST)%.c $(BUILD_OBJ)
	$(COMPILE) $< -o $@

$(BUILD_OBJ):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)%.dep: %.c $(BUILD_DIR)
	$(DEPEND) $< >$@
	
clean:
	rm -rf build

include $(patsubst %.c,$(BUILD_DIR)%.dep,$(notdir $(SRC)))
include $(patsubst %.c,$(BUILD_DIR)%.dep,$(notdir $(SRC_TEST)))
