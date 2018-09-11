//
//  main.cpp
//  Part 2
//
//  Created by Susan Wang on 7/28/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include "MinQueue.h"
#include <iostream>
using namespace std;
int main () {
    // Construct a Queue
    cout << "----- Create a queue -----" << endl;
    MinQueue<char> Q1;
    cout << "Queue1: " << Q1 << endl << endl;
    
    // Get the size of the Queue
    cout << "The size of the queue is: " << Q1.size() << endl << endl;
    
    // enqueue 5 nodes at back with value 10,20,30,..,100
    Q1.enqueue('c');
    Q1.enqueue('b');
    Q1.enqueue('a');
    Q1.enqueue('d');
    cout << "Enqueue c, b, a, d to queue1" << endl << "Queue1: " << Q1 << endl << endl;
    
    // Get the size of the Queue
    cout << "The size of the queue is: " << Q1.size() << endl << endl;
    
    // Get the minimum of the Queue
    cout << "The minimum of the Queue is: " << Q1.getMin() << endl << endl;
    
    // dequeue a nodes at front with value 10
    cout << "Dequeue a nodes at front with value 10" << endl;
    Q1.dequeue();
    cout << "Queue1: " << Q1 << endl << endl;
    
    // Get the size of the Queue
    cout << "The size of the queue is: " << Q1.size() << endl << endl;
    
    // Construct a Queue
    cout << "----- Create a queue -----" << endl;
    MinQueue<string> Q2;
    
    Q2.enqueue("strawberry");
    cout << "Enqueue \"strawberry\" -- " << "Queue2: " << Q2 << endl << endl;
    Q2.enqueue("watermelon");
    cout << "Enqueue \"watermelon\" -- " << "Queue2: " << Q2 << endl << endl;
    Q2.enqueue("banana");
    cout << "Enqueue \"banana\" -- " << "Queue2: " << Q2 << endl << endl;
    Q2.enqueue("orange");
    Q2.enqueue("apple");
    cout << "Enqueue \"orange\" and \"apple\" in order -- " << "Queue2: " << Q2 << endl << endl;
    
    // Get the size of the Queue
    cout << "The size of the queue is: " << Q2.size() << endl << endl;
    
    // Get the minimum of the Queue
    cout << "The minimum of the Queue is: " << Q2.getMin() << endl << endl;
    
    Q2.dequeue();
    cout << "Dequeue a node from Queue2: " << Q2 << endl << endl;
    Q2.dequeue();
    cout << "Dequeue a node from Queue2: " << Q2 << endl << endl;
    Q2.dequeue();
    cout << "Dequeue a node from Queue2: " << Q2 << endl << endl;
    
    // Get the size of the Queue
    cout << "The size of the queue is: " << Q2.size() << endl << endl;
    
    try{
        // Construct a Queue
        cout << "----- Create a queue -----" << endl;
        MinQueue<int> Q3;
        
        Q3.enqueue(7);
        Q3.enqueue(12);
        Q3.enqueue(4);
        Q3.enqueue(10);
        
        cout << "Enqueue 7, 12, 4, 10 to Queue3 in order" << endl << "Queue3: " << Q3 << endl << endl;
        
        // Get the minimum of the Queue
        cout << "The minimum of the Queue is: " << Q3.getMin() << endl << endl;
        
        Q3.dequeue();
        Q3.dequeue();
        Q3.dequeue();
        cout << "Dequeue three elements from queue3" << endl << "Queue3: " << Q3 << endl << endl;
        Q3.dequeue();
        Q3.dequeue();
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}

