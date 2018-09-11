//
//  My_stack.h
//  programming assignment2
//
//  Created by Susan Wang on 7/20/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef My_stack_h
#define My_stack_h

#include <iostream>
#include <vector>

using namespace std;

class My_stack {
private:
    vector<int> stack_data;
public:
    My_stack();
    void push(int item);
    int top();
    int pop();
    bool empty();
};

#endif /* My_stack_h */
