#include <stdio.h>

int main(){
	int c;

	system("clear");

	while((c = getchar()) != EOF){
		if(c == '\t')
			printf("\\t");
		if(c == '\b')
			printf("\\b");
		if(c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
