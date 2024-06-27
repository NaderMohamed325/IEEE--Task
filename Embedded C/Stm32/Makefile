CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=executable.map

ACH = cortex-m4

main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@

GPIO_Prog.o: GPIO_Prog.c
	@$(CC) $(CFLAGS) $^ -o $@

RCC_Prog.o: RCC_Prog.c
	@$(CC) $(CFLAGS) $^ -o $@

SysTick.o: SysTick_Prog.c
	@$(CC) $(CFLAGS) $^ -o $@

startup.o: startup.c
	@$(CC) $(CFLAGS) $^ -o $@

executable.elf: startup.o main.o GPIO_Prog.o RCC_Prog.o SysTick.o
	@$(CC) $(LDFLAGS) $^ -o $@

all: main.o GPIO_Prog.o RCC_Prog.o SysTick.o startup.o executable.elf

clean:
	@rm -f *.o *elf
