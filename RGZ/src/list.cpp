/**
 * @file list.cpp
 * @brief Файл з описом методів класа-списка
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "list.h"

/**
 * @brief Конструктор класу {@link CList}
 */
CList::CList() {}

/**
 * @brief Деструктор класу {@link CList}
 */
CList::~CList() {
    while (!birds.empty()){
        birds.pop_back();
    }
    birds.clear();
}

/**
 * @brief Метод, що додає елемент в кінець списку
 * @param bird Елемент, що буде доданий
 */
void CList::Add_Bird(Virtual_Bird *bird) {
    N += 1;
    birds.push_back(bird->clone());
}

/**
 * @brief Метод, що додає елемент до списку за індексом
 * @param bird елемент, що буде доданий
 * @param index Номер позиції у списку, на яку буде доданий елемент
 */
void CList::Add_Bird_by_index(Virtual_Bird *bird, int index) {
    auto iter = birds.begin();
    birds.insert(iter + index, bird->clone());
    N += 1;
}

/**
 * @brief Метод, що видаляє елемент зі списку за індексом
 * @param index Номер елемента у списку, що буде видалений
 */
void CList::Delete_Bird(int index){
    if (index > birds.size()){
        index = birds.size();
    } else if(index < 0){
        index = 0;
    }
    auto pos = birds.begin() + index;
    birds.erase(pos);
    N--;
}

/**
 * @brief Метод, що виводить весь список у консоль
 */
void CList::Print_All() const {
    for (int i = 0; i <= N; ++i) {
        cout << birds[i] << endl;
    }
}

/**
 * @brief Геттер для параметра N
 * @return Кількість елементів у списку
 */
int CList::Get_N() const {
    return this->N;
}

/**
 * @brief Метод, що повертає елемент списку за індексом
 * @param index номер елемента у списку
 */
Virtual_Bird* CList::Get_Bird_by_index(const int index) const {
    return birds[index];
}

/**
 * @brief Метод, який очищує список
 */
void CList::Clear_List() {
    while (!birds.empty()){
        birds.pop_back();
    }
    birds.clear();
    N = -1;
}

