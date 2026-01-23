C = gcc
CFLAGS = -Wall -g
TARGET = stack_test
all: $(TARGET)

$(TARGET): main.o stack.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o $(TARGET)
