.POSIX:

CFLAGS = -std=c99 -pedantic -Wall -Wextra

TESTS = test_intrep
all : $(TESTS)

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o

test_intrep : test_intrep.c intrep.o

intrep.o : intrep.c intrep.h
