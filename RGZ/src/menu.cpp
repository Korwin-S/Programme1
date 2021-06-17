/**
 * @file menu.cpp
 * @brief Файл з описом методів класа-меню
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "menu.h"

/**
 * @brief Конструктор класу {@link Menu}
 */
Menu::Menu() = default;

/**
 * @brief Деструктор класу {@link Menu}
 */
Menu::~Menu() = default;

/**
 * @brief Метод, що виконує перевірку вхідних даних для додання/видалення/отримання по індексу певного елементу,
 * щоб уникнути виключних ситуацій
 * @param index Номер елементу
 * @param N Кількість елементів у списку
 * @param situation_code Номер операції додання/видалення/отримання елементу,
 * завдяки якому метод розуміє, за якими критеріями перевіряти вхідні дані
 * @return Результат перевірки
 */
bool Menu::Index_Check(int index, int N, const int situation_code) const {
    switch (situation_code) {
        case 0:
            if (N == -1) {
                cout << "\nError: List is empty\n";
                return false;
            } else
            if (index > N || index < 0) {
                cout << "\nError: Wrong index. Please try again\n";
                return false;
            } else
                return true;
        case 1:
            if (N == -1) N++;
            if (index > N || index < 0) {
                cout << "\nError: Wrong index. Please try again\n";
                return false;
            } else
                return true;
        default: {
            cout << "Index check error";
            return false;
        }
    }
}

/**
 * @brief Функція виконує очищення вхідного потоку cin
 */
void Clear_cin(){
    cin.clear();
    cin.ignore(32767,'\n');
}

/**
 * @brief Метод, що демонструє роботу розроблених методів класу {@link CList}
 * @return 0 - код успішного виконання методу
 */
int Menu::For_List() const{
    CList List;
    Bird bird1 {false, "Cockoo", 123, {444, 9, 2, true}, Female};
    Bird bird2 {true, "Sparrow", 37, {800, 15, 0, false}, Male};
    Bird bird3 {true, "Pigeon", 46, {763, 81, 3, true}, Male};
    Bird bird4 {false, "Eagle", 890, {2780, 10, 5, true}, Male};

    while (true) {
        int action;
        cout << "\n|--------------------------------------------------------------------|\n";
        cout << " Choose an action: \n";
        cout << "\t1. Start filling\n";
        cout << "\t2. Print all\n";
        cout << "\t3. Get element by index\n";
        cout << "\t4. Get amount of elements in list\n";
        cout << "\t5. Add element\n";
        cout << "\t6. Delete element\n";
        cout << "\t7. Clear list\n";
        cout << "\t8. Exit\n";
        cout << "|--------------------------------------------------------------------|\n\n";
        cout << " --> ";
        cin >> action;
        switch (action) {
            case 1:
                List.Add_Bird(&bird1);
                List.Add_Bird(&bird2);
                List.Add_Bird(&bird3);
                cout << "\nList successfully filled\n";
                break;
            case 2:
                cout << "\nList:\n";
                List.Print_All();
                break;
            case 3:
                cout << "Enter element index (start from 0)\n";
                cout << " --> ";
                int index;
                cin >> index;
                Clear_cin();
                if (!Index_Check(index, List.Get_N(), 0)) continue;
                cout << "\nAsked element:\n";
                List.Get_Bird_by_index(index)->Print();
                break;
            case 4:
                cout << "Amount of elements in list: " << List.Get_N() + 1 << endl;
                break;
            case 5:
                cout << "Element, that will be added:\n";
                bird4.Print();
                cout << "\nEnter position where you want to insert\n";
                cout << " --> ";
                int index1;
                cin >> index1;
                Clear_cin();
                if (!Index_Check(index1, List.Get_N(), 1)) continue;
                List.Add_Bird_by_index(&bird4, index1);
                cout << "\nElement successfully added\n";
                break;
            case 6:
                cout << "\nEnter position where you want to delete\n";
                cout << " --> ";
                int index2;
                cin >> index2;
                Clear_cin();
                if (!Index_Check(index2, List.Get_N(), 0)) continue;
                List.Delete_Bird(index2);
                cout << "\nElement successfully deleted\n";
                break;
            case 7:
                List.Clear_List();
                cout << "\nList successfully cleared\n";
                break;
            case 8:
                List.Clear_List();
                cout << "\nShutting down...\n";
                return 0;
            default:
                cout << "\nERROR: You entered an incorrect number\n";
                Clear_cin();
                break;
        }
    }
}

/**
 * @brief Метод, що демонструє роботу розроблених методів класу {@link Controller}
 * @return 0 - код успішного виконання методу
 */
int Menu::For_Controller() const {
//    Bird bird1 {false, "Cockoo", 123, {444, 9, 2, true}, Female};
//    Bird bird2 {true, "Sparrow", 37, {800, 15, 0, false}, Male};
//    Bird bird3 {true, "Pigeon", 46, {763, 81, 3, true}, Male};
//    Bird bird4 {false, "Eagle", 890, {2780, 10, 5, true}, Male};
//
//    Migrant migrant1 {false, "Parrot", 100, {2180, 15, 1, false}, Male, October, January};
//    Migrant migrant2 {true, "Duck", 333, {218, 75, 7, false}, Female, March, July};
//

    Controller List;
    while (true) {
        int action;
        cout << "\n|--------------------------------------------------------------------|\n";
        cout << " Choose an action: \n";
        cout << "\t1. Read list from file\n";
        cout << "\t2. Print all\n";
        cout << "\t3. Find sex ratio\n";
        cout << "\t4. Find average age of non-ringed birds\n";
        cout << "\t5. Find bird with longest wintering\n";
        cout << "\t6. Sort list\n";
        cout << "\t7. Write list to file\n";
        cout << "\t8. Clear list\n";
        cout << "\t9. Exit\n";
        cout << "|--------------------------------------------------------------------|\n\n";
        cout << " --> ";
        cin >> action;
        switch (action) {
            case 1:{
                cout << "Enter input file name\n";
                cout << " --> ";
                string filename;
                cin >> filename;
                List.Read_From_File(filename);
                cout << "\nList successfully filled\n";
                break;}
            case 2:
                cout << "\nList:\n";
                List.Print_All();
                break;
            case 3:
                List.Find_Sex_Ratio();
                break;
            case 4:
                List.Find_Average_Age_of_not_LOTR();
                break;
            case 5:
                List.Find_Bird_With_Longest_Wintering();
                break;
            case 6:{
                cout << "\nDo you want to invert sort direction? (Yes/No)\n";
                cout << " --> ";
                string answer;
                cin >> answer;
                cout << " Choose your criterion: \n";
                cout << "\t1. Ringed or not ringed\n";
                cout << "\t2. Name\n";
                cout << "\t3. Age\n";
                cout << "\t4. Space of home\n";
                cout << "\t5. Height of home\n";
                cout << "\t6. Count of feeders in home\n";
                cout << "\t7. Is home a nest\n";
                cout << "\t8. Sex\n";
                cout << "\t9. Departure month\n";
                cout << "\t10. Arrival month\n";
                cout << "\t11. Minimal living temperature\n";
                cout << "\t12. Maximal living temperature\n";
                cout << "\t13. I'm afraid and want to exit\n";
                cout << " --> ";
                int criterion = 1;
                bool direction = false;
                cin >> criterion;
                Clear_cin();
                if (answer == "Yes" || answer == "yes") direction = true;
                if (criterion == 13) continue;
                List.Sort(direction, criterion - 1);
                cout << "\nList successfully sorted\n";
                break;}
            case 7:{
                cout << "Enter output file name\n";
                cout << " --> ";
                string filename;
                cin >> filename;
                List.Write_To_File(filename);
                cout << "\nList successfully writed to output file\n";
                break;}
            case 8:
                List.Clear_List();
                cout << "\nList successfully cleared\n";
                break;
            case 9:
                List.Clear_List();
                cout << "\nShutting down...\n";
                return 0;
            default:
                cout << "\nERROR: You entered an incorrect number\n";
                Clear_cin();
                break;
        }
    }
}

/**
 * @brief Метод, що, в залежності від вибору користувача, викликає відповідні методи
 * для роботи з класом {@link CList} або класом {@link Controller}
 */
void Menu::Call_Dialog_Menu(){
    bool flag = true;
    while (flag) {
        int action = 0;
        cout << "\nWhich class you prefer to work?\n";
        cout << "\t1. List\n";
        cout << "\t2. Controller\n";
        cout << " --> ";
        cin >> action;
        Clear_cin();
        switch (action) {
            case 1:
                For_List();
                flag = false;
                break;
            case 2:
                For_Controller();
                flag = false;
                break;
            default:
                cout << "\nERROR: You entered an incorrect number\n";
                continue;
        }
    }
}



