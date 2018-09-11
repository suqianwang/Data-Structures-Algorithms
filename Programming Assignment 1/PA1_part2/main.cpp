// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include <string>
#include "TemplatedMy_vec.h"

int main(){
    
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.
    
    cout << "***** test objects with char type *****" << endl;
    
    TemplatedMy_vec<char> v;                           // define an object v of TemplatedMy_vec<char> type
    
    try{
        v.insert_at_rank(0, 'B');       // insert 'B' at the rank 0 into the vector v
        cout << v << endl;              // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;   // display the vector v size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        v.insert_at_rank(0, 'A');       // insert 'A' at the rank 0  to the vector v
        cout << v << endl;              // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;   // display the vector v size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        v.insert_at_rank(10, 'D');      // insert 'D' at the rank 10 into the vector v
        cout << v << endl;              // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;   // display the vector v size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        v.remove_at_rank(1);            // remove a character at the rank 1 from the vector v
        cout << v << endl;              // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;   // display the vector v size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        v.replace_at_rank(0, 'E');      // replace a character at the rank 0 by the character 'E'
        cout << v << endl;              // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;   // display the vector v size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<char> v1(v);                   // create a copy v1 of the vector v using a copy constructor
    cout << v1 << endl;             // use the overloaded operator << to display the vector v1
    
    try{
        v1.replace_at_rank(2, 'Y');     // replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << v1 << endl;             // use the overloaded operator << to display vector v1 elements
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<char> v2;                      // define an object v2 of TemplatedMy_vec<char> type
    
    try{
        v2.insert_at_rank(0, 'K');      // insert 'K' at the rank 0 into the vector v2
        cout << v2 << endl;             // use the overloaded operator << to display vector elements
        cout << v2.get_size() << endl;  // display the vector v2 size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    v2 = v1;                        // test the assignment operator and copy the vector v1 to v2
    cout << v2 << endl;
    
    try{
        v2[0] = '1';                    // Set v2 to '1','2','3','4','5'
        for (int i = 2; i <= 5; i++)
            v2.insert_at_rank(i - 1, '0' + i);
        cout << v2 << endl;             // use the overloaded operator << to display vector v2
        cout << v2.get_size() << endl;  // display the vector v2 size
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        cout << "index of the largest element in v2 is " << find_max_index(v2, v2.get_size()) << endl;                // test the function find_max_index using v2
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        sort_max(v2);                   // test the function sort_max using v2
        cout << "sorted v2: " << v2 << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        v2.replace_at_rank(14, 'S');    // replace in the vector v2 a character at the rank 14 with 'S'
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    
    cout << endl << "***** test objects with int type *****" << endl;
    
    TemplatedMy_vec<int> vint;
    try{
        vint.insert_at_rank(0, 5);
        cout << vint << endl;
        cout << vint.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vint.insert_at_rank(0, 4);
        cout << vint << endl;
        cout << vint.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vint.insert_at_rank(8, 7);
        cout << vint << endl;
        cout << vint.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vint.remove_at_rank(1);
        cout << vint << endl;
        cout << vint.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vint.replace_at_rank(0, 8);
        cout << vint << endl;
        cout << vint.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<int> vint1(vint);
    cout << vint1 << endl;
    
    try{
        vint1.replace_at_rank(2, 12);
        cout << vint1 << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<int> vint2;
    
    try{
        vint2.insert_at_rank(0, 15);
        cout << vint2 << endl;
        cout << vint2.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    vint2 = vint1;
    cout << vint2 << endl;
    
    try{
        vint2[0] = 90;                    // Set vint2 to 90, 22, 13, 49, 5
        vint2.insert_at_rank(1, 22);
        vint2.insert_at_rank(2, 13);
        vint2.insert_at_rank(3, 49);
        vint2.insert_at_rank(4, 5);
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        cout << "index of the largest element in vint2 is " << find_max_index(vint2, vint2.get_size()) << endl;                // test the function find_max_index using vint2
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        sort_max(vint2);
        cout << "sorted vint2: " << vint2 << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vint2.replace_at_rank(14, 9);
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    
    cout << endl << "***** test objects with string type *****" << endl;
    
    TemplatedMy_vec<string> vstring;
    try{
        vstring.insert_at_rank(0, "pineapple");
        cout << vstring << endl;
        cout << vstring.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vstring.insert_at_rank(0, "grape");
        cout << vstring << endl;
        cout << vstring.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vstring.insert_at_rank(4, "peach");
        cout << vstring << endl;
        cout << vstring.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vstring.remove_at_rank(1);
        cout << vstring << endl;
        cout << vstring.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vstring.replace_at_rank(0, "blackberry");
        cout << vstring << endl;
        cout << vstring.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<string> vstring1(vstring);
    cout << vstring1 << endl;
    
    try{
        vstring1.replace_at_rank(2, "pear");
        cout << vstring1 << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    TemplatedMy_vec<string> vstring2;
    
    try{
        vstring2.insert_at_rank(0, "apple");
        cout << vstring2 << endl;
        cout << vstring2.get_size() << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    vstring2 = vstring1;
    cout << vstring2 << endl;
    
    try{
        vstring2[0] = "strawberry";
        vstring2.insert_at_rank(1, "apple");
        vstring2.insert_at_rank(2, "orange");
        vstring2.insert_at_rank(3, "banana");
        vstring2.insert_at_rank(4, "watermelon");
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        cout << "index of the largest element in vstring2 is " << find_max_index(vstring2, vstring2.get_size()) << endl;                // test the function find_max_index using vstring2
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        sort_max(vstring2);
        cout << "sorted vstring2: " << vstring2 << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        vstring2.replace_at_rank(14, "FRUIT");
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
