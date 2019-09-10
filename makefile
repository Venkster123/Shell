CC	:= gcc

TARGET	:= shell

SRC	:= main.c
SRC 	+= file.c
SRC 	+= dir.c
SRC	+= misc.c
SRC	+= parser.c


all: $(SRC)
	@echo BUILDING...
	@$(CC) -o $(TARGET) $(SRC)
	@echo DONE
