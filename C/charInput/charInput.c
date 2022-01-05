#include <stdio.h>

int main(){
	int c;

	c = getchar(); // retrieves the char from stdin
	while(c = getchar() != EOF){ // EOF is an integer defined in stdio.h. Additionally, the precendence of != is higher than =
		printf("%d\n",c);
	}
	printf("%d at EOF\n",c);
}
