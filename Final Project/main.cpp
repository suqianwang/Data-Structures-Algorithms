#include <iostream>
#include <stdexcept>
#include "Map.h"
#include "Room.h"

using namespace std;

void display_menu() {
    cout << "------------" << endl;
    cout << "You can do one of the following options, please enter the option number:" << endl;
    cout << "<1> print the adjacency list for a given graph." << endl;
    cout << "<2> find the length of all entry-exit paths, and the shortest path" << endl;
    cout << "<3> print out all vertices for all entry-exit paths" << endl;
    
    cout << endl << "enter your choice: ";
}


int main() {

    Map map;

    int choice;
    cout << "please enter the name of the input file: ";
    string input_file;
    cin >> input_file;
    map.input_map(input_file);
    map.search_path();
    
    while (true) {
        display_menu();
        cin >> choice;
        switch(choice) {
            case 1:
                map.show_graph();
                break;
            case 2:
                map.show_path();
                break;
            case 3:
                map.show_path_vertices();
                break;
            default:
                try{
                    throw runtime_error("undefined option");
                }
                catch(exception &error){
                    cerr << "Error: " << error.what() << endl;
                }
        }
    }
	return 0;
}
