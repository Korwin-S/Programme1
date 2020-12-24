/**
 * @mainpage
 * # Загальне завдання
 * Дано  масив  з  N   речовинних  чисел.  Підрахувати  кількість  ділянок,
 * які  утворюють  безперервні  послідовності  чисел  з  не-зменшуваними
 * значеннями.  Максимальну ділянку переписати у інший масив.
 *
 * @author Starovoytov N.
 * @date 24-dec-2020
 * @version 1.0
 */

/**
* @file Pr3.c
* @brief Лабораторна робота №11
*
* @author Starovoytov N.
* @date 24-dec-2020
* @version 1.0
*/

#include <stdlib.h>

/**
 * Розмір масиву
 */
#define N 12

/**
 * Знаходження кількості ділянок, які  утворюють  безперервні  послідовності  чисел  з  не-зменшуваними значеннями
 * @param array - вхідний масив
 * @return counter - кількість ділянок
 */
float find_count(float *array)
{   /*
    float DBG_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_array[i] = *(array + i);
    }
    */
    int counter = 0;
    for (int i = 1; i < N; i++) {
        if (*(array + i) >= *(array + i - 1) && *(array + i + 1) < *(array + i)) {
            counter +=1;
        }
    }
    return counter;
}

/**
 * Знаходження номерів елементів масиву, які є початком і кінцем найбільшої ділянки
 * @param array - вхідний масив
 * @param pos_min_max - масив, в який будуть записані перший та останній елементи найбільшої ділянки
 */
void find_positions(float *array, int pos_min_max[])
{   /*
    float DBG_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_array[i] = *(array + i);
    }
    */
    int temp = 0, a = 0, b = 0;
    int prev_pos = 0;
    int now_pos = 0;
    for (int i = 1; i < N; i++) {
        if (*(array + i) <= *(array + i - 1) && *(array + i + 1) >= *(array + i))
            prev_pos = i;
        if (*(array + i) >= *(array + i - 1) && *(array + i + 1) < *(array + i)){
            now_pos = i;
            if (now_pos - prev_pos > temp) {
                a = prev_pos;
                b = now_pos;
                temp = now_pos - prev_pos;
            }
        }
    }
    pos_min_max[0] = a;
    pos_min_max[1] = b;
}

/**
 * Заповнення результуючого масиву числами з найбільшої ділянки
 * @param array - масив
 * @param result_arr - результуючий масив
 * @param a - перший елемент ділянки
 * @param b - останній елемент ділянки
 */
void fill_res_array (float *array, float *result_arr, int a, int b){
    for (int i = a; i <= b; i++ ){
        *(result_arr + i - a) = *(array + i);
    }
}

/**
 * Головна функція.
 * Послідовність дій:
 * -# Виділяємо пам'ять для задання масиву
 * -# Заповняємо масив випадковими числами
 * -# Створюємо масив для зберігання першого та останнього елементів найбільшої ділянки та заповнюємо його через функцію {@link find_positions}
 * -# Змінній size_of_res надаємо значення розміру результуючого масиву
 * -# Виділяємо пам'ять та заповнюємо результуючий масив за допомогою функції {@link fill_res_array}
 * -# Змінній num_of_chunks надаємо значення кількості ділянок за допомогою функції {@link find_count}
 * -# Очищуємо пам'ять
 * @return 0 успішний код повернення з програми (0)
 */
int main()
{
    float *array= malloc(N * sizeof(float));
    for (int i = 0; i < N; i++){
        *(array + i) = rand() % 100/(float)10 ;
    }
    /*
    float DBG_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_array[i] = *(array + i);
    }
     */
    int pos_min_max[2] = {0};
    find_positions(array, pos_min_max);

    int size_of_res = pos_min_max[1] - pos_min_max[0] + 1;
    float *result_arr = malloc(size_of_res * sizeof(float));

    fill_res_array(array, result_arr, pos_min_max[0], pos_min_max[1]);
    int num_of_chunks = find_count(array);
    /*
    float DBG_result_array[N] = {0};
    for (int i = 0; i < N; i++){
        DBG_result_array[i] = *(result_arr + i);
    }
    */
    free(result_arr);
    free(array);
    return 0;
}



