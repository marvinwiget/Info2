C = gcc
CFLAGS = -Wall -g
TARGET = queue_test
all: $(TARGET)

$(TARGET): main.o queue.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

stack.o: queue.c queue.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o $(TARGET)
