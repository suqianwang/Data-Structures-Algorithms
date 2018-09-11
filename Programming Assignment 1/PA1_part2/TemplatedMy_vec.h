/*TemplatedMy_vec.h
Suqian Wang
Header file for a vector data structure.
*/

#ifndef TemplatedMy_vec_h
#define TemplatedMy_vec_h
#include <iostream>

using namespace std;

template <class T>
class TemplatedMy_vec {
	
	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	TemplatedMy_vec();
	~TemplatedMy_vec();
	TemplatedMy_vec(const TemplatedMy_vec& vec);
	TemplatedMy_vec& operator=(const TemplatedMy_vec& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	
};

#endif
	
template <typename T> ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec);
template <typename T> int find_max_index(const TemplatedMy_vec<T>& v,int size);
template <typename T> void sort_max(TemplatedMy_vec<T>& vec);


template<class T> TemplatedMy_vec<T>::TemplatedMy_vec():size(0), capacity(10), ptr(new T[capacity]) {}

template<class T> TemplatedMy_vec<T>::~TemplatedMy_vec() {delete[] ptr;}

template <class T> TemplatedMy_vec<T>::TemplatedMy_vec(const TemplatedMy_vec& vec):size(vec.size), capacity(vec.capacity), ptr(new T[vec.capacity]) {
    for (int i = 0; i < size; i++) {
        this->ptr[i] = vec.ptr[i];
    }
}

template <class T> TemplatedMy_vec<T>& TemplatedMy_vec<T>::operator=(const TemplatedMy_vec& vec) {
    if (this != &vec) {
        delete[] ptr;
        this->size = vec.size;
        this->capacity = vec.capacity;
        this->ptr = new T[this->capacity];
        for (int i = 0; i < vec.size; i++) {
            this->ptr[i] = vec.ptr[i];
        }
    }
    return *this;
}

template <class T> int TemplatedMy_vec<T>::get_size() const {
    return this->size;
}

template <class T> int TemplatedMy_vec<T>::get_capacity() const {
    return this->capacity;
}

template <class T> T& TemplatedMy_vec<T>::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[i];
}

template <class T> T& TemplatedMy_vec<T>::operator[](int i) {
    if (i < 0 || i >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[i];
}

template <class T> bool TemplatedMy_vec<T>::is_empty() const {
    if (size == 0) {
        return true;
    }
    return false;
}

template <class T> T& TemplatedMy_vec<T>::elem_at_rank(int r) const {
    if (r < 0 || r >= size) {
        throw out_of_range("Out of Range");
    }
    return this->ptr[r];
}

template <class T> void TemplatedMy_vec<T>::insert_at_rank(int r, const T& elem) {
    if (r < 0 || r > size) {
        throw out_of_range("Out of Range");
    }
    else {
        this->size++;
        if (this->size > capacity) {
            int new_capacity = 2 * this->capacity;
            T *new_ptr = new T[new_capacity];
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

template <class T> void TemplatedMy_vec<T>::replace_at_rank(int r, const T& elem) {
    if (r < 0 || r >= size) {
        throw out_of_range("Out of Range");
    }
    else {
        ptr[r] = elem;
    }
}

template <class T> void TemplatedMy_vec<T>::remove_at_rank(int r) {
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

template <typename T> ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec) {
    for (int i = 0; i < vec.get_size(); i++) {
        out << vec.elem_at_rank(i) << " ";
    }
    return out;
}

template <typename T> int find_max_index(const TemplatedMy_vec<T>& v,int size) {
    if (v.is_empty() == true) {
        cout << "vector is empty" << endl;
        throw;
    }
    T temp = v[0];
    int max_index = 0;
    int i = 1;
    for (; i < size; i++) {
        if (temp <= v[i]) {
            temp = v[i];
            max_index = i;
        }
    }
    return max_index;
}

template <typename T> void sort_max(TemplatedMy_vec<T>& vec) {
    if (vec.is_empty() == true) {
        cout << "vector is empty" << endl;
        throw;
    }
    T temp;
    int max_index = 0;
    for (int i = vec.get_size(); i > 0; i--) {
        temp = vec.elem_at_rank(i - 1);
        max_index = find_max_index(vec, i);
        vec.replace_at_rank(i - 1, vec.elem_at_rank(max_index));
        vec.replace_at_rank(max_index, temp);
    }
}

