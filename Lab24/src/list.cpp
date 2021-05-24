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

    std::copy(list, list + N, new_list);
    new_list[N] = bird;

    delete [] list;
    list = new_list;
    N++;
}

void CList::Add_Bird_From_String(const string& bird_string) {
    auto *bird = new Bird;
    bird->FromString(bird_string);
    auto *new_list = new Bird[N + 1];

    std::copy(list, list + N, new_list);
    new_list[N] = *bird;

    delete [] list;
    list = new_list;
    N++;
}

void CList::Delete_Bird(int index){
    auto *new_list = new Bird[N - 1];
    if (index != 0) {
        std::copy(list, (list + index), new_list);
    }
    if (index < (int32_t) N - 1) {
        std::copy((list + index + 1), (list + N), new_list + index);
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
        Get_Bird(i).Print_Bird_From_String(Get_Bird(i).toString());
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
    cout << "\nFemale to male ratio is " << result << "%\n\n";
    return result;
}

int CList::Get_N() const {
    return this->N;
}

void CList::Read_From_File(const string &file_name) {
    ifstream input_file(file_name);
    if (!input_file.is_open()) {
        cerr << "Error! Can't open file " << file_name << " for reading\n";
    } else {
        this->Clear_List();
        while (input_file) {
            string buffer;
            getline(input_file, buffer, '\n');
            if (!buffer.empty())
            Add_Bird_From_String(buffer);
        }
    }
    input_file.close();
}

void CList::Write_To_File(const string &file_name) const {
    ofstream output_file(file_name);
    if (!output_file.is_open()) {
        cerr << "Error! Can't open file " << file_name << " for writing\n";
    } else {
        for (size_t i = 0; i < N; i++) {
            output_file << Get_Bird(i).toString();
        }
    }
    output_file.close();
}

void CList::Clear_List() {
    delete [] list;
    list = nullptr;
    N = 0;
}
