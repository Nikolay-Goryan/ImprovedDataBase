//
//  database.h
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#pragma once
#include "extra_date.h"
#include <map>
#include <deque>
#include <utility>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;





class Database {
public:
    
    void Add(const Date& date, const string& event);
    
    ostream& Print(ostream& date) const;
    int RemoveIf(std::function<bool (const Date&, const string&)> predicate);
    vector<pair<Date, string> > FindIf(std::function<bool (const Date&, const string&)> predicate) const;
    pair<Date, string> Last(const Date& date) const;
    
private:
    map<Date, vector<string> > storage;
    map<Date, set<string> > set_storage;
};


