#include <stdio.h>

int main(){
	int c;

	while((c = getchar()) != EOF){
		if(c == '\t')
			printf("\\t\n");
		if(c == '\b')
			printf("\\b\n");
		if(c == '\\')
			printf("\\\\ \n");
	}
}
