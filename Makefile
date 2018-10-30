C_SRCS = $(wildcard *.c)
C_OBJS = $(C_SRCS:.c=.o)
S_SRCS = $(wildcard *.s)
S_OBJS = $(S_SRCS:.s=.o)

OBJS   = $(C_OBJS) $(S_OBJS)

CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

DATE = $(shell date '+%Y-%m-%d_%H:%M:%S')

all:
	$(MAKE) clean
	$(MAKE) build_date
	$(MAKE) kernel8.img

build_date:
	echo '#pragma once\n\n#define BUILD_DATE "${DATE}"' > build_date.h

%.o: %.s
	aarch64-none-elf-gcc $(CFLAGS) -c $< -o $@

%.o: %.c
	aarch64-none-elf-gcc $(CFLAGS) -c $< -o $@

kernel8.img: $(OBJS)
	aarch64-none-elf-ld -nostdlib -nostartfiles $(OBJS) -T link.ld -o kernel8.elf
	aarch64-none-elf-objdump kernel8.elf -D > kernel8.txt
	aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm kernel8.elf build_date.h *.o >/dev/null 2>/dev/null || true

.PHONY: all clean build_date