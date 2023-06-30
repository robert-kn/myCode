CC = CC
CFLAGS = -Wall -Wshadow
OBJS = mystring.o main.o
HDRS = mystring.h
VAL = valgrind --tool=memcheck --leak-check=full --verbose --log-file

# the symbol $@ as used below means the symbol before the : on the line above which in this case is mystring
mystring: $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# if an object file is needed compile the corresponding .c file
.c.o:
	$(CC) $(CFLAGS) -c $*.c   

clean:
	/bin/rm -f $(OBJS) ../outputs/* log*

testall: test0 test1 test2 

# the -w flag used with diff will ignore differences caused by spaces.

# grep ERROR *log*

test0: mystring
	$(VAL)=log0 ./mystring strlen ../inputs/text.txt ../outputs/out_len
#	diff ../outputs/out_len ../expected/out_len_expected -w

test1: mystring
	$(VAL)=log1 ./mystring countchar ../inputs/text.txt ../outputs/out_countchar
#	diff ../outputs/out_countchar ../expected/out_char_expected -w

test2: mystring
	$(VAL)=log2 ./mystring strupper ../inputs/text.txt ../outputs/out_strupper
#	diff ../outputs/out_strupper ../expected/out_strupper_expected -w

	