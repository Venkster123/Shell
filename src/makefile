CC	:= gcc

TARGET	:= shell

SRC	:= shell.c
SRC	+= list.c
SRC	+= file.c
SRC	+= dir.c

FLAGS := -lncurses

all: $(SRC)
	@echo BUILDING...
	@$(CC) -o $(TARGET) $(SRC) $(FLAGS)
	@echo DONE
