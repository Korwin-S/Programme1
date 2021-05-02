/**
 * @mainpage
 * # Загальне завдання
 * -# Розробити функцію, яка реалізує вставку в рядок "s" другий рядок "s2" в "і" - у позицію рядка "s";
 * -# Розробити функцію, видалення з рядка "" усіх символів з індексами в заданому діапазоні;
 * -# Розробити функцію додавання та видалення елементів з динамічного масиву вашої прикладної області
 *
 * @author Starovoytov N.
 * @date 29-apr-2021
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
 * - демонстрація реалізації перших двох завдань за допомогою функції {@link Demonstration_of_strings}
 * - створення масиву із {@link N} птахів
 * - зчитування масиву птахів з файлу за допомогою функції {@link read_from_file}
 * - генерація віку кожної птиці за допомогою функції {@link random_age_generation}
 * - надання користувачу вибору: додати або видалати елемент з масиву
 * - (в залежності від вибору) додавання елемента {@link paste_bird} за допомогою функції {@link add_bird}
 * - (в залежності від вибору) видалення елемента за допомогою функції {@link delete_bird}
 * - звільненя виділеної пам'яті
 * @return 0 - успішний код повернення з програми
 */
int main() {

    Demonstration_of_strings();

    struct Bird *birds = malloc(N * sizeof(struct Bird));
    read_from_file(birds);
    random_age_generation(birds);

    print_in_console(birds, N);

    struct Bird paste_bird = {1, "Some_bird", 27, 48, 49, 2, 0, Male};

    int position, a;
    printf("Select add/remove (1/0): ");
    scanf("%d", &a);
    if (a == 1) {
        printf("Enter a position to paste: ");
        scanf("%d", &position);
        birds = add_bird(birds, paste_bird, position);
        printf("\n\n______________________________________________________________________________________\n\n");
        print_in_console(birds, N + 1);
    }
    if (a == 0) {
        printf("Enter a position to remove: ");
        scanf("%d", &position);
        birds = delete_bird(birds, position);

        printf("\n\n______________________________________________________________________________________\n\n");
        print_in_console(birds, N - 1);
    }

    free(birds);
    return 0;
}