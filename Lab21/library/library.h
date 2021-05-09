#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>


#define N 5

/**
 * Структура «Стать птаха»
 */
enum Sex{
    Male,
    Female
};

/**
 * Структура «Птах»
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
    struct Bird *next;
    struct Bird *prev;
};

/**
 * Функція виводить поточну дату та час на екран
 */
void Print_Date();


/**
* Функція виводить елемент списку на екран
* @param bird елемент списку для виводу
*/
void Print_bird(struct Bird *bird);

/**
 * Двоспрямований список
 */
struct List {
    struct Bird *head;
    struct Bird *tail;
};

/**
 * Функція створює список
 */
struct List *New_list();

/**
 * Функція створює новий елемент списку
 * @param bird елемент, що буде створений
 * @return повертає створений елемент
 */
struct Bird *New_bird(struct Bird *bird);

/**
 * Функція додає новий елемент в кінець списку
 * @param list список для додавання елементу
 * @param bird елемент, що буде доданий
 */
void Add_element_to_end(struct List *list, struct Bird *bird);

/**
 * Функція додає новий елемент в початок списку
 * @param list список для додавання елементу
 * @param bird елемент, що буде доданий
 */
void Add_element_to_begin(struct List *list, struct Bird *bird);

/**
 * Функція додає новий елемент в список по індексу
 * @param pos місце куди додати новий елемент
 * @param list список для додавання елементу
 * @param bird елемент, що буде доданий
 */
void Insert_element(struct List *list, int pos, struct Bird *bird);

/**
 * Функція видаляє елемент зі списку
 * @param pos з якого буде видалено елемент
 * @param list список для видалення елементу
 */
void Delete_element(struct List *list, int pos);

/**
 * Функція читає данні з заданого файлу та записує їх в список
 * @param list список для заповнення
 */
void Read_list_from_file(struct List* list);

/**
 * Функція виводить список на екран
 * @param list список для виводу
 */
void Show_list(struct List *list);

/**
 * Функція записує у файл заданий список
 * @param list список для зчитування
 * @param side напрям списку
 */
void Print_list_in_file(struct List *list);

/**
 * Функція знаходить заданий елемент списку
 * @param list список для пошуку
 * @param index поле, яке треба знайти
 */
void Find_bird(struct List * list, int index);

/**
 * Функція сортує сиписок за віком птиці
 * @param list список для сортування
 * @param compare викликає функції порівняння заданих полів
 */
void Sort_birds_by_age(struct List *list);

/**
 * Функція очищує список
 * @param list список для очищення
 */
void Free_list(struct List *list);


#endif //LIB_LIBRARY_H
