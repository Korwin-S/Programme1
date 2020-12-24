#include <stdlib.h>

#define N 7

void fill_array (int **array){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *(*(array + i) + j) = rand() % 10 - 5;
        }
    }
}

void fill_res_array (int **array, int *result_array){
    for(int i = 0; i < N; i++){
        *(result_array + i) = *(*(array + i) + i);
    }
}

void sort_array (int *result_array){
    int temp = 0;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (*(result_array + i) < *(result_array + j)) {
                temp = *(result_array + j);
                *(result_array + j) = *(result_array + i);
                *(result_array + i) = temp;
            }
        }
    }
}

int main() {

    int  **array = (int**)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++){
        array[i] = (int *)malloc(N * sizeof(int));
    }
    int *result_array = malloc(N * sizeof(int));

    fill_array(array);
    /*
    int DBG_array[N][N] = {0};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            DBG_array[i][j] = *(*(array + i) + j);
        }
    }
    */
    fill_res_array(array, result_array);
    /*
    int DBG_res_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_res_array[i] = *(result_array + i);
    }
    */
    sort_array(result_array);
    /*
    for (int i = 0; i < N; i++){
        DBG_res_array[i] = *(result_array + i);
    }
    */
    free(array);
    free(result_array);

}

