/**
 * @file ControllerTest.h
 * @brief Файл з описом класа-теста
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "../src/controller.h"

/**
 * @brief Клас, що призначений для тестування класу {@link Controller}
 */
class ControllerTest {
protected:
    /** Результат тестування */
    bool result;
public:
    ControllerTest();
    virtual ~ControllerTest();

    void Test_Find_Sex_Ratio();
    void Test_Find_Average_Age_of_not_LOTR();
    void Test_Find_Bird_With_Longest_Wintering();
    void Test_Sort();
    void Print_total_result() const;
};
