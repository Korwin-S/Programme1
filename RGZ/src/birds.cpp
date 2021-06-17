/**
 * @file birds.cpp
 * @brief Файл з описом методів базового класа та його спадкоємців
 *
 * @author Starovoytov N.
 * @date 14-june-2021
 * @version 1.0
 */

#include "birds.h"

/**
 * @brief Конструктор за замовчуванням класу {@link Bird}
 */
Bird::Bird (): LOTR(false), name(), age(0), home{0, 0, 0, false}, enumSex(Male) {}
/**
 * @brief Конструктор з параметрами класу {@link Bird}
 */
Bird::Bird (bool LOTR, string name, int age, struct Home home, enum Sex sex): LOTR(LOTR), name(std::move(name)), age(age), home(home), enumSex(sex) {}
/**
 * @brief Деструктор класу {@link Bird}
 */
Bird::~Bird(){}

/**
 * @brief Конструктор за замовчуванням класу {@link Migrant}
 */
Migrant::Migrant(): departure(departure), arrival(arrival) {}
/**
 * @brief Конструктор з параметрами класу {@link Migrant}
 */
Migrant::Migrant(bool LOTR, string name, int age, Bird::Home home, enum Sex sex, enum Month departure, enum Month arrival)
        : Bird(LOTR, std::move(name), age, home, sex), departure(departure), arrival(arrival) {}
/**
* @brief Деструктор класу {@link Migrant}
*/
Migrant::~Migrant() = default;

/**
 * @brief Конструктор за замовчуванням класу {@link Exotic}
 */
Exotic::Exotic(): min_temperature(0), max_temperature(0) {}
/**
 * @brief Конструктор з параметрами класу {@link Exotic}
 */
Exotic::Exotic(bool LOTR, string name, int age, Bird::Home home, enum Sex sex, int min_temperature, int max_temperature)
        : Bird(LOTR, std::move(name), age, home, sex), min_temperature(min_temperature), max_temperature(max_temperature){}
/**
* @brief Деструктор класу {@link Exotic}
*/
Exotic::~Exotic() = default;


/**
 * @brief Геттер для параметра {@link LOTR}
 * @return {@link LOTR}
 */
bool Bird::get_LOTR() const {
    return this->LOTR;
}
/**
 * @brief Геттер для параметра {@link name}
 * @return {@link name}
 */
string Bird::get_name() const {
    return this->name;
}
/**
 * @brief Геттер для параметра {@link age}
 * @return {@link age}
 */
int Bird::get_age() const {
    return this->age;
}
/**
 * @brief Геттер для параметра {@link space}
 * @return {@link space}
 */
int Bird::get_space() const {
    return this->home.space;
}
/**
 * @brief Геттер для параметра {@link height}
 * @return {@link height}
 */
int Bird::get_height() const {
    return this->home.height;
}
/**
 * @brief Геттер для параметра {@link count_of_feeders}
 * @return {@link count_of_feeders}
 */
int Bird::get_count_of_feeders() const {
    return this->home.count_of_feeders;
}
/**
 * @brief Геттер для параметра {@link if_nest}
 * @return {@link if_nest}
 */
bool Bird::get_if_nest() const {
    return this->home.if_nest;
}
/**
 * @brief Геттер для параметра {@link enumSex}
 * @return {@link enumSex}
 */
Sex Bird::get_Sex() const {
    return this->enumSex;
}
/**
 * @brief Сеттер для параметра {@link LOTR}
 */
void Bird::set_LOTR(const int LOTR) {
    this->LOTR = LOTR;
}
/**
 * @brief Сеттер для параметра {@link name}
 */
void Bird::set_name(const string name) {
    this->name = name;
}
/**
 * @brief Сеттер для параметра {@link age}
 */
void Bird::set_age(const int age) {
    this->age = age;
}
/**
 * @brief Сеттер для параметра {@link space}
 */
void Bird::set_space(const int space) {
    this->home.space = space;
}
/**
 * @brief Сеттер для параметра {@link height}
 */
void Bird::set_height(const int height) {
    this->home.height = height;
}
/**
 * @brief Сеттер для параметра {@link count_of_feeders}
 */
void Bird::set_count_of_feeders(const int count_of_feeders) {
    this->home.count_of_feeders = count_of_feeders;
}
/**
 * @brief Сеттер для параметра {@link if_nest}
 */
void Bird::set_if_nest(const int if_nest) {
    this->home.if_nest = if_nest;
}
/**
 * @brief Сеттер для параметра {@link enumSex}
 */
void Bird::set_Sex(const Sex sex) {
    this->enumSex = sex;
}


/**
 * @brief Метод, що виводить інформацію про птаха у консоль
 */
void Bird::Print() {
    cout << this;
}

/**
 * @brief Метод, конвертує назву місяця з типу "enum" до типу "string"
 * @return Назва місяця у вигляді строки
 */
string enum_Month_to_String(int number) {
    switch (number) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default: {
            cerr << "Incorrect number of month";
            return "";
        }
    }
}

/**
 * @brief Метод, конвертує назву місяця з типу "string" до типу "enum"
 * @return Назва місяця у вигляді перелічуваного типу даних
 */
enum Month String_to_enum_Month(const string& month){
    if (month == "January" || month == "january") return January; else
    if (month == "February" || month == "february") return February; else
    if (month == "March" || month == "march") return March; else
    if (month == "April" || month == "april") return April; else
    if (month == "May" || month == "may") return May; else
    if (month == "June" || month == "june") return June; else
    if (month == "July" || month == "july") return July; else
    if (month == "August" || month == "august") return August; else
    if (month == "September" || month == "september") return September; else
    if (month == "October" || month == "october") return October; else
    if (month == "November" || month == "november") return November; else
    if (month == "December" || month == "december") return December; else
    {
        cerr << "Incorrect number of month";
        return January;
    }
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ostream" та "Bird"
 * @return Поток виводу з записаними даними
 */
ostream& operator<<(ostream &out, const Bird &bird) {
    if(bird.LOTR){
        out << "\nIs bird the Lord of the Ring: Yes\n";
    }else{
        out << "\nIs bird the Lord of the Ring: NO\n";
    }
    out << "Name: " << bird.name << endl;
    out << "Age: " << bird.age << " months" << endl;
    out << "   Home area:  " << bird.home.space << " sm^2\n";
    out << "   Home height:  " << bird.home.height << " sm\n";
    out << "   Home feeders amount:  " << bird.home.count_of_feeders << "\n";
    if(bird.home.if_nest == 1){
        out << "   Is bird's home a nest: Yes\n";
    }else{
        out << "   Is bird's home a nest: NO\n";
    }
    if(bird.enumSex == Male){
        out << "Sex: male\n";
    } else if(bird.enumSex == Female) {
        out << "Sex: female\n";
    }
    return out;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ofstream" та "Bird"
 * @return Поток виводу з записаними даними
 */
ofstream& operator<<(ofstream &out, const Bird &bird) {
    if(bird.LOTR){
        out << "\nYes ";
    }else{
        out << "\nNo ";
    }
    out << bird.name << " ";
    out << bird.age << " ";
    out << bird.home.space << " ";
    out << bird.home.height << " ";
    out << bird.home.count_of_feeders << " ";
    if(bird.home.if_nest){
        out << "Yes ";
    }else{
        out << "No ";
    }
    if(bird.enumSex == Male){
        out << "Male";
    } else if(bird.enumSex == Female) {
        out << "Female";
    }
    return out;
}

/**
 * @brief Перевантажений оператор вводу для вхідних даних типу "stringstream" та "Bird"
 * @return Поток вводу з записаними даними
 */
stringstream &operator>>(stringstream &in, Bird &bird) {
    string sex, LOTR, if_nest;
    in >> LOTR >> bird.name >> bird.age >> bird.home.space >> bird.home.height
            >> bird.home.count_of_feeders >> if_nest >> sex;
    if (LOTR == "Yes" || LOTR == "yes") bird.LOTR = true;
    else bird.LOTR = false;
    if (if_nest == "Yes" || if_nest == "yes") bird.home.if_nest = true;
    else bird.home.if_nest = false;
    if(sex == "male" || sex == "Male") bird.enumSex = Male;
    else if(sex == "female" || sex == "Female") bird.enumSex = Female;
    return in;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ostream" та "Migrant"
 * @return Поток виводу з записаними даними
 */
ostream &operator<<(ostream &out, const Migrant &migrant) {
    if(migrant.LOTR){
        out << "\nIs bird the Lord of the Ring: Yes\n";
    }else{
        out << "\nIs bird the Lord of the Ring: NO\n";
    }
    out << "Name: " << migrant.name << endl;
    out << "Age: " << migrant.age << " months" << endl;
    out << "   Home area:  " << migrant.home.space << " sm^2\n";
    out << "   Home height:  " << migrant.home.height << " sm\n";
    out << "   Home feeders amount:  " << migrant.home.count_of_feeders << "\n";
    if(migrant.home.if_nest == 1){
        out << "   Is bird's home a nest: Yes\n";
    }else{
        out << "   Is bird's home a nest: NO\n";
    }
    if(migrant.enumSex == Male){
        out << "Sex: male\n";
    } else if(migrant.enumSex == Female) {
        out << "Sex: female\n";
    }
    out << "Departure month: " << enum_Month_to_String(migrant.get_departure()) << endl;
    out << "Arrival month: " << enum_Month_to_String(migrant.get_arrival()) << endl;
    return out;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ofstream" та "Migrant"
 * @return Поток виводу з записаними даними
 */
ofstream &operator<<(ofstream &out, const Migrant &migrant) {
    if(migrant.LOTR){
        out << "\nYes ";
    }else{
        out << "\nNo ";
    }
    out << migrant.name << " ";
    out << migrant.age << " ";
    out << migrant.home.space << " ";
    out << migrant.home.height << " ";
    out << migrant.home.count_of_feeders << " ";
    if(migrant.home.if_nest){
        out << "Yes ";
    }else{
        out << "No ";
    }
    if(migrant.enumSex == Male){
        out << "Male ";
    } else if(migrant.enumSex == Female) {
        out << "Female ";
    }
    out << enum_Month_to_String(migrant.get_departure()) << " ";
    out << enum_Month_to_String(migrant.get_arrival());
    return out;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ostream" та "Exotic"
 * @return Поток виводу з записаними даними
 */
ostream &operator<<(ostream &out, const Exotic &exotic) {
    if(exotic.LOTR){
        out << "\nIs exotic the Lord of the Ring: Yes\n";
    }else{
        out << "\nIs exotic the Lord of the Ring: NO\n";
    }
    out << "Name: " << exotic.name << endl;
    out << "Age: " << exotic.age << " months" << endl;
    out << "   Home area:  " << exotic.home.space << " sm^2\n";
    out << "   Home height:  " << exotic.home.height << " sm\n";
    out << "   Home feeders amount:  " << exotic.home.count_of_feeders << "\n";
    if(exotic.home.if_nest == 1){
        out << "   Is exotic's home a nest: Yes\n";
    }else{
        out << "   Is exotic's home a nest: NO\n";
    }
    if(exotic.enumSex == Male){
        out << "Sex: male\n";
    } else if(exotic.enumSex == Female) {
        out << "Sex: female\n";
    }
    out << "Minimum comfort temperature: " << exotic.min_temperature << endl;
    out << "Maximum comfort temperature: " << exotic.max_temperature << endl;
    return out;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ofstream" та "Exotic"
 * @return Поток виводу з записаними даними
 */
ofstream &operator<<(ofstream &out, const Exotic &exotic) {
    if(exotic.LOTR){
        out << "\nYes ";
    }else{
        out << "\nNo ";
    }
    out << exotic.name << " ";
    out << exotic.age << " ";
    out << exotic.home.space << " ";
    out << exotic.home.height << " ";
    out << exotic.home.count_of_feeders << " ";
    if(exotic.home.if_nest){
        out << "Yes ";
    }else{
        out << "No ";
    }
    if(exotic.enumSex == Male){
        out << "Male ";
    } else if(exotic.enumSex == Female) {
        out << "Female ";
    }
    out << exotic.min_temperature << " ";
    out << exotic.max_temperature;
    return out;
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ostream" та "Virtual_Bird"
 * @return Поток виводу з записаними даними
 */
ostream &operator<<(ostream &out, const Virtual_Bird *bird) {
    switch (bird->GetType()) {
        case 'B':
        {   auto * buf = (Bird*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        case 'M':
        {   auto * buf = (Migrant*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        case 'E':
        {
            auto * buf = (Exotic*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        default: cout << "Invalid bird type"; return out;
    }
}

/**
 * @brief Перевантажений оператор виводу для вхідних даних типу "ofstream" та "Virtual_Bird"
 * @return Поток виводу з записаними даними
 */
ofstream &operator<<(ofstream &out, const Virtual_Bird *bird) {
    switch (bird->GetType()) {
        case 'B':
        {   auto * buf = (Bird*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        case 'M':
        {   auto * buf = (Migrant*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        case 'E':
        {
            auto * buf = (Exotic*) bird->clone();
            out << *buf;
            delete buf;
            return out;}
        default: cout << "Invalid bird type"; return out;
    }
}

/**
 * @brief Перевантажений оператор вводу для вхідних даних типу "stringstream" та "Migrant"
 * @return Поток вводу з записаними даними
 */
stringstream &operator>>(stringstream &in, Migrant &migrant) {
    string sex, LOTR, if_nest, departure, arrival;
    in >> LOTR >> migrant.name >> migrant.age >> migrant.home.space >> migrant.home.height
       >> migrant.home.count_of_feeders >> if_nest >> sex >> departure >> arrival;

    if (LOTR == "Yes" || LOTR == "yes") migrant.LOTR = true;
    else migrant.LOTR = false;
    if (if_nest == "Yes" || if_nest == "yes") migrant.home.if_nest = true;
    else migrant.home.if_nest = false;
    if(sex == "male" || sex == "Male") migrant.enumSex = Male;
    else if(sex == "female" || sex == "Female") migrant.enumSex = Female;
    migrant.departure = String_to_enum_Month(departure);
    migrant.arrival = String_to_enum_Month(arrival);

    return in;
}

/**
 * @brief Перевантажений оператор вводу для вхідних даних типу "stringstream" та "Exotic"
 * @return Поток вводу з записаними даними
 */
stringstream &operator>>(stringstream &in, Exotic &exotic) {
    string sex, LOTR, if_nest;
    in >> LOTR >> exotic.name >> exotic.age >> exotic.home.space >> exotic.home.height
       >> exotic.home.count_of_feeders >> if_nest >> sex >> exotic.min_temperature >> exotic.max_temperature;

    if (LOTR == "Yes" || LOTR == "yes") exotic.LOTR = true;
    else exotic.LOTR = false;
    if (if_nest == "Yes" || if_nest == "yes") exotic.home.if_nest = true;
    else exotic.home.if_nest = false;
    if(sex == "male" || sex == "Male") exotic.enumSex = Male;
    else if(sex == "female" || sex == "Female") exotic.enumSex = Female;

    return in;
}

/**
 * @brief Перевантажений оператор порівняння для вхідних даних типу "Bird"
 * @return Результат порівняння
 */
bool Bird::operator==(const Bird *other_bird){
     return this->LOTR == other_bird->LOTR &&
            this->age == other_bird->age &&
            this->name == other_bird->name &&
            this->enumSex == other_bird->enumSex &&
            this->home.if_nest == other_bird->home.if_nest &&
            this->home.space == other_bird->home.space &&
            this->home.height == other_bird->home.height &&
            this->home.count_of_feeders == other_bird->home.count_of_feeders;
}

/**
 * @brief Перевантажений оператор інвертованого порівняння для вхідних даних типу "Bird"
 * @return Результат порівняння
 */
bool Bird::operator!=(const Bird *other_bird) {
    return !(this == other_bird);
}

/**
 * @brief Перевантажений оператор порівняння для вхідних даних типу "Migrant" та "Virtual_Bird"
 * @return Результат порівняння
 */
bool Migrant::operator==(const Virtual_Bird *other_migrant_bird) {
    auto * other_migrant = (Migrant*) other_migrant_bird->clone();
    return this->LOTR == other_migrant->LOTR &&
           this->age == other_migrant->age &&
           this->name == other_migrant->name &&
           this->enumSex == other_migrant->enumSex &&
           this->home.if_nest == other_migrant->home.if_nest &&
           this->home.space == other_migrant->home.space &&
           this->home.height == other_migrant->home.height &&
           this->home.count_of_feeders == other_migrant->home.count_of_feeders &&
           this->departure == other_migrant->departure &&
           this->arrival == other_migrant->arrival;
}

/**
 * @brief Перевантажений оператор інвертованого порівняння для вхідних даних типу "Migrant" та "Virtual_Bird"
 * @return Результат порівняння
 */
bool Migrant::operator!=(const Virtual_Bird *other_migrant) {
    return !(this == other_migrant);
}

/**
 * @brief Перевантажений метод клонування елементу для класу {@link Bird}
 * @return Новий елемент, що є копією даного
 */
Virtual_Bird* Bird::clone() const {
    return (Virtual_Bird*) new Bird(*this);
}

/**
 * @brief Перевантажений метод клонування елементу для класу {@link Migrant}
 * @return Новий елемент, що є копією даного
 */
Virtual_Bird *Migrant::clone() const {
    return (Virtual_Bird*) new Migrant(*this);
}

/**
 * @brief Перевантажений метод клонування елементу для класу {@link Exotic}
 * @return Новий елемент, що є копією даного
 */
Virtual_Bird *Exotic::clone() const {
    return (Virtual_Bird*) new Exotic(*this);
}

/**
 * @brief Перевантажений метод класу {@link Bird}, що слугує для ідентифікації типу птиха
 * @return Символ 'B'
 */
char Bird::GetType() const {
    return 'B';
}
/**
 * @brief Перевантажений метод класу {@link Migrant}, що слугує для ідентифікації типу птиха
 * @return Символ 'M'
 */
char Migrant::GetType() const {
    return 'M';
}
/**
 * @brief Перевантажений метод класу {@link Exotic}, що слугує для ідентифікації типу птиха
 * @return Символ 'E'
 */
char Exotic::GetType() const {
    return 'E';
}









