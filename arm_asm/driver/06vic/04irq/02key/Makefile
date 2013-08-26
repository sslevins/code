TARGET		:=arm
START_OBJ	:=start.o
OBJS		:=main.o irq.o
BIN		:=$(TARGET).bin
ADDR		:=0x00000000

CC		:=arm-linux-gcc
AS		:=arm-linux-as
LD		:=arm-linux-ld
OBJCOPY		:=arm-linux-objcopy

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
