CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=executable.map

ACH = cortex-m3

main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@

lcd.o: lcd.c
	@$(CC) $(CFLAGS) $^ -o $@

Stm32_F103C6_GPIO.o: Stm32_F103C6_GPIO.c
	@$(CC) $(CFLAGS) $^ -o $@

startup.o: startup.c
	@$(CC) $(CFLAGS) $^ -o $@



executable.elf: startup.o main.o Stm32_F103C6_GPIO.o lcd.o
	@$(CC) $(LDFLAGS) $^ -o $@


all: startup.o main.o Stm32_F103C6_GPIO.o lcd.o  executable.elf

clean:
	@rm -f *.o *.elf *.map
