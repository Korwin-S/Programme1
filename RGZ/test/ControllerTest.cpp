/**
 * @file ControllerTest.cpp
 * @brief Файл з описом методів класа-теста
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "ControllerTest.h"

/**
 * @brief Конструктор класа {@link ControllerTest}
 */
ControllerTest::ControllerTest() : result(true) {}
/**
 * @brief Деструктор класа {@link ControllerTest}
 */
ControllerTest::~ControllerTest() {}

/**
 * @brief Метод, тестує метод {@link Find_Sex_Ratio} класа {@link Controller}
 */
void ControllerTest::Test_Find_Sex_Ratio() {
    cout << "\nTesting Find_Sex_Ratio function:";
    Controller List;
    Bird bird1 {false, "Cockoo", 123, {444, 9, 2, true}, Male};
    Bird bird2 {true, "Sparrow", 37, {800, 15, 0, false}, Female};
    Migrant migrant1 {false, "Seagull", 100, {2180, 15, 1, false}, Male, October, January};
    Migrant migrant2 {false, "Eagle", 890, {2780, 10, 5, true}, Male, June, December};
    Exotic exotic2 {true, "Pigeon", 287, {296, 70, 6, true}, Male, -15, 16};

    List.Add_Bird(&bird1);
    List.Add_Bird(&bird2);
    List.Add_Bird(&migrant1);
    List.Add_Bird(&exotic2);
    List.Add_Bird(&migrant2);

    double expected_ratio = 25;
    if (expected_ratio == List.Find_Sex_Ratio()) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        result = false;
    }
}

/**
 * @brief Метод, тестує метод {@link Find_Average_Age_of_not_LOTR} класа {@link Controller}
 */
void ControllerTest::Test_Find_Average_Age_of_not_LOTR() {
    cout << "\nTesting Find_Average_Age_of_not_LOTR function:";
    Controller List;
    Bird bird1 {false, "Cockoo", 124, {444, 9, 2, true}, Female};
    Bird bird2 {true, "Sparrow", 37, {800, 15, 0, false}, Male};
    Migrant migrant1 {false, "Seagull", 100, {2180, 15, 1, false}, Male, October, January};
    Exotic exotic2 {true, "Pigeon", 283, {296, 70, 6, true}, Female, -15, 16};

    List.Add_Bird(&bird1);
    List.Add_Bird(&bird2);
    List.Add_Bird(&migrant1);
    List.Add_Bird(&exotic2);

    double expected_age = (double) (bird1.get_age() + migrant1.get_age()) / 2;
    if (expected_age == List.Find_Average_Age_of_not_LOTR()) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        result = false;
    }
}

/**
 * @brief Метод, тестує метод {@link Find_Bird_With_Longest_Wintering} класа {@link Controller}
 */
void ControllerTest::Test_Find_Bird_With_Longest_Wintering() {
    cout << "\nTesting Find_Bird_With_Longest_Wintering function:\n";
    Controller List;
    Bird bird1 {false, "Cockoo", 123, {444, 9, 2, true}, Female};
    Bird bird2 {true, "Sparrow", 37, {800, 15, 0, false}, Male};
    Migrant migrant1 {false, "Seagull", 100, {2180, 15, 1, false}, Male, October, January};
    Migrant migrant2 {true, "Albatross", 333, {218, 75, 7, false}, Female, March, July};
    Migrant migrant3 {false, "Eagle", 890, {2780, 10, 5, true}, Male, June, December};
    Exotic exotic2 {true, "Pigeon", 286, {296, 70, 6, true}, Female, -15, 16};

    List.Add_Bird(&bird1);
    List.Add_Bird(&bird2);
    List.Add_Bird(&migrant1);
    List.Add_Bird(&exotic2);
    List.Add_Bird(&migrant2);
    List.Add_Bird(&migrant3);

    if (migrant3 == List.Find_Bird_With_Longest_Wintering()) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        result = false;
    }
}

/**
 * @brief Метод, тестує метод {@link Sort} класа {@link Controller}
 */
void ControllerTest::Test_Sort(){
    cout << "\nTesting Sort function:\n";
    Controller List;
    Bird bird1 {false, "Cockoo", 123, {444, 9, 2, true}, Female};
    Bird bird2 {true, "Seagull", 37, {800, 15, 0, false}, Male};
    Migrant migrant1 {false, "Sparrow", 100, {2180, 15, 1, false}, Male, October, January};
    Migrant migrant2 {true, "Albatross", 333, {218, 75, 7, false}, Female, March, July};
    Migrant migrant3 {false, "Eagle", 890, {2780, 10, 5, true}, Male, June, December};
    Exotic exotic2 {true, "Pigeon", 286, {296, 70, 6, true}, Female, -15, 16};

    List.Add_Bird(&bird1);
    List.Add_Bird(&bird2);
    List.Add_Bird(&migrant1);
    List.Add_Bird(&exotic2);
    List.Add_Bird(&migrant2);
    List.Add_Bird(&migrant3);

    List.Sort(false, 1);
    if (migrant2 == List.Get_Bird_by_index(0) && migrant1 == List.Get_Bird_by_index(5)) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        result = false;
    }
}

/**
 * @brief Метод, що виводить загальний результат тестування у консоль
 */
void ControllerTest::Print_total_result() const {
    if (result) cout << "\nAll tests complete!\n";
    else cout << "\nSomething went wrong!\n";

}



