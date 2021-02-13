//
//  database.cpp
//  FinalProject
//
//  Created by Nikolay Goryan on 16/02/2019.
//  Copyright © 2019 Nikolay Goryan. All rights reserved.
//

#include "database.h"
#include <unistd.h>

void Database :: Add(const Date& date, const string& event) {
    if(set_storage[date].count(event) == 0) {
        storage[date].push_back(event);
        set_storage[date].insert(event);
    }
}

ostream& Database :: Print(ostream& out) const {
    for(auto date: storage) {
        for(auto event: date.second) {
            out << date.first << " "  << event << endl;
        }
    }
    return out;
}



int Database :: RemoveIf(std::function<bool (const Date&, const string&)> predicate) {
    int count = 0;
    map<Date, vector<string>> storage_copy = storage;
    for(auto date: storage_copy) {
        vector<string>& events = date.second;
        auto p = stable_partition(events.begin(), events.end(),
                                  [date, predicate](const string& s){return !predicate(date.first, s);});

        count += events.end() - p;
        events.erase(p, events.end());

        if(events.empty()) {
            storage.erase(date.first);
            set_storage.erase(date.first);
        } else {
            storage[date.first] = events;
            set_storage[date.first] = set<string>(events.begin(), events.end());
        }

    }
    return count;
}


pair<Date, string> Database::Last(const Date& date) const {
    if (storage.empty() || date < storage.begin()->first) throw invalid_argument("");
    auto up = storage.upper_bound(date);
        --up;
    return make_pair(up->first, *up->second.rbegin());
}

vector<pair<Date, string>> Database :: FindIf(std::function<bool (const Date&, const string&)> predicate) const{
    vector<pair<Date, string>> founded_events;
    
    for(auto date: storage) {
        for(auto event: date.second) {
            if(predicate(date.first, event)) {
                founded_events.push_back(make_pair(date.first, event));
            }
        }
    }
    return founded_events;
}



