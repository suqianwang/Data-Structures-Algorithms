//
//  Map.h
//  Final project
//
//  Created by Susan Wang on 8/2/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include <vector>
#include "Room.h"
using namespace std;

// map class
class Map {
    
private:
    int num_row;
    int num_room;
    int entry_id;
    int exit_id;
    
    vector<vector<int>> path;
    vector<vector<int>> graph;
    vector<int> current_path;
    vector<Room> room_list;
    
public:
    Map(){};
    
    void input_map(string input_file);
    void make_graph();
    vector<int> get_valid_neighbor(int id);
    void search_path();
    void dfs();
    void dfs_aux(bool* is_visited, int id);
    void show_path();
    
    void show_graph();
    void show_path_vertices();
    void find_shortest_path();
};


#endif /* Map_h */
