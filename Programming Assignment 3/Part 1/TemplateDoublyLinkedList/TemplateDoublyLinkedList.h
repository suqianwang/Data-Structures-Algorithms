#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
class DoublyLinkedList; // class declaration

// list node
template<class T>
struct DListNode {
    T obj;
    DListNode *prev, *next;
    DListNode(T e=T(), DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list
template<class T>
class TemplateDoublyLinkedList {
private:
    DListNode<T> header, trailer;
public:
    TemplateDoublyLinkedList() : header(T()), trailer(T()) // constructor
    { header.next = &trailer; trailer.prev = &header; }
    TemplateDoublyLinkedList(const TemplateDoublyLinkedList& dll); // copy constructor
    ~TemplateDoublyLinkedList(); // destructor
    
    TemplateDoublyLinkedList& operator=(const TemplateDoublyLinkedList& dll); // assignment operator
    
    // return the pointer to the first node
    DListNode<T> *getFirst() const { return header.next; }
    
    // return the pointer to the trailer
    const DListNode<T> *getAfterLast() const { return &trailer; }
    
    // return if the list is empty
    bool isEmpty() const { return header.next == &trailer; }
    
    T first() const; // return the first object
    T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    T removeFirst(); // remove the first node
    void insertLast(T newobj); // insert to the last of the list
    T removeLast(); // remove the last node
    void insertAfter(DListNode<T> &p, T newobj);
    void insertBefore(DListNode<T> &p, T newobj);
    T removeAfter(DListNode<T> &p);
    T removeBefore(DListNode<T> &p);
};

// output operator
template <typename T> ostream& operator<<(ostream& out, const TemplateDoublyLinkedList<T>& dll);
// return the list length
template <typename T> int DoublyLinkedListLength(TemplateDoublyLinkedList<T>& dll);


// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template<class T> TemplateDoublyLinkedList<T>::TemplateDoublyLinkedList(const TemplateDoublyLinkedList& dll) {
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    DListNode<T> *current = dll.getFirst();
    while (current != dll.getAfterLast()) {
        this->insertLast(current->obj);
        current = current->next;
    }
    
}

// assignment operator
template<class T> TemplateDoublyLinkedList<T>& TemplateDoublyLinkedList<T>::operator=(const TemplateDoublyLinkedList& dll) {
    // delete the list
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    
    DListNode<T> *current = dll.getFirst();
    while (current != dll.getAfterLast()) {
        this->insertLast(current->obj);
        current = current->next;
    }
    return *this;
}

// insert the new object as the first one
template<class T> void TemplateDoublyLinkedList<T>::insertFirst(T newobj) {
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

// insert the new object as the last one
template<class T> void TemplateDoublyLinkedList<T>::insertLast(T newobj) {
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

// remove the first object from the list
template<class T> T TemplateDoublyLinkedList<T>::removeFirst() {
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
    
}

// remove the last object from the list
template<class T> T TemplateDoublyLinkedList<T>::removeLast() {
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}

// destructor
template<class T> TemplateDoublyLinkedList<T>::~TemplateDoublyLinkedList() {
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// return the first object
template<class T> T TemplateDoublyLinkedList<T>::first() const {
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked Lisr");
    return header.next->obj;
}

// return the last object
template<class T> T TemplateDoublyLinkedList<T>::last() const {
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked Lisr");
    return trailer.prev->obj;
}

// insert the new object after the node p
template<class T> void TemplateDoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj) {
    DListNode<T> *newNode = new DListNode<T>(newobj, &p, p.next);
    newNode->next = p.next;
    newNode->prev = &p;
    p.next->prev = newNode;
    p.next = newNode;
}

// insert the new object before the node p
template<class T> void TemplateDoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj) {
    DListNode<T> *newNode = new DListNode<T>(newobj, p.prev, &p);
    newNode->prev = p.prev;
    newNode->next = &p;
    p.prev->next = newNode;
    p.prev = newNode;
}

// remove the node after the node p
template<class T> T TemplateDoublyLinkedList<T>::removeAfter(DListNode<T> &p) {
    if (p.next == &trailer)
        throw range_error("p is the last node, no node after");
    DListNode<T> *node = p.next;
    node->next->prev = &p;
    p.next = node->next;
    
    T obj = node->obj;
    delete node;
    return obj;
}

// remove the node before the node p
template<class T> T TemplateDoublyLinkedList<T>::removeBefore(DListNode<T> &p) {
    if (p.prev == &header)
        throw range_error("p is the first node, no node before");
    DListNode<T> *node = p.prev;
    node->prev->next = &p;
    p.prev = node->prev;
    
    T obj = node->obj;
    delete node;
    return obj;
}

// return the list length
template<typename T> int DoublyLinkedListLength(TemplateDoublyLinkedList<T>& dll) {
    DListNode<T> *current = dll.getFirst();
    int count = 0;
    while (current != dll.getAfterLast()) {
        count++;
        current = current->next;
    }
    return count;
}

// output operator
template<typename T> ostream& operator<<(ostream& out, const TemplateDoublyLinkedList<T>& dll) {
    
    if (dll.isEmpty()) {
        out << "";
        return out;
    }
    
    DListNode<T> *current = dll.getFirst();
    while (current->next != dll.getAfterLast()) {
        out << current->obj << ", ";
        current = current->next;
    }
    out << current->obj;
    return out;
}
