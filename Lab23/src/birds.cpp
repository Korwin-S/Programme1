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

void Bird::Print() {
    if(this->LOTR){
        printf("\nIs bird the Lord of the Ring: Yes\n");
    }else{
        printf("\nIs bird the Lord of the Ring: NO\n");
    }
    cout << "Name: " << this->name << endl;
    printf("Age: %d months\n", this->age);
    printf("   Home area: %d sm^2\n", this->home.space);
    printf("   Home height: %d sm\n", this->home.height);
    printf("   Home feeders amount: %d\n", this->home.count_of_feeders);
    if(this->home.if_nest == 1){
        printf("   Is bird's home a nest: Yes\n");
    }else{
        printf("   Is bird's home a nest: NO\n");
    }
    if(this->enumSex == Male){
        printf("Sex: male\n");
    } else if(this->enumSex == Female) {
        printf("Sex: female\n");
    }
}

