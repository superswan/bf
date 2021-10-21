# -*- Makefile -*-

#target: dependencies
#	action
BUILD_DIR=./bin

all: bf ascii2bf

bf: 
	@mkdir -p bin
	cc bf.c -o $(BUILD_DIR)/bf

ascii2bf:
	@mkdir -p bin
	cc ascii2bf.c -o $(BUILD_DIR)/ascii2bf

bfloader:
	@mkdir -p bin
	gcc  -fno-stack-protector -z execstack -w  bfloader.c -o $(BUILD_DIR)/bfloader -no-pie -m32

clean:
	rm *.bf
	rm -rf bin 