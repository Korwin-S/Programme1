#include <stdlib.h>
#define N 3

int main()
{
    int matrix[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 3;
        }
    }
    int result[N][N] = {0};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int l = 0; l < N; l++) {
                result[i][j] += matrix[i][l] * matrix[l][j];
            }
       	}
   	}
   	return 0;
}
