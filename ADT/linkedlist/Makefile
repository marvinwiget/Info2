C = gcc
CFLAGS = -Wall -g
TARGET = linkedlist_test
all: $(TARGET)

$(TARGET): main.o linkedlist.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o linkedlist.o

main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f *.o $(TARGET)
