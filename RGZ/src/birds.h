#pragma once

/**
 * @file birds.h
 * @brief Файл з описом базового класу "птах" та його спадкоємців
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

using std::string;
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;
using std::regex;
using std::cmatch;
using std::regex_match;
using std::regex_search;
using std::regex_replace;

/**Перелік статей птахів*/
enum Sex{
    Male,
    Female
};

/**Перелік місяців*/
enum Month{
    January,    //0
    February,    //1
    March,    //2
    April,    //3
    May,    //4
    June,    //5
    July,    //6
    August,    //7
    September,    //8
    October,    //9
    November,    //10
    December    //11
};

/**
 * @brief Віртуальний базовий клас, спадкоємцями якого є всі "птахи": {@link Bird}, {@link Migrant} та {@link Exotic}
 */
class Virtual_Bird{
public:
    /** Конструктор класу {@link Virtual_Bird} */
    Virtual_Bird() = default;
    /** Деструктор класу {@link Virtual_Bird} */
    virtual ~Virtual_Bird() = default;
    /** Метод, що виводить інформацію про птаха у консоль */
    virtual void Print() = 0;
    /** Метод клонування */
    virtual Virtual_Bird* clone() const = 0;
    /** Метод, що повертає тип птаха */
    virtual char GetType() const = 0;

    friend ostream& operator<<(ostream &out, const Virtual_Bird* bird);
    friend ofstream& operator<<(ofstream &out, const Virtual_Bird* bird);

};

/**
 * @brief Базовий клас "Птах"
 */
class Bird : public Virtual_Bird{
protected:
    /**Окольцьований птах чи ні*/
    bool LOTR; // 1 - yes, 0 - no.
    /**Ім'я птаха*/
    string name;
    /**Вік птаха*/
    int age;
    /** @brief Структура, що містить дані про домівку птаха*/
    struct Home{
        /**Площа домівки*/
        int space;
        /**Висота домівки*/
        int height;
        /**Кількість годівниць домівки*/
        int count_of_feeders;
        /**Чи є домівка гніздом*/
        bool if_nest; // 1 - yes, 0 - no.
    } home;
    /**Стать птаха*/
    enum Sex enumSex;

public:
    Bird ();
    Bird (bool LOTR, string name, int age, struct Home home, enum Sex sex);
    //Bird(const Bird &copy);
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

    Virtual_Bird *clone() const override;
    void Print() override;
    char GetType() const override;

    friend ostream& operator<<(ostream &out, const Bird &bird);
    friend ofstream& operator<<(ofstream &out, const Bird &bird);
    friend stringstream &operator>>(stringstream &in, Bird &bird);
    bool operator==(const Bird *other_bird);
    bool operator!=(const Bird *other_bird);
};

/**
 * @brief Клас "Мігруючий птах"
 */
class Migrant : public Bird {
protected:
    /**Місяць відльоту у вирій*/
    enum Month departure;
    /**Місяць прибуття з вирію*/
    enum Month arrival;
public:
    Migrant();
    Migrant (bool LOTR, string name, int age, struct Home home, enum Sex sex, enum Month departure, enum Month arrival);
    virtual ~Migrant();

    Month get_departure() const{return departure;}
    Month get_arrival() const{return arrival;}

    Virtual_Bird *clone() const override final;

    char GetType() const override final;

    friend ostream& operator<<(ostream &out, const Migrant &migrant);
    friend ofstream& operator<<(ofstream &out, const Migrant &migrant);
    friend stringstream &operator>>(stringstream &in, Migrant &migrant);
    bool operator==(const Virtual_Bird *other_migrant);
    bool operator!=(const Virtual_Bird *other_migrant);
};

/**
 * @brief Клас "Екзотичний птах"
 */
class Exotic : public Bird {
protected:
    /**Мінімальна комфортна температура для життя*/
    int min_temperature;
    /**Максимальна комфортна температура для життя*/
    int max_temperature;
public:
    Exotic();
    Exotic(bool LOTR, string name, int age, Bird::Home home, enum Sex sex, int min_temperature, int max_temperature);
    virtual ~Exotic();

    int get_min_temperature() const{return min_temperature;}
    int get_max_temperature() const{return max_temperature;}

    Virtual_Bird *clone() const override final;
    char GetType() const override final;

    friend ostream& operator<<(ostream &out, const Exotic &exotic);
    friend ofstream& operator<<(ofstream &out, const Exotic &exotic);
    friend stringstream &operator>>(stringstream &in, Exotic &exotic);

};


