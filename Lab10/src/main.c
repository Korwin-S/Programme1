/**
 * @mainpage
 * # Загальне завдання
 *  Для лабораторної роботи “Функції” необхідно додати можливість генерації Doxygen документації.
 *
 *  Завдання лабораторної роботи “Функції”:
 *
 * - Завдання №1: «Визначити найбільший спільний дільник для двох заданих чисел».
 *
 * - Завдання №2:  «Дано двовимірний масив з N * N цілих чисел. Виконати циклічне зрушення елементів рядків масиву
 * в напрямку справа наліво (перший елемент рядка повинен переміститися в ії кінець)».
 *
 * - Завдання №3: «Реалізувати функцію, що визначає, скільки серед заданої послідовності чисел таких пар,
 * у котрих перше число менше наступного, використовуючи функцію з варіативною кількістю аргументів».


 * @author Starovoytov N.
 * @date 20-dec-2020
 * @version 1.0
 */

 /**
 * @file main.c
 * @brief Лабораторна робота №9
 *
 * @author Starovoytov N.
 * @date 20-dec-2020
 * @version 1.0
 */

#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

/**
 * Розмір матриці у завданні №2
 */
#define N 3

/**
 * Знаходження НСД двох чисел
 * @param a  - Перше число
 * @param b  - Друге число
 * @return result - НСД двох чисел
 */
int Find_gcf (int a, int b){
    int result = 0;
    while (a != 0 && b != 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    result = a + b;
    return result;
}

/**
 * Циклічний зсув (зрушення) кожної строки матриці на 1 праворуч
 * @param array  - Матриця
 * @return 0  - Код успішного виконання функції
 */
int Shift_matrix_right_1 (int array[]) {
    int temp[N];
    for (int i = 1; i <= N; i++) {
        temp[i-1] = array[(i-1)*N];
        for (int j = 0; j < N; j++) {
            array[(i-1)*N+j] = array[(i-1)*N+j+1];
        }
        array[i*N-1] = temp[i-1];
    }
    return 0;
}

/**
 * Знаходження серед заданої послідовності чисел
 * кількості таких пар, у котрих перше число менше наступного
 * @param size  - Кількість чисел у послідовності
 * @param ...  - Числа послідовності
 * @return result  - Кількість пар, що відповідають заданим параметрам
 */
int Num_of_ordered_pairs (int size, ... )
{
    int result = 0;
    int i = 1;
    va_list v;
    va_start(v, size);
    int a = va_arg(v, int), b;
    while (i < size){
        b = va_arg(v, int);
        if (a < b) result += 1;
        a = b;
        i++;
    }
    va_end(v);
    return result;
}

/**
 * Головна функція.
 *
 * Послідовність дій для завдання 1:
 * - задаємо seed для функції rand()
 * - задаємо два числа, для яких будемо знаходити НСД
 * - присвоюємо змінним результат за допомогою функції
 * {@link Find_gcf}
 *
 * Послідовність дій для завдання 2:
 * - задаємо масив (матрицю) розміру N*N
 * - заповнюємо матрицю випадковими числами
 * - робимо циклічний зсув (зрушення) кожної строки матриці за допомогою функції
 * {@link Shift_matrix_right_1}
 *
 * Послідовність дій для завдання 3:
 * - задаємо розмір масиву
 * - присвоюємо змінним результат за допомогою функції
 * {@link Num_of_ordered_pairs}
 * @return успішний код повернення з програми (0)
 */
int main(){
    ///// Program 1 /////
    srand(time(NULL));
    const int Pr1_num1 = 175;
    const int Pr1_num2 = 250;
    int Pr1_result = 0, Pr1_result_rand = 0;
    Pr1_result = Find_gcf (Pr1_num1, Pr1_num2);
    Pr1_result_rand = Find_gcf (rand()%500, rand()%500);

    ///// Program 2 /////
    int Pr2_array[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Pr2_array[i][j] = rand() % 10;
        }
    }
    Shift_matrix_right_1 (&Pr2_array[0][0]);

    ///// Program 3 /////
    int Pr3_size = 9;
    int Pr3_result = Num_of_ordered_pairs (Pr3_size, 2, 2, 8, 7, 9, 3, 12, 5, 99);
    int Pr3_result_random = Num_of_ordered_pairs (Pr3_size, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100);

    return 0;
}
