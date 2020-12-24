#include <stdlib.h>

#define N 12

void fill_array (int *array) {
    for (size_t i = 0; i < N; i++) {
        *(array + i) = rand() % 15 - 5;
    }
}

void find_positions (int *array, int positions[]) {
    int temp_sum = 0, sum = 0, temp_low_pos = 0, low_pos = 0, high_pos = 0;
    for (int i = 0; i < N; i++) {
        if (*(array + i) > 0) {
            if (temp_sum == 0) temp_low_pos = i;
            temp_sum += *(array + i);
        } else {
            if (temp_sum > sum) {
                low_pos = temp_low_pos;
                high_pos = i - 1;
                sum = temp_sum;
            }
            temp_sum = 0;
        }
    }
    positions[0] = low_pos;
    positions[1] = high_pos;
}

void fill_result_array (int *array, int *result_array, int low_pos, int high_pos) {
    for (int i = low_pos; i <= high_pos; i++ ){
        *(result_array + (i - low_pos)) = *(array + i);
    }
}

int main()
{
    int *array = malloc(N * sizeof(int));
    fill_array(array);
	/*
    int DBG_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_array[i] = *(array + i);
    }
	*/
    int positions[2] = {0};
    find_positions(array, positions);

    int size_of_res_arr = positions[1] - positions[0] + 1;

    int *result_array= malloc(size_of_res_arr * sizeof(int));
    fill_result_array(array, result_array, positions[0], positions[1]);
	/*
    int DBG_result_array[N] = {0};
    for (int i = 0; i < size_of_res_arr; i++){
        DBG_result_array[i] = *(result_array+ i);
    }
	*/
    free(result_array);
    free(array);

    return 0;
}

