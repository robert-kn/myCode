CC = CC
CFLAGS = -Wall -Wshadow
VALGRIND = valgrind --tool=memcheck --verbose --log-file

prog: areDistinct.o main.o
	$(CC) $(CFLAGS) areDistinct.o main.o -o prog

areDistinct.o: areDistinct.c
	$(CC) $(CFLAGS) -c areDistinct.c  

main.o: main.c
	$(CC) $(CFLAGS) -c main.c  

clean:
	/bin/rm -f *.o prog ../outputs/* log*

testall: test0 test1 test2 

# the -w flag used with diff will ignore differences caused by spaces.

# grep ERROR *log*

test0: prog
	./prog ../inputs/duplicates.txt > ../outputs/dupsOut.txt
	diff ../expected/expected0 ../outputs/dupsOut.txt -w
	$(VALGRIND)=log0 ./prog ../inputs/duplicates.txt > /dev/null

test1: prog
	./prog ../inputs/empty.txt > ../outputs/empty.txt
	diff ../expected/expected1 ../outputs/empty.txt -w
	$(VALGRIND)=log1 ./prog ../inputs/empty.txt > /dev/null

test2: prog
	./prog ../inputs/uniqNums.txt > ../outputs/uniqNums.txt
	diff ../expected/expected2 ../outputs/uniqNums.txt -w
	$(VALGRIND)=log2 ./prog ../inputs/uniqNums.txt > /dev/null