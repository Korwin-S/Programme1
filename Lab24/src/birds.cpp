#include "birds.h"


Bird::Bird (): LOTR(false), name(), age(0), home{0, 0, 0, false}, enumSex(Male) {
//    cout << "Default constructor was called for Bird" << endl;
}

Bird::Bird (bool LOTR, string name, int age, struct Home home, enum Sex sex): LOTR(LOTR), name(std::move(name)), age(age), home(home), enumSex(sex) {
//    cout << "Constructor with parameters was called for Bird" << endl;
}

Bird::Bird(const Bird &copy) : LOTR(copy.LOTR), name(copy.name), age(copy.age), home(copy.home), enumSex(copy.enumSex) {
//    cout << "Copy constructor was called for Bird" << endl;
}

Bird::~Bird(){
//    cout << "Destructor was called for Bird" << endl;
}

bool Bird::get_LOTR() const {
    return this->LOTR;
}

string Bird::get_name() const {
    return this->name;
}

int Bird::get_age() const {
    return this->age;
}

int Bird::get_space() const {
    return this->home.space;
}

int Bird::get_height() const {
    return this->home.height;
}

int Bird::get_count_of_feeders() const {
    return this->home.count_of_feeders;
}

bool Bird::get_if_nest() const {
    return this->home.if_nest;
}

Sex Bird::get_Sex() const {
    return this->enumSex;
}

void Bird::set_LOTR(const int LOTR) {
    this->LOTR = LOTR;
}

void Bird::set_name(const string name) {
    this->name = name;
}

void Bird::set_age(const int age) {
    this->age = age;
}

void Bird::set_space(const int space) {
    this->home.space = space;
}

void Bird::set_height(const int height) {
    this->home.height = height;
}

void Bird::set_count_of_feeders(const int count_of_feeders) {
    this->home.count_of_feeders = count_of_feeders;
}

void Bird::set_if_nest(const int if_nest) {
    this->home.if_nest = if_nest;
}

void Bird::set_Sex(const Sex sex) {
    this->enumSex = sex;
}

string Bird::toString() const {
    stringstream bird_ss;
    bird_ss << "\nIs bird the Lord of the Ring: " << (this->LOTR ? "Yes\n" : "No\n")
            << "Name: " << this->name << endl
            << "Age: " << this->age << " months" << endl
            << "   Home area: " << this->home.space << " sm^2\n"
            << "   Home height: " << this->home.height << " sm\n"
            << "   Home feeders amount: " << this->home.count_of_feeders << "\n"
            << "   Is bird's home a nest: " << (this->home.if_nest ? "Yes\n" : "No\n")
            << "Sex: " << (this->enumSex ? "female\n" : "male\n");
    return bird_ss.str();
}

void Bird::FromString(const string& bird_string) {
    string sex;
    stringstream bird_ss(bird_string);
    bird_ss >> this->LOTR >> this->name >> this->age >> this->home.space >> this->home.height
    >> this->home.count_of_feeders >> this->home.if_nest >> sex;
    if(sex == "male" || sex == "Male") this->enumSex = Male;
    else if(sex == "female" || sex == "Female") this->enumSex = Female;
}

void Bird::Print_Bird_From_String(const string& bird_string) const {
    cout << bird_string << endl;
}

void Bird::Print() const {
    if(this->LOTR){
        cout << "\nIs bird the Lord of the Ring: Yes\n";
    }else{
        cout << "\nIs bird the Lord of the Ring: NO\n";
    }
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << " months" << endl;
    cout << "   Home area:  " << this->home.space << " sm^2\n";
    cout << "   Home height:  " << this->home.height << " sm\n";
    cout << "   Home feeders amount:  " << this->home.count_of_feeders << "\n";
    if(this->home.if_nest == 1){
        cout << "   Is bird's home a nest: Yes\n";
    }else{
        cout << "   Is bird's home a nest: NO\n";
    }
    if(this->enumSex == Male){
        cout << "Sex: male\n";
    } else if(this->enumSex == Female) {
        cout << "Sex: female\n";
    }
}


