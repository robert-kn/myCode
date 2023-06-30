#include <stdio.h>

int main(){
	int c = 0;

	//c = getchar(); 

	while((c = getchar()) != EOF){
		printf("%d\n",c);
	}
	printf("%d at EOF\n",c);
}
