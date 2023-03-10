# uppercase words represent symbols which can be accessed using $()
CC = cc
CFLAGS = -Wall -Wshadow
OBJSMAIN2 = mysort.o main2.o 
OBJSMAIN1 = mystring.o main1.o 
OBJSPROG = areDistinct.o main.o
HDRS1 = mystring.h 
HDRS2 = mysort.h
VAL = valgrind --tool=memcheck --verbose --leak-check=full --verbose --log-file=

mysort: $(OBJSMAIN2) $(HDRS2)
	$(CC) $(CFLAGS) $(OBJSMAIN2) -o $@

main1: $(OBJSMAIN1) $(HDRS1)
	$(CC) $(CFLAGS) $(OBJSMAIN1) -o $@
# the symbol $@ means the symbol before the : on line 9 

#line 14 means that if an object file is needed, compile the corresponding .c file
.c.o:
	$(CC) $(CFLAGS) -c $*.c

prog: $(OBJSPROG)
	$(CC) $(CFLAGS) $(OBJSPROG) -o $@

testgen: testgen.c
	$(CC) $(CFLAGS) testgen.c -o testgen

test: mysort
	$(VAL)log6 ./mysort 6 < inputs/input6 > outputs/output6_mysort
	diff outputs/output6 outputs/output6_mysort
	$(VAL)log20 ./mysort 20 < inputs/input20 > outputs/output20_mysort
	diff outputs/output20 outputs/output20_mysort
	$(VAL)log50 ./mysort 50 < inputs/input50 > outputs/output50_mysort
	diff outputs/output50 outputs/output50_mysort
	$(VAL)log100 ./mysort 100 < inputs/input100 > outputs/output100_mysort
	diff outputs/output100 outputs/output100_mysort

inputgen: testgen
	./testgen 6 > inputs/input6
	./testgen 20 > inputs/input20
	./testgen 50 > inputs/input50
	./testgen 100 > inputs/input100
	sort -n inputs/input6 > outputs/output6
	sort -n inputs/input20 > outputs/output20
	sort -n inputs/input50 > outputs/output50
	sort -n inputs/input100 > outputs/output100

testall: test0 test1 test2 test3 test4 test5

test0: prog
	./prog inputs/num0.txt > outputs/output0
	$(VAL)log0 ./prog inputs/num0.txt > /dev/null

test1: prog
	./prog inputs/num1.txt > outputs/output1
	$(VAL)log1 ./prog inputs/num1.txt > /dev/null

test2: prog
	./prog inputs/num2.txt > outputs/output2
	$(VAL)log2 ./prog inputs/num2.txt > /dev/null

test3: main1
	$(VAL)log3 ./main1 strlen inputs/text.txt outputs/output_strlen
#	diff -q out_len expected_strlen

test4: main1
	$(VAL)log4 ./main1 countchar inputs/text.txt outputs/out_countchar
#	diff -q output_countchar expected_countchar

test5: main1
	$(VAL)log5 ./main1 strupper inputs/text.txt outputs/out_upper
#	diff -q out_upper expected_strupper

clean:
	/bin/rm -f *.o prog outputs/* log* $(OBJSMAIN1) $(OBJSPROG) main1 testgen