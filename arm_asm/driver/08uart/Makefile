TARGET		:=arm
START_OBJ	:=start.o
OBJS		:=main.o clock.o uart.o
BIN		:=$(TARGET).bin
ADDR		:=0x00000000

CC		:=arm-none-linux-gnueabi-gcc
AS		:=arm-none-linux-gnueabi-as
LD		:=arm-none-linux-gnueabi-ld
OBJCOPY		:=arm-none-linux-gnueabi-objcopy

###################################################################

all:$(TARGET)
	$(OBJCOPY) -O binary $(TARGET) /tftpboot/$(BIN)
	rm $(START_OBJ) $(OBJS) $(TARGET) -rf
$(TARGET):$(START_OBJ) $(OBJS)
	$(LD) $(START_OBJ) $(OBJS) -o $(TARGET) -Ttext $(ADDR)
%o:%c
	$(CC) -c -o $@ $<
%o:%s
	$(AS) -o $@ $<
%o:%S
	$(AS) -o $@ $<
