PROJ = Queue
CC = gcc
CCFLAGS = -std=c99 -Wall -Werror

$(PROJ)Test: $(PROJ).o $(PROJ)Test.o
	$(CC) $(CCFLAGS) -o $@ $^

$(PROJ).o: $(PROJ).c
	$(CC) $(CCFLAGS) -c -o $@ $^

$(PROJ)Test.o: $(PROJ)Test.c
	$(CC) $(CCFLAGS) -c -o $@ $^

.PHONY: clean

clean:
	rm $(PROJ)Test *.o 
