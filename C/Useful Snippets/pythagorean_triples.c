#include <stdio.h>

int Squared(int x);

int main(void)
{
	int maxC;

	printf("Enter the maximum length of hypotenuse: ");
	scanf("%d", &maxC);

	for (int sideC = 1; sideC <= maxC; sideC++) {
		for (int sideB = 1; sideB <= maxC; sideB++) {
			for (int sideA = 1; sideA <= maxC; sideA++) {
				if (Squared(sideC) == Squared(sideA) + Squared(sideB))
					printf("%d %d %d\n", sideA, sideB, sideC);
			}
		}
	}
}

int Squared(int x)
{
	return x * x;
}
