//
//  date.h
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//
#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;


class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day);
    
    int GetYear() const ;
    int GetMonth() const ;
    int GetDay() const ;
    
private:
    int year;
    int month;
    int day;
};


Date ParseDate(istream& date);

ostream& operator<<(ostream& stream, const Date& date);


