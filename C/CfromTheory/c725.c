/**
 * Write a program that reads 6 integers and stores them in a 2×3 array (e.g., a). Then, it should read another 6 integers and store them in a second 3×2 
 * array (e.g., b). The program shoulddisplaytheelementsofathird2×2array(e.g.,c),whichistheresultofc = a×b. It is reminded from the linear algebra that the 
 * product of two matrices is produced by adding the products of the elements of each row of the first matrix with the correspond- ing elements of each column 
 * of the second matrix. Therefore, the outcome of a N×M matrix multiplied with a M×N matrix is a N×N matrix. For example, consider the following a (2×3) and 
 * b (3×2) matrices:
 * 
 * a = [[1, -1, 1],
 *      [0, 2, 1]]
 * 
 * b = [[1, 0],
 *      [2, -2],
 *      [2, 3]]
 * 
 * The dimension of c = a×b is 2×2, and its elements are
 * 
 *  c = [[1 * 1 + (-1) * 2 + 1 * 2, 1 * 0 + (-1) * (-2) * 1 * 3]
 *       [0 * 1 + 2 * 2 + 1 * 2, 0 * 0 + 2 * (-2) + 1 * 3]]
 * 
 *    = [[1, 5]
 *       [6, -1]]
 * 
*/

#include <stdio.h> 

#define N 2
#define M 3

int main(void){
    int i, j, k, a[N][M], b[M][N], c[N][N] = {0};

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            for(k = 0; k < M; k++)
                c[i][j] += a[i][k] * b[k][j];

    printf("\nArray c = a x b (%dx%d)\n", N, N);
    printf("-----------------\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%5d", c[i][j]);
        printf("\n");
    }
    return 0;
}