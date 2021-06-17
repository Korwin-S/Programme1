/**
 * @file controller.h
 * @brief Файл з описом класа-контроллера та класів-функторів
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#pragma once

#include "list.h"

/**
 * @brief Клас, що включає в себе колекцію розроблених класів, та наступні методи роботи з цією колекцією:
 * -# Читання даних з файлу та їх запис у контейнер (STL-контейнер);
 * -# Запис даних з контейнера у файл;
 * -# сортування елементів у контейнері за вказаними критеріями: поле та напрям сортування, які задаються користувачем з клавіатури;
 * -# пошук елементів за вказаними критеріями (три критерія, що присутні у кожному варіанті);
 */
class Controller {
private:
    /** Список птахів */
    vector<Virtual_Bird*> birds;
    /** Кількість елементів списку */
    int N = -1;
public:
    Controller();
    virtual ~Controller();

    int Get_N() const;
    void Add_Bird(Virtual_Bird *bird);
    Virtual_Bird *Get_Bird_by_index(const int index) const;
    void Delete_Bird(int index);
    void Print_All() const;
    void Clear_List();

    void Sort(bool direction, int criterion);

    double Find_Sex_Ratio() const;
    double Find_Average_Age_of_not_LOTR() const;
    Virtual_Bird *Find_Bird_With_Longest_Wintering() const;

    char Regex_Check(string &str, char *type) const;

    void Read_From_File(const string &file_name);
    void Write_To_File(const string &fileName) const;

};

/**
 * @brief Клас-функтор, у якому перевантажений оператор круглих дужок. Використовується при сортуванні списку птахів.
 */
class Functor{
protected:
    /** Критерій сортування */
    int criterion;
public:
    Functor();
    virtual ~Functor();

    virtual int get_criterion() const;

    virtual void set_criterion(const int Criterion);

    virtual bool operator()(Virtual_Bird* A, Virtual_Bird* B) const;

};
/*
**
 * @brief Клас-функтор, у якому перевантажений оператор круглих дужок. Робить те ж саме, що і клас
 * {@link Functor}, але інвертує напрям сортування. Використовується при сортуванні списку птахів.
 */
/*
class Invert_Functor{
protected:
    ** Критерій сортування *//*
    int criterion;
public:
    Invert_Functor();
    virtual ~Invert_Functor();

    int get_criterion() const;
    void set_criterion(const int Criterion);

    bool operator()(Virtual_Bird* A, Virtual_Bird* B) const;

};*/
