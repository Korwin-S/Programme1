/**
 * @mainpage
 * # Загальне завдання
 * Для  попередньо  розробленого  функціоналу  по  роботі  з  прикладною
областю за допомогою макровизначень зробити наступну “кастомізацію”:  якщо
визначене  макровизначення  debug,  т о   при  виклику  кожної  функції  роботи  з
прикладною областю виконувати таке:
 * -# Виводити поточну дату та час;
 * -# Виводити ім’я поточної функції;
 * -# При завершенні програми вивести загальний час роботи програми.
 * @author Starovoytov N.
 * @date 07-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Основний файл з демонстрацією роботи програми
 *
 * @author Starovoytov N.
 * @date 07-may-2021
 * @version 1.0
 */

#include "../Library/library.h"

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

    #define DEBUG

    #ifdef DEBUG
        Print_Date();
    #endif

    printf("\n");
    struct List *list = New_list();

    struct Bird struct_paste_bird = {0, "SOME_BIRD", 27, 250, 40, 2, 0, 1};
    struct Bird *paste_bird = malloc(sizeof(struct Bird));
    *paste_bird = struct_paste_bird;

    Read_list_from_file(list);
    int start1, finish1;

    while (true) {
        int action = 0;
        printf("\n|--------------------------------------------------------------------|\n");
        printf(" Выберите действие: \n");
        printf("\t1. Вывести список на экран\n");
        printf("\t2. Вывести список в файл\n");
        printf("\t3. Вставить новый элемент в список\n");
        printf("\t4. Удалить элемент из списка\n");
        printf("\t5. Найти в списке элемент\n");
        printf("\t6. Сортировать список по возрасту птицы\n");
        printf("\t7. Вывести на экран птиц с именем, содержащим два или больше слова\n");
        printf("\t8. Выход\n");
        printf("|--------------------------------------------------------------------|\n\n");
        printf(" --> ");
        scanf("%d", &action);
        switch (action) {
            case 1:
                #ifdef DEBUG
                printf("\nВыполняется функция Show_list");
                printf("\nСписок:\n\n");
                start1 = clock();
                Show_list(list);
                finish1 = clock();
                finish1 -= start1;
                printf("Время выполнения функции: %dms%s", finish1, "\n");
                #else
                printf("\nСписок:\n\n");
                Show_list(list);
                #endif
                break;
            case 2:
                #ifdef DEBUG
                printf("\nВыполняется функция Print_list_in_file");
                start1 = clock();
                Print_list_in_file(list);
                finish1 = clock();
                finish1 -= start1;
                printf("\n Список занесен в файл 'result.txt'\n");
                printf("Время выполнения функции: %dms%s", finish1, "\n\n");
                #else
                Print_list_in_file(list);
                printf("\n Список занесен в файл 'result.txt'\n\n");
                #endif
                break;
            case 3:
                printf("\nЭлемент, который будет вставлен: \n\n");
                Print_bird(paste_bird);
                printf("\nВведите позицию, на которую нужно вставить элемент: \n");
                printf(" --> ");
                int pos;
                scanf("%d", &pos);
                #ifdef DEBUG
                printf("\nВыполняется функция Insert_element");
                start1 = clock();
                Insert_element(list, pos, paste_bird);
                finish1 = clock();
                finish1 -= start1;
                printf("\nЭлемент вставлен\n");
                printf("Время выполнения функции: %dms%s", finish1, "\n\n\n");
                #else
                Insert_element(list, pos, paste_bird);
                printf("\nЭлемент вставлен\n\n\n");
                #endif
                break;
            case 4:
                printf("\nВведите позицию элемента, который будет удалён: \n");
                printf(" --> ");
                int num;
                scanf("%d", &num);
                #ifdef DEBUG
                printf("\nВыполняется функция Delete_element");
                start1 = clock();
                Delete_element(list, num);
                finish1 = clock();
                finish1 -= start1;
                printf("\nЭлемент удалён\n");
                printf("Время выполнения функции: %dms%s", finish1, "\n\n\n");
                #else
                Delete_element(list, num);
                printf("\nЭлемент удалён\n\n\n");
                #endif
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
                #ifdef DEBUG
                printf("\nВыполняется функция Find_bird");
                start1 = clock();
                Find_bird(list, number);
                finish1 = clock();
                finish1 -= start1;
                printf("Время выполнения функции: %dms%s", finish1, "\n\n\n");
                #else
                Find_bird(list, number);
                #endif
                break;
            case 6:
                #ifdef DEBUG
                printf("\nВыполняется функция Sort_birds_by_age");
                start1 = clock();
                Sort_birds_by_age(list);
                finish1 = clock();
                finish1 -= start1;
                printf("\nСписок отсортирован \n");
                printf("Время выполнения функции: %dms%s", finish1, "\n\n\n");
                #else
                Sort_birds_by_age(list);
                printf("\nСписок отсортирован \n");
                #endif
                break;
            case 7:
                #ifdef DEBUG
                printf("\nВыполняется функция Print_Regex_Two_Words\n\n");
                start1 = clock();
                Print_Regex_Two_Words(list);
                finish1 = clock();
                finish1 -= start1;
                printf("Время выполнения функции: %dms%s", finish1, "\n\n\n");
                #else
                Print_Regex_Two_Words(list);
                #endif
                break;
            case 8:
                #ifdef DEBUG
                printf("\nВыполняется функция Free_list");
                start1 = clock();
                Free_list(list);
                finish1 = clock();
                finish1 -= start1;
                free(list);
                printf("\nВремя выполнения функции: %dms%s", finish1, "\n");
                printf("\nЗавершение работы программы...\n");
                return 0;
                #else
                Free_list(list);
                free(list);
                printf("\nЗавершение работы программы...\n");
                return 0;
                #endif
            default:
                printf("\nERROR: Вы ввели некорректный вариант\n");
                break;
        }
    }
}