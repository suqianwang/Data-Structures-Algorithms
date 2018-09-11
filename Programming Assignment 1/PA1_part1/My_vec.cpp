//
//  My_vec.cpp
//  Programming Assignment 1
//
//  Created by Susan Wang on 7/11/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "My_vec.h"
using namespace std;

// default constructor
My_vec::My_vec():size(0), capacity(10), ptr(new char[capacity]) {}

// destructor
My_vec::~My_vec() {delete[] ptr;}

// copy constructor
My_vec::My_vec(const My_vec& vec):size(vec.size), capacity(vec.capacity), ptr(new char[vec.capacity]) {
    for (int i = 0; i < size; i++) {
        this->ptr[i] = vec.ptr[i];
    }
}

// copy assignment
My_vec& My_vec::operator=(const My_vec& vec) {
    if (this != &vec) {
        delete[] ptr;
        this->size = vec.size;
        this->capacity = vec.capacity;
        this->ptr = new char[this->capacity];
        for (int i = 0; i < vec.size; i++) {
            this->ptr[i] = vec.ptr[i];
        }
    }
    return *this;
}

// get the size of a dynamic array
int My_vec::get_size() const {
    return this->size;
}

// get the capacity of a dynamic array
int My_vec::get_capacity() const {
    return this->capacity;
}

// overload [] const operator
char& My_vec::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[i];
}

// overload [] operator
char& My_vec::operator[](int i) {
    if (i < 0 || i >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[i];
}

// determine if the vector is empty
bool My_vec::is_empty() const {
    if (size == 0) {
        return true;
    }
    return false;
}

// get an element at a specific index
char& My_vec::elem_at_rank(int r) const {
    if (r < 0 || r >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[r];
}

// insert an element to a specific index
void My_vec::insert_at_rank(int r, const char& elem) {
    if (r < 0 || r > size) {
        throw out_of_range("Out of Range");
    }
    else {
        this->size++;
        if (this->size > capacity) {
            int new_capacity = 2 * this->capacity;
            char *new_ptr = new char[new_capacity];
            for (int i = 0; i < this->size; i++) {
                new_ptr[i] = this->ptr[i];
            }
            this->capacity = new_capacity;
            this->ptr = new_ptr;
            delete[] new_ptr;
        }
        for (int i = this->size; i > r; i--) {
            this->ptr[i] = this->ptr[i-1];
        }
        this->ptr[r] = elem;
    }
}

// replace an element at a specific index
void My_vec::replace_at_rank(int r, const char& elem) {
    if (r < 0 || r >= size) {
        throw out_of_range("Out of Range");
    }
    else {
        ptr[r] = elem;
    }
}

// remove an element at a specific index
void My_vec::remove_at_rank(int r) {
    if (r < 0 || r >= size) {
        throw out_of_range("Out of Range");
    }
    else {
        for (int i = r; i < size - 1; i++) {
            this->ptr[i] = this->ptr[i+1];
        }
        this->size--;
    }
}

// overload output operator
ostream& operator<<(ostream& out, const My_vec& vec) {
    for (int i = 0; i < vec.get_size(); i++) {
        out << vec.elem_at_rank(i) << ", ";
    }
    return out;
}

// find the index of the largest object in an array
int find_max_index(const My_vec& v,int size) {
    if (v.is_empty() == true) {
        cout << "vector is empty" << endl;
        throw;
    }
    char temp = v[0];
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (temp <= v[i]) {
            temp = v[i];
            max_index = i;
        }
    }
    return max_index;
}

// sort the array in ascending order
void sort_max(My_vec& vec) {
    if (vec.is_empty() == true) {
        cout << "vector is empty" << endl;
        throw;
    }
    char temp;
    int max_index = 0;
    for (int i = vec.get_size(); i > 0; i--) {
        temp = vec.elem_at_rank(i - 1);
        max_index = find_max_index(vec, i);
        vec.replace_at_rank(i - 1, vec.elem_at_rank(max_index));
        vec.replace_at_rank(max_index, temp);
    }
}
