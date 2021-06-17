/**
 * @file menu.h
 * @brief Файл з описом класа-меню
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#pragma once

#include "controller.h"

/**
 * @brief Клас, що призначений для демонстрації роботи розроблених методів класів {@link CList} та {@link Controller}
 */
class Menu {
public:
    Menu();
    virtual ~Menu();

    int For_List() const;
    int For_Controller() const;
    bool Index_Check(int index, int N, const int situation_code) const;

    void Call_Dialog_Menu();
};

