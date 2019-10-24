CC	:= g++

TARGET	:= calc

SRC	:= main.cpp
SRC	+= operand.cpp
SRC	+= operation.cpp

FLAGS := -lgmp

all: $(SRC)
	@echo BUILDING...
	@$(CC) -o $(TARGET) $(SRC) $(FLAGS)
	@echo DONE
