#pragma once

/**
 * @file lib.h
 * @brief Файл з описом структури птаха, та списком функцій
 *
 * @author Starovoytov N.
 * @date 29-apr-2021
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
 * Функція виводить масив структур на екран
 * @param birds масив структур що виводиться
 */
void print_in_console(struct Bird *birds, int count);

/**
 * Функція вставляє елемент в масив структур за заданим індексом
 * @param birds масив структур
 * @param paste_bird елемент, що буде вставлений
 * @param pos індекс, за яким буде вставлений елемент
 */
struct Bird * add_bird(struct Bird *birds, struct Bird paste_bird, int pos);

/**
 * Функція видаляє елемент з масиву структур за заданим індексом
 * @param birds масив структур
 * @param pos індекс, за яким буде видалений елемент
 */
struct Bird * delete_bird(struct Bird *birds, int pos);

/**
 * Функція вставляє підрядок в рядок за заданим індексом
 * @param text текст в який буде вставлений підрядок
 * @param pasted_text підрядок, який буде вставлений в текст
 * @param pos індекс, після якого буде вставлений підрядок
 */
char * insert_string(char * text, char * pasted_text, int pos);

/**
 * Функція видаляє підрядок з тексту за заданим індексом
 * @param text текст з якого буде видалений підрядок
 * @param start_pos індекс, починаючи з якого буде видалений підрядок
 * @param end_pos індекс, яким закінчиться видалення підрязка
 */
char * delete_string(char * text, int start_pos, int end_pos);

/**
 * Функція порівнює строки між собою та повертає результат у форматі, що легко привести ло типу bool
 * @param a перша строка для порівняння
 * @param b друга строка для порівняння
 * @return результат порівняння: 0 - перша строка коротше другої або строки рівні, 1 - перша строка довше другої
 */
int bool_compare_strings(char a[10], char b[10]);

/**
 * Функція демонструє реалізацію перших двох завдань: робота з рядками
 */
void Demonstration_of_strings();
