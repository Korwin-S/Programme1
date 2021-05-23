#pragma once

/**
 * @file lib.h
 * @brief Файл з описом структури птаха, та списком функцій
 *
 * @author Starovoytov N.
 * @date 19-apr-2021
 * @version 1.0
 */

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <vector>
#include <fstream>

using namespace  std;

/**
 * Кількість структур(птахів) у масиві
 */
enum Sex{
    Male,
    Female
};

/**
 * Структура «Птиця»
 */
class Bird{
private:
    bool LOTR; // 1 - yes, 0 - no.
    string name;
    int age;
    struct Home{
        int space;
        int height;
        int count_of_feeders;
        bool if_nest; // 1 - yes, 0 - no.
    } home;
    enum Sex enumSex;

public:
    Bird ();
    Bird (bool LOTR, string name, int age, struct Home home, enum Sex sex);
    Bird(const Bird &copy);
    virtual ~Bird();

    bool get_LOTR() const;
    string get_name() const;
    int get_age() const;
    int get_space() const;
    int get_height() const;
    int get_count_of_feeders() const;
    bool get_if_nest() const;
    Sex get_Sex() const;

    void set_LOTR (const int LOTR);
    void set_name (const string name);
    void set_age (const int age);
    void set_space (const int space);
    void set_height (const int height);
    void set_count_of_feeders (const int count_of_feeders);
    void set_if_nest (const int if_nest);
    void set_Sex (const Sex sex);

    void Print();
};


