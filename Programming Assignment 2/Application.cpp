//
//  Application.cpp
//  programming assignment2
//
//  Created by Susan Wang on 7/20/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include "My_stack.h"

using namespace std;

vector<int> spans1(vector<int> x) {
    vector<int> s;
    for (int i = 0; i < x.size(); i++) {
        int j = 1;
        while (j <= i && x.at(i - j) <= x.at(i))
            j = j + 1;
        s.push_back(j);
    }
    return s;
}

vector<int> spans2(vector<int> x) {
    My_stack stack;
    vector<int> s;
    for (int i = 0; i < x.size(); i++) {
        while (!stack.empty()) {
            if (x.at(i) >= x.at(stack.top()))
                stack.pop();
            else break;
        }
        
        int j = -1;
        if (!stack.empty())
            j = stack.top();
        s.push_back(i - j);
        stack.push(i);
    }
    
    return s;
}

void outputSpan(vector<int> s) {
    for (int i = 0; i < s.size()-1; i++) {
        cout << s.at(i) << ", ";
    }
    cout << s.at(s.size()-1) << endl;
}

int main() {
    cout << "-------- testing stack class --------" << endl;
    My_stack stack;
    cout << endl << "*** testing push, pop, top operations ***" << endl;
    stack.push(6);
    cout << "now the stack is: 6, the top of stack is " << stack.top() << endl;
    stack.push(3);
    cout << "now the stack is: 6, 3(top of stack), the top of stack is " << stack.top() << endl;
    cout << "the element pop from stack is " << stack.pop() << endl;
    cout << "now the stack is: 6, the top of stack is " << stack.top() << endl;
    stack.push(4);
    cout << "now the stack is: 6, 4(top of stack), the top of stack is " << stack.top() << endl;
    
    cout << endl << "*** testing empty operation ***" << endl;
    cout  << "now the stack is not empty, emtpy operation should return 0: " << stack.empty() << endl;
    cout << "the element pop from stack is " << stack.pop() << endl;
    cout << "the element pop from stack is " << stack.pop() << endl;
    cout  << "now the stack is empty, emtpy operation should return 1: " << stack.empty() << endl;
    
    cout << endl << "*** testing exception: accessing an empty stack top ***" << endl;
    try{
        cout << stack.top() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    cout << endl << "*** testing exception: pop an empty stack ***" << endl;
    try{
        cout << "the element pop from stack is " << stack.pop() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    cout << endl << "-------- testing span algorithm1 and span algorithm2 --------" << endl;
    
    vector<int> v1 = {6, 3, 4, 5, 2};    
    cout << endl << "vector v1 is ";
    for (auto& i : v1) cout << i << ' ';
    cout << endl;
    
    cout << "Spans1 of the vector v1 is: ";
    outputSpan(spans1(v1));
    cout << "Spans2 of the vector v1 is: ";
    outputSpan(spans2(v1));
    
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << endl << "vector v2 is ";
    for (auto& i : v2) cout << i << ' ';
    cout << endl;
    
    cout << "Spans1 of the vector v2 is: ";
    outputSpan(spans1(v2));
    cout << "Spans2 of the vector v2 is: ";
    outputSpan(spans2(v2));

    vector<int> v3 = {1, 85, 46, 53, 72, 99};
    cout << endl << "vector v3 is ";
    for (auto& i : v3) cout << i << ' ';
    cout << endl;
    
    cout << "Spans1 of the vector v3 is: ";
    outputSpan(spans1(v3));
    cout << "Spans2 of the vector v3 is: ";
    outputSpan(spans2(v3));

    return 0;
}
