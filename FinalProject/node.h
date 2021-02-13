//
//  node.h
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#pragma once

#include "date.h"
#include "extra_date.h"
#include <memory>

using namespace std;


enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And,
};


class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};


class EmptyNode : public  Node {
    
    bool Evaluate(const Date& date , const string& event = "") override;
    
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, Date date);
    
    bool Evaluate(const Date& date, const string& event) override;
    
private:

    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    
    EventComparisonNode(const Comparison& cmp, string event);
    
    bool Evaluate(const Date& date, const string& event) override;
    
private:
    Comparison cmp_;
    string event_;
    
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& logical_operation, shared_ptr<Node> left, shared_ptr<Node> right);
    bool Evaluate(const Date& date, const string& event) override;
    
private:
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
    LogicalOperation logical_operation_;
    
};

