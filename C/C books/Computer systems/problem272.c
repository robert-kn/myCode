// You are given the task of writing a function that will copy an integer val into a buffer buf, but it should do so only if enough space is available in the buffer. Here is the code you write:

/* Copy integer into buffer if space is available */
/* WARNING: The following code is buggy */
void copy_int(int val, void *buf, int maxbytes) {
	if (maxbytes-sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
}

// This code makes use of the library function memcpy. Although its use is a bit artificial here, where we simply want to copy an int, it illustrates an approach commonly used to copy larger data structures.
// You carefully test the code and discover that it always copies the value to the buffer, even when maxbytes is too small.

// A. Explain why the conditional test in the code always succeeds. Hint: The sizeof operator returns a value of type size_t.

// because sizeof(val) has type size_t, which is an unsigned type hence expression within the if conditional wraps around to a very large unsigned number when maxbytes-sizeof(val) is -ve. this means that the expression is always true i.e. yields 1

// B. Show how you can rewrite the conditional test to make it work properly.

void copy_int(int val, void *buf, int maxbytes) {
	if (maxbytes >= sizeof(val))
		memcpy(buf, (void *) &val, sizeof(val));
}