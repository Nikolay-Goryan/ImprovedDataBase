//
//  extra_date.cpp
//  FinalProject
//
//  Created by Николай Горян on 19/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#include "extra_date.h"


bool operator<(const Date& lhs, const Date& rhs) {
    // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
    // создадим вектор из года, месяца и дня для каждой даты и сравним их
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
    vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
    vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
    vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
