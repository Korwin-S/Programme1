#include <stdlib.h>
#include <time.h>
#define N 3

int main()
{	
	srand(time(NULL));
    int array[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        array[i][j] = rand() % 10;
        }
    }
    int temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = array[i][0];
        for (int j = 0; j < N; j++) {
        array[i][j] = array[i][j+1];
        }
        array[i][N-1] = temp[i];
    }
    return 0;
}
