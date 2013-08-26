TARGET		:=bootloader
START_OBJ	:=start.o
OBJS		:=boot.o clock.o ddr.o nand.o led.o string.o main.o uart.o 
BIN		:=$(TARGET).bin
ADDR		:=0x57000000

CC		:=arm-linux-gcc
AS		:=arm-linux-as
LD		:=arm-linux-ld
OBJCOPY		:=arm-linux-objcopy

#####################################################

all:$(TARGET)
	$(OBJCOPY) -O binary $(TARGET) /tftpboot/$(BIN)

$(TARGET):$(START_OBJ) $(OBJS)
	$(LD) $(START_OBJ) $(OBJS) -o $(TARGET) -Ttext $(ADDR) 

%o:%c
	$(CC) -c -o $@ $<
%o:%s
	$(AS) -o $@ $<


clean:
	rm $(TARGET) $(START_OBJ) $(OBJS) -rf
