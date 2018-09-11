//
//  MinQueue.h
//  part2
//
//  Created by Susan Wang on 7/27/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef MinQueue_h
#define MinQueue_h

#include <iostream>
#include <string>
#include "TemplateDoublyLinkedList.h"
using namespace std;

template<class T>
class MinQueue {
private:
    TemplateDoublyLinkedList<T> dll;
    int queueSize;
public:
    
    MinQueue(): dll(), queueSize(0) {}
    ~MinQueue() { dll.~TemplateDoublyLinkedList(); }
    bool isEmpty() const;
    int size();
    void enqueue(T elem);
    T dequeue ();
    T getMin();
    template<typename X>
    friend ostream& operator<<(ostream& out, const MinQueue<X>& queue);
};

struct QueueEmptyException: std::range_error {
    explicit QueueEmptyException(char const*msg=NULL): range_error(msg) {}
};

template<class T> bool MinQueue<T>::isEmpty() const {
    return this->dll.isEmpty();
}

template<class T> int MinQueue<T>::size() {
    return this->queueSize;
}

template<class T> void MinQueue<T>::enqueue(T elem) {
    this->dll.insertLast(elem);
    this->queueSize++;
}

template<class T> T MinQueue<T>::dequeue () {
    if (isEmpty())
        throw QueueEmptyException("Access to an empty queue");
    this->queueSize--;
    return this->dll.removeFirst();
}

template<class T>T MinQueue<T>::getMin() {
    if (isEmpty())
        throw QueueEmptyException("Access to an empty queue");
    
    DListNode<T> *current = this->dll.getFirst();
    T minValue = current->obj;
    while (current != this->dll.getAfterLast()) {
        if (current->obj < minValue)
            minValue = current->obj;
        current = current->next;
    }
    return minValue;
}

template<typename X> ostream& operator<<(ostream& out, const MinQueue<X>& queue) {
    out << queue.dll;
    return out;
}

#endif /* MinQueue_h */
