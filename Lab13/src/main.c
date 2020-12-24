/**
 * @mainpage
 * # Загальне завдання
 * Завдання №5: "Текст - це програма на мові С. Визначити, скільки в ньому операторів циклу".
 *
 * @author Starovoytov N.
 * @date 24-dec-2020
 * @version 1.0
 */

/**
* @file main.c
* @brief Лабораторна робота №13
*
* @author Starovoytov N.
* @date 24-dec-2020
* @version 1.0
*/

#include <stdlib.h>
#include <string.h>

/**
 * Функція підраховує, скільки в заданому тексті операторів циклу.
 * @param string - строка із заданим текстом
 * @return Кількість операторів циклу в заданому тексті
 */
int get_count_of_operators(char *string)
{
    int counter = 0;
    char *string_copy = malloc((strlen(string) + 1) * sizeof(char));
    strcpy(string_copy, string);
    char *operators[] = {"while", "do", "for", "continue", "break"};
    for (int i=0; i<5; i++){
        while (strstr(string_copy, operators[i]) != NULL) {
            counter++;
            char *temp = strstr(string_copy, operators[i]);
            memset(temp, '_', 1);
            }
    }
    return counter;
}

/**
 * Головна функція.
 * Послідовність дій:
 * -# Задаємо строку із заданим текстом
 * -# Змінній result присвоюємо значення кількості операторів циклу в заданому тексті за допомогою функції {@link get_count_of_operators}
 * @return 0 - код успішного виконання програми
 */
int main()
{
    char string[] = "main(){int a=0, b=0; for (i=0; i<15; i++) a += 1; do {b += 2; if (b == 40) break; if (b == 30) break;} while (b <= 90); return 0;}";
    int result = get_count_of_operators(string);
    return 0;
}