CC=cc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -O3 -pipe
LFLAGS=-lcurl
BIN=qpost
OBJS=util.o requests.o main.o

default: all clean
all: $(BIN)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

install:
	cp $(BIN) /usr/bin

uninstall:
	rm /usr/bin/$(BIN)

clean:
	rm -rf *.o *.gch .*~ *~

run:
	./$(BIN)
