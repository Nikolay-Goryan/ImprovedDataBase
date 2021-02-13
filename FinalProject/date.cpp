//
//  date.cpp
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#include "date.h"







ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
    "-" << setw(2) << setfill('0') << date.GetMonth() <<
    "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

Date ParseDate(istream& date_stream) {
    bool ok = true;
    
    int year = 0;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int month = 0;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int day = 0;
    ok = ok && (date_stream >> day);
    
    if (!ok) {
        throw logic_error("Wrong date format: ");
    }
    return Date(year, month, day);
}


Date :: Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date :: GetYear() const {
    return year;
}
int Date :: GetMonth() const {
    return month;
}
int Date :: GetDay() const {
    return day;
}
