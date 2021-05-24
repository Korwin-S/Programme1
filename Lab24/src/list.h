#pragma once

#include "birds.h"

class CList {
private:
    Bird *list = nullptr;
    int N;
public:
    CList();
    ~CList();

    int Get_N() const;
    void Add_Bird(const Bird &bird);
    void Delete_Bird(int index);
    Bird &Get_Bird(int index) const;
    void Print_All() const;
    double Find_Sex_Ratio() const;
    void Read_From_File(const string &fileName);
    void Write_To_File(const string &fileName) const;

    void Clear_List();

    void Add_Bird_From_String(const string &bird_string);
};

