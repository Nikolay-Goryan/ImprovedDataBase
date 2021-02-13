//
//  node.cpp
//  FinalProject
//
//  Created by Николай Горян on 12/02/2019.
//  Copyright © 2019 Николай Горян. All rights reserved.
//

#include "node.h"



DateComparisonNode::DateComparisonNode(const Comparison& cmp, Date date) : cmp_(cmp), date_(date) {};

EventComparisonNode::EventComparisonNode(const Comparison& cmp, string event) : cmp_(cmp), event_(event) {};

LogicalOperationNode :: LogicalOperationNode(const LogicalOperation& logical_operation, shared_ptr<Node> left, shared_ptr<Node> right) : logical_operation_(logical_operation), left_(left), right_(right) {};



bool  EmptyNode::Evaluate(const Date& date , const string& event) {
    return true;
}



bool DateComparisonNode::Evaluate(const Date& date, const string& event = "") {
    if(cmp_ == Comparison::Less) {
        return date < date_;
    } else if(cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    } else if(cmp_ == Comparison::Greater) {
        return !(date <= date_);
    } else if(cmp_ == Comparison::GreaterOrEqual) {
        return !(date < date_);
    } else if(cmp_ == Comparison::Equal) {
        return date == date_;
    } else if(cmp_ == Comparison::NotEqual) {
        return !(date == date_);
    }
    cout << "Mistake in DateComparisonNode::Evaluate" << endl;
    return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
    if(cmp_ == Comparison::Less) {
        return event < event_;
    } else if(cmp_ == Comparison::LessOrEqual) {
        return event <= event_;
    } else if(cmp_ == Comparison::Greater) {
        return !(event <= event_);
    } else if(cmp_ == Comparison::GreaterOrEqual) {
        return !(event < event_);
    } else if(cmp_ == Comparison::Equal) {
        return event == event_;
    } else if(cmp_ == Comparison::NotEqual) {
        return !(event == event_);
    }
    cout << "Mistake in EventComparisonNode::Evaluate" << endl;
    return false;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
    bool left_result = left_ -> Evaluate(date, event);
    bool right_result = right_ -> Evaluate(date, event);
    if(logical_operation_ == LogicalOperation::Or) {
        return left_result || right_result;
    } else if(logical_operation_ == LogicalOperation::And) {
        return left_result && right_result;
    }
    cout << "Mistake in LogicalOperationNode::Evaluate" << endl;
    return false;
}


//2017-11-20 Monday
//2017-11-21 Tuesday
//2017-11-21 Weekly meeting
//2017-11-20 Monday
//2017-11-21 Tuesday
//Found 2 entries
//2017-11-21 Weekly meeting
//Removed 2 entries
//2017-11-20 Monday
//No entries

//Add 2017-11-21 Tuesday
//Add 2017-11-20 Monday
//Add 2017-11-21    Weekly meeting
//Print
//Find event != "Weekly meeting"
//Last 2017-11-30
//Del date > 2017-11-20
//Last 2017-11-30
//Last 2017-11-01
