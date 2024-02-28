CC		= gcc
CFLAGS	= -g
RM		= rm -f


default: all

all: TicTacToe hello

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c

TicTacToe: main.c
	$(CC) $(CFLAGS) -o TicTacToe main.c

clean veryclean:
	$(RM) TicTacToe hello