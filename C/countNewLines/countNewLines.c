#include <stdio.h>

int main(){
	int character, count;

	count = 0;

	while((character = getchar()) != EOF){
		if(character == '\n')
			++count;
	}
	printf("%d\n", count);
}
