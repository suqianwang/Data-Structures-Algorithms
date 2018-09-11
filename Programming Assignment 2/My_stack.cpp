//
//  My_stack.cpp
//  programming assignment2
//
//  Created by Susan Wang on 7/20/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdexcept>

#include "My_stack.h"

using namespace std;

My_stack::My_stack() {
    
}

void My_stack::push(int item) {
    stack_data.push_back(item);
}

int My_stack::top() {
    if (empty()) {
        throw runtime_error("Access to Empty Stack");
    }
    return stack_data.back();
}

int My_stack::pop() {
    if (empty()) {
        throw runtime_error("Access to Empty Stack");
    }
    int popElem = stack_data.back();
    stack_data.pop_back();
    return popElem;
}

bool My_stack::empty() {
    return stack_data.size() == 0;
}
