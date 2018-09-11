//
//  Map.cpp
//  Final project
//
//  Created by Susan Wang on 8/2/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include "Map.h"
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// get map from input file
void Map::input_map(string input_file) {
    path.clear();
    graph.clear();
    room_list.clear();
    
    ifstream map_data;
    map_data.open(input_file);
    if (map_data.is_open()) {
        
        map_data >> this->num_room;
        this->num_row = sqrt(this->num_room);
        this->entry_id = 0;
        this->exit_id = num_room - 1;
        
        int door[4];
        int room_id = 0;
        while(map_data.eof() == false) {
            for (int i = 0; i < 4; i++) {
                map_data >> door[i];
            }
            this->room_list.push_back(Room(room_id, door));
            room_id++;
        }
        map_data.close();
        
        this->make_graph();
    }
    else {
        cout << "error opening file" << endl;
    }
}

// create graph from room list
void Map::make_graph() {
    for (int i = 0; i < this->num_room; i++) {
        this->graph.push_back(this->get_valid_neighbor(i));
    }
}

// get valid neighbor for given room
vector<int> Map::get_valid_neighbor(int id) {
    vector<int> valid_neighbor;
    if (this->room_list.at(id).door[NORTH] == 1)
        valid_neighbor.push_back(id - this->num_row);
    if (this->room_list.at(id).door[EAST] == 1)
        valid_neighbor.push_back(id + 1);
    if (this->room_list.at(id).door[SOUTH] == 1)
        valid_neighbor.push_back(id + this->num_row);
    if (this->room_list.at(id).door[WEST] == 1)
        valid_neighbor.push_back(id - 1);
    
    return valid_neighbor;
}

// search for all valid pathes in the map
void Map::search_path() {
    this->dfs();
}

// using dfs algorithm
void Map::dfs() {
    bool* is_visited = new bool[num_row* num_row];
    for (int i = 0; i < this->num_room; i++)
        is_visited[i] = false;
    
    this->current_path.clear();
    this->path.clear();
    
    this->current_path.push_back(this->entry_id);
    for (int i = 0; i < this->graph.at(this->entry_id).size(); i++) {
        int u_id = this->graph.at(this->entry_id).at(i);
        this->dfs_aux(is_visited, u_id);
    }
}

// dfs algorithm aux
void Map::dfs_aux(bool* is_visited, int u_id) {
    this->current_path.push_back(u_id);
    
    if (u_id == this->exit_id) {
        this->path.push_back(this->current_path);
    }
    else {
        is_visited[u_id] = true;
        for (int i = 0; i < graph.at(u_id).size(); i++) {
            int v_id = graph.at(u_id).at(i);
            if (!is_visited[v_id]) {
                this->dfs_aux(is_visited, v_id);
            }
        }
    }
    this->current_path.pop_back();
}

// show all valid pathes
void Map::show_path() {
    
    for (int i = 0; i < this->path.size(); i++) {
        int* map_draw = new int[num_room];
        
        for (int j = 0; j < this->num_room; j++) {
            map_draw[j] = 0;
        }
        
        for (int j = 0; j < this->path.at(i).size(); j++) {
            map_draw[path.at(i).at(j)] = 1;
        }
        
        cout << "->display path " << i << endl;
        for (int j = 0; j < this->num_row; j++) {
            for (int k = 0; k < this->num_row; k++) {
                cout << ((map_draw[j * this->num_row + k] == 1)? "o" : "x") << " ";
            }
            cout << endl << endl;
        }
        cout << "The length of the path above is " << this->path.at(i).size() - 1 << " which is the number of the graph edges(doors to open) to reach the Exit." << endl;
        delete[] map_draw;
    }
    this->find_shortest_path();
}

void Map::show_graph() {
    for (int i = 0; i < this->graph.size(); i++) {
        cout << i;
        for (int j = 0; j < this->graph.at(i).size(); j++) {
            cout << "->" << this->graph.at(i).at(j);
        }
        cout << endl;
    }
    
}

void Map::show_path_vertices() {
    for (int i = 0; i < this->path.size(); i++) {
        cout << "the vertices of the " << i << " path is: " << endl;
        for (int j = 0; j < this->path.at(i).size(); j++)
            cout << this->path.at(i).at(j) << " ";
        cout << endl;
    }
}

void Map::find_shortest_path() {
    if (this->path.size() == 0)
        cout << "no valid path" << endl;
    else {
        int min_size = int(this->path.at(0).size());
        int min_index = 0;
        for (int i = 0; i < this->path.size(); i++) {
            if (this->path.at(i).size() < min_size) {
                min_size = int(this->path.at(i).size());
                min_index = i;
            }
        }
        
        cout << endl << "the shortest one is path " << min_index + 1 << ", the length of which is " << min_size - 1 << endl;
    }
}

