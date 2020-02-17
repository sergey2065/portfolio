# makefile 

TARGET = test_vector.out
CC = gcc
CFLAGS = -ansi -g -pedantic -Wall -Werror -I ../include/
SRCS = test_vector.c ../source/vector.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) $(OBJS)
