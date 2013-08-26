TARGET		:=arm
START_OBJ	:=start.o
OBJS		:=main.o ac97.o irq.o 
BIN		:=$(TARGET).bin
ADDR		:=0x50000000

CC		:=arm-none-linux-gnueabi-gcc
AS		:=arm-none-linux-gnueabi-as
LD		:=arm-none-linux-gnueabi-ld
OBJCOPY		:=arm-none-linux-gnueabi-objcopy

#####################################################

all:$(TARGET)
	$(OBJCOPY) -O binary $(TARGET) /tftpboot/$(BIN)

$(TARGET):$(START_OBJ) $(OBJS)
	$(LD) $(START_OBJ) $(OBJS) -o $(TARGET) -T ld.lds

%o:%c
	$(CC) -c -o $@ $<
%o:%s
	$(AS) -o $@ $<


clean:
	rm $(TARGET) $(START_OBJ) $(OBJS) -rf
