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
};

