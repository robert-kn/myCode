#include <stdio.h>

int main(){
	long count;

	count = 0;
	// when run, it appears that this program counts an empty space as a character in addition to the char that is entered on  
	// stdin
	while(getchar() != EOF){
		count = count + 1;
	}
	printf("%ld\n",count);

	return 0;
}
