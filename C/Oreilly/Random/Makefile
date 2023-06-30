CC = gcc
CFLAGS = -Wall -Wshadow -Wextra 
OBJS = mysort.o main.o
HDRS = mysort.h

mysort: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

randomGen: randomGen.c
	$(CC) $(CFLAGS) randomGen.c -o randomGen

test: mysort
	./mysort 6   < ../inputs/input6   > output6
	diff output6    ../expected/expected6
	./mysort 20  < ../inputs/input20  > output20
	diff output20   ../expected/expected20
	./mysort 50  < ../inputs/input50  > output50
	diff output50   ../expected/expected50
	./mysort 100 < ../inputs/input100 > output100	
	diff output100  ../expected/expected100

inputgen: randomGen
	 ./randomGen 6   > ../inputs/input6
	 ./randomGen 20  > ../inputs/input20
	 ./randomGen 50  > ../inputs/input50
	 ./randomGen 100 > ../inputs/input100
	 sort -n ../inputs/input6 > ../expected/expected6
	 sort -n ../inputs/input20 > ../expected/expected20
	 sort -n ../inputs/input50 > ../expected/expected50
	 sort -n ../inputs/input100 > ../expected/expected100