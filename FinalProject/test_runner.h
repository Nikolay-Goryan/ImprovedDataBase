//
//  test_runner.h
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//



#pragma once

#include "condition_parser.h"



class TestRunner {
public:
    void RunTest(void (*f)(), const string& message) {
        
    }
    
};

void TestParseCondition();

void AssertEqual(const string& event1, const string& event2, const string& message);

void AssertEqual(vector<string> events1, vector<string> events2, const string& message);
