C = gcc
CFLAGS = -Wall -g
TARGET = a
all: $(TARGET)

$(TARGET): testing.o stack.o
	$(CC) $(CFLAGS) -o $(TARGET) testing.o stack.o

testing.o: testing.c stack.h
	$(CC) $(CFLAGS) -c testing.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o $(TARGET)
