#include <stdlib.h>
#include <stdbool.h>

#define N 12

void fill_array (int *array) {
    for (int i = 0; i < N; i++) {
        *(array + i) = rand() % 6;
    }
}

void fill_array_repeat (int *array, int *array_repeat){
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            if (*(array + i) == *(array + j)) count++;
        }
        *(array_repeat + i) = count;
        count = 0;
    }
}

int count_result_size (int *array, int *array_repeat){
    int result_size = 0;
    bool flag = true;
    for (int i = 0; i < N; i++){
        if (*(array_repeat + i) != 1) {
            for (int j = 0; j < i; j++){
                if (*(array + i) == *(array + j)) flag = false;
            }
            if (flag == true) result_size += 1;
            flag = true;
        }
    }
    result_size *= 2;
    return result_size;
}

void fill_result_array (int size, int *array, int *array_repeat, int *result_array){
    int k = 0;
    bool flag = true;
    for (int i = 0; i < N; i++){
        if (*(array_repeat + i) != 1){
            for (int j = 0; j < i; j++){
                if (*(array + i) == *(array + j)) flag = false;
            }
            if (flag == true){
                *(result_array + k) = *(array + i);
                *(result_array + k + 1) = *(array_repeat + i);
                k += 2;
            }
            flag = true;
        }
    }
}


int main ()
{
    int *array = malloc(N * sizeof(int));
    int *array_repeat = malloc(N * sizeof(int));

    fill_array(array);
    /*
    int DBG_arr[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_arr[i] = *(array + i);
    }
    */
    fill_array_repeat (array, array_repeat);
    /*
    int DBG_arr_repeat[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_arr_repeat[i] = *(array_repeat + i);
    }
    */
    int result_size = count_result_size(array, array_repeat);
    int *result_array = malloc(result_size * sizeof(int));
    fill_result_array(result_size, array, array_repeat, result_array);
    /*
    int DBG_result_array[N] = {0};
    for (int i = 0; i < result_size; i++){
        DBG_result_array[i] = *(result_array + i);
    }
    */
    free(result_array);
    free(array);
    free(array_repeat);

    return 0;
}

