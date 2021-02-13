//
//  extra_db_functy.cpp
//  FinalProject
//
//  Created by Николай Горян on 19/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#include "extra_db_functy.h"


ostream& operator<<(ostream& output, pair<Date , string> st) {
    output << st.first << " " << st.second;
    return output;
}

ostream& operator<<(ostream& output, pair<Date, vector<string>> st) {
    for(auto event: st.second) {
        output << st.first << " " << event << endl;
    }
    return output;
}
