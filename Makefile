
CC=gcc
CFLAGS=-O2 -std=c11 -Wall -Wextra -Wshadow

INC= -Iinclude

SRC=\
src/coin_change.c \
src/fractional_knapsack.c \
src/utils.c \
src/main.c

OBJ=$(SRC:.c=.o)

all: optimization_demo

optimization_demo: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) optimization_demo
