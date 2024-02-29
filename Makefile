CC		= gcc
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
	echo "unittest TODO"