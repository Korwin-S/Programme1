#pragma once


#define N 5

enum Sex{
    Male,
    Female
};

/**
 * Структура «Птиця»
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
