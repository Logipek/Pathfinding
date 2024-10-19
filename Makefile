CC = gcc
CFLAGS = -Wall -g -lm
TARGET = pathfinding
SRCS = main.c library.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) && ./$(TARGET)

clean:
	rm -f $(TARGET)

re: clean all