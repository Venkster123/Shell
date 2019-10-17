CC	:= gcc

TARGET	:= shell

SRC	:= main.c
SRC	+= list.c
SRC	+= file.c
SRC	+= dir.c
SRC	+= parser.c
SRC	+= window.c

FLAGS := -lncurses

all: $(SRC)
	@echo BUILDING...
	@$(CC) -o $(TARGET) $(SRC) $(FLAGS)
	@echo DONE
