all: project1

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

project1: project1.o
	cc -o $@ $^

project1.o: project1.c
	cc -c $(CFLAGS) project1.c


clean:
	rm -f *.o project1


