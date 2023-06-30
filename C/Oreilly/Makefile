CC = CC -Wall -Wshadow -fprofile-arcs -ftest-coverage

cov: coverage.c
	$(CC) coverage.c -o cov
	./cov
	gcov coverage.c
	grep "#" coverage.c.gcov

clean:
	rm -f *.gcov *.gcno cov *.gcda