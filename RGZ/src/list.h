/**
 * @file list.h
 * @brief Файл з описом класа-списка
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#pragma once

#include "birds.h"

/**
 * @brief Клас, що включає в себе массив
(STL-коллекцію) вказівників до базового класу. А також базові методи
роботи з списком:
 * -# Очистка списку
 * -# Відображення списку
 * -# Додання елементу
 * -# Видалення елементу
 * -# Отримання елементу
 */
class CList {
private:
    /** Список птахів */
    vector<Virtual_Bird*> birds;
    /** Кількість елементів списку */
    int N = -1;
public:
    CList();
    virtual ~CList();

    int Get_N() const;
    void Add_Bird(Virtual_Bird *bird);
    void Add_Bird_by_index(Virtual_Bird *bird, int index);
    Virtual_Bird *Get_Bird_by_index(int index) const;
    void Delete_Bird(int index);
    void Print_All() const;
    void Clear_List();
};

