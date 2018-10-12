C_SRCS = $(wildcard *.c)
C_OBJS = $(C_SRCS:.c=.o)
S_SRCS = $(wildcard *.s)
S_OBJS = $(S_SRCS:.s=.o)

OBJS   = $(C_OBJS) $(S_OBJS)

CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all:
	$(MAKE) clean
	$(MAKE) kernel8.img

%.o: %.s
	aarch64-linux-gnu-gcc $(CFLAGS) -c $< -o $@

%.o: %.c
	aarch64-linux-gnu-gcc $(CFLAGS) -c $< -o $@

kernel8.img: start.o $(OBJS)
	aarch64-linux-gnu-ld -nostdlib -nostartfiles $(OBJS) -T link.ld -o kernel8.elf
	aarch64-linux-gnu-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm kernel8.elf *.o >/dev/null 2>/dev/null || true

.PHONY: all clean