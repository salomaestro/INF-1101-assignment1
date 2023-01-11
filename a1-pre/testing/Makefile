CC=gcc
CFLAGS=-I .
DEPS = main.h
OBJ = main.o

SRC=main.c
SRC:=$(patsubst %.c,./%.c, $(SRC))

%.o: %.c $(DEPS)
	$(CC) -c -p $@ $< $(CFLAGS)

run:
	./main
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -f $(OBJ)