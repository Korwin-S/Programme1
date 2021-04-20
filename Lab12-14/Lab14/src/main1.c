/**
 * @mainpage
 * # Загальне завдання
 * Програму, яка була розроблена у попередній лабораторній роботі (робота з строками), змінити так, щоб:
 -#  початкові дані вводилися з файлу;
 -#  видача результуючих даних проводилася і в консоль, і у файл.
 -#  ім’я вхідного та вихідного фалу було отримано від користувача;
 -#  при  запиті  даних,  користувач  отримав  повідомлення,  що  від  нього очікують.
 * Завдання №5: "Текст - це програма на мові С. Визначити, скільки в ньому операторів циклу".
 *
 * @author Starovoytov N.
 * @date 05-apr-2021
 * @version 1.0
 */

/**
* @file main1.c
* @brief Лабораторна робота №14
*
* @author Starovoytov N.
* @date 05-apr-2021
* @version 1.0
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    free(string_copy);
    return counter;
}

/**
 * Функція читає з вхідного файлу текст да зберігає його в одну строку
 * @param string - строка із заданим текстом
 * @return *string - покажчик на строку із прочитаним текстом
 */
char read_from_file(char *string) {
    FILE *input;
    char *input_name = malloc(100);
    printf("Please enter input file name:");
    scanf("%s", input_name);
    getchar();
    if ((input = fopen(input_name, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fscanf(input, "%[^EOF]", string);
    free(input_name);
    fclose(input);
    return *string;
}



/**
 * Функція записує у вихідний файл результат - кількість операторів циклу в заданому тексті
 * @param result - кількість операторів циклу в заданому тексті
 */
void write_to_file(int result) {
    FILE *output;
    char *output_name = malloc(100);
    printf("Please enter output file name:");
    scanf("%s", output_name);
    getchar();
    if ((output = fopen(output_name, "w")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fprintf(output, "%d", result);
    fclose(output);
    free(output_name);
}


/**
 * Головна функція.
 * Послідовність дій:
 * -# Виділяємо пам'ять під строку з текстом
 * -# Зчитуємо з вхідного файлу текст до строки string
 * -# Змінній result присвоюємо значення кількості операторів циклу в заданому тексті за допомогою функції {@link get_count_of_operators}
 * -# Записуємо у вихідний файл результат - кількість операторів циклу в заданому тексті
 * @return 0 - код успішного виконання програми
 */
int main()
{
    char *string = malloc(200);
    *string = read_from_file(string);
    int result = get_count_of_operators(string);
    free(string);
    write_to_file(result);
    return 0;
}