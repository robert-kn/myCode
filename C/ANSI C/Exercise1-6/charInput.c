#include <stdio.h>

int main(){
	int c;

	c = getchar(); 

	while(c = getchar() != EOF){
		printf("%d\n",c);
	}
	printf("%d at EOF\n",c);
}
