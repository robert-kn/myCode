#include <stdio.h>

int main(){
	int character, countB, countT, countNL;
	
	countB = countT = countNL = 0;

	while((character = getchar()) != EOF){
		if(character == '\n')
			++countNL;
		if(character == '\t')
			++countT;
		if(character == ' ')
			++countB;
	}
	printf("blanks = %d, tabs = %d, newlines = %d\n", countB, countT, countNL);
}
