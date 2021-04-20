#pragma once

/**
 * @file lib.h
 * @brief Файл з описом структури птаха, та списком функцій
 *
 * @author Starovoytov N.
 * @date 19-apr-2021
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Кількість структур(птахів) у масиві
 */
#define N 5

/**
 * Перелік статей
 */
enum Sex{
    Male,
    Female
};

/**
 * Структура «Птиця»
 */
struct Bird{
    int LOTR; // 1 - yes, 0 - no.
    char name[15];
    int age;
    struct Home{
        int space;
        int height;
        int count_of_feeders;
        int if_nest; // 1 - yes, 0 - no.
    } home;
    enum Sex enumSex;
};

/**
 * Функція читає данні з заданого файлу та записує їх в задану структуру
 * @param name масив структур для заповнення
 */
void read_from_file(struct Bird *birds);

/**
 * Функція генерує випадковий вік птиці у заданому діапазоні
 * @param birds масив структур для заповнення
 */
void random_age_generation(struct Bird *birds);

/**
 * Функція порівнює строки між собою та повертає результат у форматі, що легко привести ло типу bool
 * @param a перша строка для порівняння
 * @param b друга строка для порівняння
 * @return результат порівняння: 0 - перша строка коротше другої або строки рівні, 1 - перша строка довше другої
 */
int bool_compare_strings(char a[10], char b[10]);

/**
 * Функція сортує масив структур за заданим критерієм
 * @param birds масив структур який буде сортуватись
 * @param criterion критерій за яким буде відбуватись сортування
 * @param size кількість птахів у масиві
 */
void sort_by_criterion(struct Bird *birds, char criterion[10], int size);

/**
 * Функція виводить відсортований масив структур на екран
 * @param birds масив структур що виводиться
 */
void print_in_console(struct Bird *birds);

/**
 * Функція виводить відсортований масив структур в текстовий файл
 * @param birds масив структур що виводиться
 */
void print_in_file(struct Bird *birds);

/**
 * Функція знаходить відсоткове відношення самок до самців у масиві птахів
 * @param birds масив структур
 * @param size кількість птахів у масиві
 * @return повертає знайдене відсоткове відношення
 */
double find_sex_ratio(struct Bird *birds, int size);

/**
 * Функція виводить відсортований масив структур в бінарний файл
 * @param birds масив структур що виводиться
 */
void write_to_binary(struct Bird *birds);

/**
 * Функція читає данні з заданого бінарного файлу та записує їх в задану структуру
 * @param birds масив структур для заповнення
 */
void read_from_binary(struct Bird *birds);

/**
 * Функція читає певну структуру за індексом із заданого бінарного файлу та записує її до заданої структури
 * @param bird структура для заповнення
 * @param file файл, з якого зчитується структура
 * @param index індекс структури
 */
void read_from_binary_by_index(struct Bird *bird, FILE *file, int index);
