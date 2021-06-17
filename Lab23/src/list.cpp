#include "list.h"



CList::CList() {
    list = nullptr;
    N = 0;
//    cout << "Default constructor was called for Clist" << endl;
}

CList::~CList() {
    delete [] list;
//    cout << "Destructor was called for Bird" << endl;
}

//////////////////////////////////////////////////////////////////////////////

void CList::Add_Bird(const Bird &bird) {
    auto *new_list = new Bird[N + 1];

    copy(list, list + N, new_list);
    new_list[N] = bird;

    delete [] list;
    list = new_list;
    N++;
}

void CList::Delete_Bird(int index){
    auto *new_list = new Bird[N - 1];
    if (index != 0) {
        copy(list, (list + index), new_list);
    }
    if (index < (int) N - 1) {
        copy((list + index + 1), (list + N), new_list + index);
    }

    delete [] list;
    list = new_list;
    N--;
}

Bird &CList::Get_Bird(const int index) const {
    if (this->list == nullptr) {
        cout << "List is \"NULL\"";
        exit(1);
    } else
    return list[index];
}

void CList::Print_All() const {
    for (int i = 0; i < N; ++i) {
        Get_Bird(i).Print();
    }
}

double CList::Find_Sex_Ratio() const{
    double counter_male = 0, counter_female = 0;
    double result;
    for(int i = 0; i < N; i++){
        if (Get_Bird(i).get_Sex() == Male) {
            counter_male++;
        } else if (Get_Bird(i).get_Sex() == Female) {
            counter_female++;
        }
    }
    result = (double) (counter_female / counter_male) * 100;
    printf("\nFemale to male ratio is %2.2f%%\n\n", result);
    return result;
}

int CList::Get_N() const {
    return this->N;
}
