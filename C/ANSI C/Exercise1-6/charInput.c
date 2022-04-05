#include <stdio.h>

int main(){
	system("clear");
	int c = 0;

	//c = getchar(); 

	while((c = getchar()) != EOF){
		printf("%d\n",c);
	}
	printf("%d at EOF\n",c);
}
