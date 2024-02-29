CC		= gcc
CXX		= g++
INC_DIR	= ./core
CFLAGS	= -g -Wall -I$(INC_DIR)
RM		= rm -f
RMDIR	= $(RM) -r


default: all

all: TicTacToe hello

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c

TicTacToe: main.c
	$(CC) $(CFLAGS) -o TicTacToe main.c core/*.c

clean veryclean:
	$(RM) TicTacToe hello
	$(RMDIR) *.dSYM

lint:
	cpplint --recursive .

test:
	$(CXX) -o unittest tests/main.c -I /usr/src/googletest/googletest/include/ -lgtest
	./unittest
