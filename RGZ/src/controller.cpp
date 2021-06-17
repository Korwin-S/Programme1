/**
 * @file controller.cpp
 * @brief Файл з описом методів класа-контролера та класів-функторів
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "controller.h"

/**
 * @brief Конструктор класу {@link Controller}
 */
Controller::Controller() {}

/**
 * @brief Конструктор класу {@link Controller}
 */
Controller::~Controller() {
    while (!birds.empty()){
        birds.pop_back();
    }
    birds.clear();
}

/**
 * @brief Метод, що додає елемент в кінець списку
 * @param bird Елемент, що буде доданий
 */
void Controller::Add_Bird(Virtual_Bird *bird) {
    N += 1;
    birds.push_back(bird->clone());
}

/**
 * @brief Метод, що видаляє елемент зі списку за індексом
 * @param index Номер елемента у списку, що буде видалений
 */
void Controller::Delete_Bird(int index){
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
void Controller::Print_All() const {
    for (int i = 0; i <= N; ++i) {
        cout << birds[i] << endl;
    }
}

/**
 * @brief Метод, що знаходить відношення кількості самок до самців у списку та виводить його у консоль.
 * Оскільки метод знаходить пряме відношення, то, наприклад, при однаковій кількості самок і самців результом буде "100%".
 * @return Відношення кількості самок до самців у списку
 */
double Controller::Find_Sex_Ratio() const{
    double counter_male = 0, counter_female = 0;
    double result;
    for(int i = 0; i <= N; i++){
        auto * buf = (Bird*) birds[i]->clone();
        if (buf->get_Sex() == Male) {
            counter_male++;
        } else if (buf->get_Sex() == Female) {
            counter_female++;
        }
        delete buf;
    }
    result = (double) (counter_female / counter_male) * 100;
    cout << "\nFemale to male ratio is " << result << "%.\n";
    return result;
}

/**
 * @brief Метод, що знаходить середній вік усіх птахів, що не окольцьовані, та виводить його у консоль.
 * @return Середній вік усіх не окольцьованих птахів зі списку
 */
double Controller::Find_Average_Age_of_not_LOTR() const{
    double counter_age = 0, counter_amount = 0;
    double result;
    for(int i = 0; i <= N; i++){
        auto * buf = (Bird*) birds[i]->clone();
        if (!buf->get_LOTR()) {
            counter_age += buf->get_age();
            counter_amount++;
        }
        delete buf;
    }
    result = (double) (counter_age / counter_amount);
    cout << "\nAverage age of non-LOTR birds is " << result << " months.\n";
    return result;
}

/**
 * @brief Метод, що знаходить у списку птаха з найдовшею зимівлею та виводить його у консоль.
 * Якщо у списку немає мігруючих птахів, метод повідомить про це у консоль.
 * @return Птах з найдовшею зимівлею
 */
Virtual_Bird* Controller::Find_Bird_With_Longest_Wintering() const{
    int buffer_result = 0, result = 0, number_of_result = 0;
    bool flag = false;
    for(int i = 0; i <= N; i++){
        if (birds[i]->GetType() == 'M') {
            flag = true;
            auto * buf = (Migrant*) birds[i]->clone();
            buffer_result = buf->get_arrival() - buf->get_departure();
            if (buffer_result < 0) buffer_result += 12;
            if (buffer_result > result) {
                result = buffer_result;
                number_of_result = i;
            }
            delete buf;
        }
    }
    if (!flag) {
        cout << "\nNo migrant birds in list\n";
        return nullptr;
    }
    auto * buf = (Migrant*) birds[number_of_result]->clone();
    cout << "\nBird with longest wintering is:\n " << buf << endl;
    delete buf;
    return birds[number_of_result];
}

/**
 * @brief Геттер для параметра N
 * @return Кількість елементів у списку
 */
int Controller::Get_N() const {
    return this->N;
}

/**
 * @brief Метод, що повертає елемент списку за індексом
 */
Virtual_Bird* Controller::Get_Bird_by_index(const int index) const {
    if (index <= -1 || index > N) {
        cerr << "Wrong bird index";
        return nullptr;
    } else
        return birds[index];
}

/**
 * @brief Метод, що виконує перевірку вхідних даних за допомогою регулярних виразів при читанні з файлу.
 * @param str Строка з вхідними даними
 * @param type Тип птаха
 * @return Перевизначена змінна type - тип зчитаного птаха('B', 'M' або 'E'), символ '0' при порожньому рядку.
 * У випадку хибних вхідних даних виводить у консоль попередження про це та повертає символ '0'.
 */
char Controller::Regex_Check(string &str, char *type) const{
    regex reg_bird("^ ?(Yes|No|yes|no) [A-Z a-z]+ [0-9]{1,3} [0-9]{1,5} [0-9]{1,5} [0-9]{1,2} (Yes|No|yes|no) (Female|Male|female|male) ?$");
    regex reg_migrant("^ ?(Yes|No|yes|no) [A-Z a-z]+ [0-9]{1,3} [0-9]{1,5} [0-9]{1,5} [0-9]{1,2} (Yes|No|yes|no) (Female|Male|female|male) [A-Za-z]{3,9} [A-Za-z]{3,9} ?$");
    regex reg_exotic("^ ?(Yes|No|yes|no) [A-Z a-z]+ [0-9]{1,3} [0-9]{1,5} [0-9]{1,5} [0-9]{1,2} (Yes|No|yes|no) (Female|Male|female|male) -?[0-9]{1,2} -?[0-9]{1,2} ?$");
    if (regex_search(str.c_str(), reg_bird)) {
        *type = 'B';
    } else
        if (regex_search(str.c_str(), reg_migrant)) {
        *type = 'M';
    } else
        if (regex_search(str.c_str(), reg_exotic)) {
            *type = 'E';
        } else if (str == "" || str == " " || str == "\n") {
            *type = '0';
        }
        else {
            cerr << "Wrong input data in file";
            *type = '0';
        }
    return *type;
}

/**
 * @brief Метод, що зчитує дані з файла, та, у випадку коректності вхідних даних
 * (перевірка за допомогою метода {@link Regex_Check}), формує птаха та заносить його у список (метод {@link Add_Bird})
 * @param file_name Ім'я вхідного файлу
 */
void Controller::Read_From_File(const string &file_name) {
    ifstream input_file(file_name);
    if (!input_file.is_open()) {
        cerr << "Error! Can't open file " << file_name << " for reading\n";
    } else {
        //this->Clear_List();
        while (input_file) {
            char type = '0';
            string buffer;
            getline(input_file, buffer, '\n');
            Regex_Check(buffer, &type);
            if (type == '0') continue;
            if (type == 'B') {
                stringstream buffer_stream;
                buffer_stream << buffer;
                Bird temp;
                buffer_stream >> temp;
                Add_Bird(&temp);
            }
            if (type == 'M') {
                stringstream buffer_stream;
                buffer_stream << buffer;
                Migrant temp;
                buffer_stream >> temp;
                Add_Bird(&temp);
            }
            if (type == 'E') {
                stringstream buffer_stream;
                buffer_stream << buffer;
                Exotic temp;
                buffer_stream >> temp;
                Add_Bird(&temp);
            }
        }
    }
    input_file.close();
}

/**
 * @brief Метод, що виводить список у вихідний файл
 * @param file_name Ім'я вихідного файлу
 */
void Controller::Write_To_File(const string &file_name) const {
    ofstream output_file(file_name);
    if (!output_file.is_open()) {
        cerr << "Error! Can't open file " << file_name << " for writing\n";
    } else {
        for (size_t i = 0; i <= N; i++) {
            output_file << birds[i];
        }
    }
    output_file.close();
}

/**
 * @brief Метод, який очищує список
 */
void Controller::Clear_List() {
    while (!birds.empty()){
        birds.pop_back();
    }
    birds.clear();
    N = -1;
}

/**
 * @brief Конструктор класу {@link Functor}
 */
Functor::Functor() : criterion(0) {}
/**
 * @brief Деструктор класу {@link Functor}
 */
Functor::~Functor() = default;

/**
 * @brief Геттер для параметра {@link criterion}
 * @return Критерій сортування
 */
int Functor::get_criterion() const {
    return criterion;
}
/**
 * @brief Сеттер для параметра {@link criterion}
 * @param Criterion номер критерію сортування
 */
void Functor::set_criterion(const int Criterion) {
    criterion = Criterion;
}

/*
 * @brief Конструктор класу {@link Invert_Functor}
 */
//Invert_Functor::Invert_Functor() : criterion(0) {}
/*
 * @brief Деструктор класу {@link Invert_Functor}
 *//*
Invert_Functor::~Invert_Functor() = default;*/
/*
 * @brief Геттер для параметра {@link criterion}
 * @return Критерій сортування
 *//*
int Invert_Functor::get_criterion() const {
    return criterion;
}*/
/*
 * @brief Сеттер для параметра {@link criterion}
 * @param Criterion номер критерію сортування
 *//*
void Invert_Functor::set_criterion(const int Criterion) {
    criterion = Criterion;
}*/

/*
 * @brief Перевантажений оператор круглих дужок класу {@link Invert_Functor}
 * @return Результат порівняння двох птахів за критерієм {@link criterion}
 * @param A Перша птиця
 * @param B Друга птиця
 *//*
bool Invert_Functor::operator()(Virtual_Bird* A, Virtual_Bird* B) const{
    Functor functor;
    functor.set_criterion(criterion);
    return !functor(A, B);
}*/

/**
 * @brief Перевантажений оператор круглих дужок класу {@link Functor}
 * @return Результат порівняння двох птахів за критерієм {@link criterion}
 * @param A Перша птиця
 * @param B Друга птиця
 */
bool Functor::operator()(Virtual_Bird* A, Virtual_Bird* B) const{
    bool result = false;
    auto *temp1 = (Bird *) A->clone();
    auto *temp2 = (Bird *) B->clone();
    switch (criterion) {
        case 0:
            if (temp1->get_LOTR() < temp2->get_LOTR()) {
                result = true;
            }
            break;
        case 1:
            if (temp1->get_name() < temp2->get_name()) {
                result = true;
            }
            break;
        case 2:
            if (temp1->get_age() < temp2->get_age()) {
                result = true;
            }
            break;
        case 3:
            if (temp1->get_space() < temp2->get_space()) {
                result = true;
            }
            break;
        case 4:
            if (temp1->get_height() < temp2->get_height()) {
                result = true;
            }
            break;
        case 5:
            if (temp1->get_count_of_feeders() < temp2->get_count_of_feeders()) {
                result = true;
            }
            break;
        case 6:
            if (temp1->get_if_nest() < temp2->get_if_nest()) {
                result = true;
            }
            break;
        case 7:
            if (temp1->get_Sex() < temp2->get_Sex()) {
                result = true;
            }
            break;
        case 8:
            if (A->GetType() == 'M' && B->GetType() == 'M') {
                auto *temp3 = (Migrant *) A->clone();
                auto *temp4 = (Migrant *) B->clone();
                if (temp3->get_departure() < temp4->get_departure()) {
                    result = true;
                }
                delete temp3;
                delete temp4;
                break;
            }
            else if (A->GetType() == 'M' || B->GetType() == 'M') {
                if (A->GetType() == 'M') result = true;
                break;
            }
            break;
        case 9:
            if (A->GetType() == 'M' && B->GetType() == 'M') {
                auto *temp3 = (Migrant *) A->clone();
                auto *temp4 = (Migrant *) B->clone();
                if (temp3->get_arrival() < temp4->get_arrival()) {
                    result = true;
                }
                delete temp3;
                delete temp4;
                break;
            }
            else if (A->GetType() == 'M' || B->GetType() == 'M') {
                if (A->GetType() == 'M') result = true;
                break;
            }
            break;
        case 10:
            if (A->GetType() == 'E' && B->GetType() == 'E') {
                auto *temp3 = (Exotic *) A->clone();
                auto *temp4 = (Exotic *) B->clone();
                if (temp3->get_min_temperature() < temp4->get_min_temperature()) {
                    result = true;
                }
                delete temp3;
                delete temp4;
                break;
            }
            else if (A->GetType() == 'E' || B->GetType() == 'E') {
                if (A->GetType() == 'E') result = true;
                break;
            }
            break;
        case 11:
            if (A->GetType() == 'E' && B->GetType() == 'E') {
                auto *temp3 = (Exotic *) A->clone();
                auto *temp4 = (Exotic *) B->clone();
                if (temp3->get_max_temperature() < temp4->get_max_temperature()) {
                    result = true;
                }
                delete temp3;
                delete temp4;
                break;
            }
            else if (A->GetType() == 'E' || B->GetType() == 'E') {
                if (A->GetType() == 'E') result = true;
                break;
            }
            break;
        default: cerr << "Incorrect search criterion\n";
    }
    delete temp1;
    delete temp2;
    return result;
}

/**
 * @brief Метод, що сортує список за заданим критерієм та в заданому напрямі.
 * @param direction Напрям сортування
 * @param criterion Критерій сортування
 */
void Controller::Sort(bool direction, int criterion) {
    Functor functor;
    functor.set_criterion(criterion);
    std::sort(birds.begin(), birds.end(), functor);
    if (direction) {
        std::reverse(birds.begin(), birds.end());
    }
}

