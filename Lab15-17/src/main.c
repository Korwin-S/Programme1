/**
 * @mainpage
 * # Загальне завдання
 * -# Розробити функцію, яка читає дані(список птахів) з файлу;
 * -# Розробити функцію, яка записує список птахів до файлу;
 * -# Розробити функцію, яка виводить список птахів на екран;
 * -# Розробити функцію, яка буде сортувати птахів за заданим критерієм;
 * -# Розробити функцію, яка буде знаходити відсоткове відношення самок до самців;
 * -# Розробити функцію, яка генерує вік птахів;
 * -# Розробити функцію, яка записує список птахів у бінарний файлу;
 * -# Розробити функцію, яка читає список птахів з бінарного файлу;
 * -# Розробити функцію, яка зчитує з бінарного файлу окремого птаха за індексом;
 *
 * @author Starovoytov N.
 * @date 19-apr-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Основний файл з демонстрацією роботи програми та функцій
 *
 * @author Starovoytov N.
 * @date 22-march-2021
 * @version 1.0
 */

#include "lib.h"

/**
 * **Головна функція.**
 *
 * Послідовність дій:
 * - створення масиву із {@link N} птахів
 * - зчитування масиву птахів з файлу за допомогою функції {@link read_from_file}
 * - генерація віку кожної птиці за допомогою функції {@link random_age_generation}
 * - сортування птахів за заданим критерієм за допомогою функції {@link sort_by_criterion}
 * - вивід даних про всіх птахів на екран за допомогою функції {@link print_in_console}
 * - вивід даних про всіх птахіви у **текстовий** файл за допомогою функції {@link print_in_file}
 * - знаходження відсоткового відношення самок до самців за допомогою функції {@link find_sex_ratio}
 * - вивід даних про всіх птахів у **бінарний** файл за допомогою функції {@link write_to_binary}
 * - зчитування масиву птахів з **бінарного** файлу за допомогою функції {@link read_from_binary}
 * - звільненя виділеної пам'яті
 * @return 0 - успішний код повернення з програми
 */
int main(){
    struct Bird * birds = malloc(N * sizeof (struct Bird));

    read_from_file(birds);

    random_age_generation(birds);

    char buf[10];
    printf("Enter a sort criterion: ");
    scanf("%s", buf);
    printf("\n");

    sort_by_criterion(birds, buf, N);

    print_in_console(birds);

    print_in_file(birds);

    find_sex_ratio(birds, N);

    write_to_binary(birds);

    struct Bird * binary_birds = malloc(N * sizeof (struct Bird));

    read_from_binary(binary_birds);
   // print_in_console(binary_birds);

    free(birds);
    free(binary_birds);
    return 0;
}