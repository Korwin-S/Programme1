/**
 * @mainpage
 * # Загальне завдання
 * -# Розробити функцію, яка зчитує список з файлу
 * -# Розробити функцію, яка записує дані(список) у файлу;
 * -# Розробити функцію, яка виводить список на екран;
 * -# Розробити функцію, яка буде сортувати список за заданим критерієм;
 * -# Розробити функцію, яка буде знаходити заданий елемент у списку;
 * -# Розробити функцію, яка видаляє елемент зі списку;
 * -# Розробити функцію, яка вставляє новий елемент по індексу;
 * -# Реалізувати діалоговий режим спілкування з користувачем
 * @author Starovoytov N.
 * @date 01-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Основний файл з демонстрацією роботи програми
 *
 * @author Starovoytov N.
 * @date 01-may-2021
 * @version 1.0
 */

#include "list.h"
#include "data.h"

/**
 * **Головна функція.**
 *
 * Послідовність дій:
 * - виділення пам'яті під список
 * - створення елементу для вставки
 * - зчитування списку птахів з файлу за допомогою функції {@link Read_list_from_file}
 * - реалізація діалогового інтерфейсу: надання користувачу вибору, яку дію потрібно виконати
 * - в залежності від вибору, виконання вибраної дії
 * @return 0 - успішний код повернення з програми
 */
int main() {
    system("chcp 65001");
    printf("\n");
    struct List *list = New_list();

    struct Bird struct_paste_bird = {0, "SOME_BIRD", 27, 250, 40, 2, 0, 1};
    struct Bird *paste_bird = malloc(sizeof(struct Bird));
    *paste_bird = struct_paste_bird;

    Read_list_from_file(list);

    while (true) {
        int action;
        printf("\n|--------------------------------------------------------------------|\n");
        printf(" Выберите действие: \n");
        printf("\t1. Вывести список на экран\n");
        printf("\t2. Вывести список в файл\n");
        printf("\t3. Вставить новый элемент в список\n");
        printf("\t4. Удалить элемент из списка\n");
        printf("\t5. Найти в списке элемент\n");
        printf("\t6. Сортировать список по возрасту птицы\n");
        printf("\t7. Выход\n");
        printf("|--------------------------------------------------------------------|\n\n");
        printf(" --> ");
        scanf("%d", &action);
        switch (action) {
            case 1:
                printf("\nСписок:\n\n");
                Show_list(list);
                break;
            case 2:
                Print_list_in_file(list);
                printf("\n Список занесен в файл 'result.txt'\n\n");
                break;
            case 3:
                printf("\nЭлемент, который будет вставлен: \n\n");
                Print_bird(paste_bird);
                printf("\nВведите позицию, на которую нужно вставить элемент: \n");
                printf(" --> ");
                int pos;
                scanf("%d", &pos);
                Insert_element(list, pos, paste_bird);
                printf("\nЭлемент вставлен\n\n\n");
                break;
            case 4:
                printf("\nВведите позицию элемента, который будет удалён: \n");
                printf(" --> ");
                int num;
                scanf("%d", &num);
                Delete_element(list, num);
                printf("\nЭлемент удалён\n\n\n");
                break;
            case 5:
                printf("\nВведите критерий, по которому искать птицу: \n");
                printf("\t1. С кольцом или без\n");
                printf("\t2. Имя\n");
                printf("\t3. Возраст\n");
                printf("\t4. Площадь скворечника\n");
                printf("\t5. Высота скворечника\n");
                printf("\t6. Кол-во кормушек скворечника\n");
                printf("\t7. Является ли скворечник гнездом\n");
                printf("\t8. Пол птицы\n");
                printf(" --> ");
                int number;
                scanf("%d", &number);
                printf("\n");
                Find_bird(list, number);
                break;
            case 6:
                Sort_birds_by_age(list);
                printf("\nСписок отсортирован \n");
                break;
            case 7:
                Free_list(list);
                free(list);
                printf("\nЗавершение работы программы...\n");
                return 0;
            default:
                printf("\nERROR: Вы ввели некорректный вариант\n");
                break;
        }
    }
}