#include <stdio.h>
#include <ctype.h>


unsigned int htoi(char s[]);

int main(void)
{
	printf("\n%d\n", htoi("0X999"));
	
	return 0;
}

unsigned int htoi(char s[])
{
	unsigned int i, n = 0;
	
	if (tolower(s[1]) == 'x')
		i = 2;
	else i = 0;
	
	for(; isdigit(s[i]) || (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'); ++i)
		if (isdigit(s[i]))
			n = n*16 + s[i] - '0';
		else n = n*16 + tolower(s[i]) + 10 - 'a';
	
	return n;
}
