#@copyright : Eng. Hossam Diab
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c )
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s )
AsOBJ = $(As:.s=.o)
Project_Name=UART_BUFFER


all:$(Project_Name).bin
	@echo "<<<<<<<<<<<<<Build is Done>>>>>>>>>>>>>>"

startup.o: startup.s
	$(CC)as.exe  $(INCS) $(CFLAGS) $< -o $@	

%.o: %.c 	
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=MAP_FILE.map

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.bin *.elf *.o
	@echo "<<<<<<<<<<<<<Delete Done>>>>>>>>>>>>>>"

clean:
	rm *.bin *.elf 
