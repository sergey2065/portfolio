# makefile 

TARGET = testList.out
CC = gcc
CFLAGS = -ansi -g -pedantic -Wall -Werror 
SRCS = ../source/doubleLinkedList.c test_linked_list.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) $(OBJS)
