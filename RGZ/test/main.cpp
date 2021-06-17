/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи класа {@link ControllerTest}
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "ControllerTest.h"

/**
 * **Головна функція.**
 *
 * Послідовність дій:
 * - Створення об'єкту Test класа {@link ControllerTest}
 * - Виклик тесту {@link Test_Find_Sex_Ratio}
 * - Виклик тесту {@link Test_Find_Average_Age_of_not_LOTR}
 * - Виклик тесту {@link Test_Find_Bird_With_Longest_Wintering}
 * - Виклик тесту {@link Test_Sort}
 * - Вивод загального результату тестування на екран {@link Print_total_result}
 * @return 0 - успішний код повернення з програми
 */
int main() {

    ControllerTest Test;
    Test.Test_Find_Sex_Ratio();
    Test.Test_Find_Average_Age_of_not_LOTR();
    Test.Test_Find_Bird_With_Longest_Wintering();
    Test.Test_Sort();
    Test.Print_total_result();

    return 0;
}
