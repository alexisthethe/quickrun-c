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
	$(RM) TicTacToe hello *.o
	$(RMDIR) *.dSYM
	$(RM) *.gcda *.gcno

lint:
	cpplint --recursive .

test:
	$(CXX) --coverage -O0 -o unittest.o tests/main.c core/*.c -I /usr/src/googletest/googletest/include/ -I$(INC_DIR) -lgtest
	./unittest.o
