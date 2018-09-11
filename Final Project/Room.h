//
//  Room.h
//  Final project
//
//  Created by Susan Wang on 8/2/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef Room_h
#define Room_h

// class for storaging information of room
class Room {
    
public:
    int id;
    int door[4];
    
    Room(int id_set, int door_set[4]) {
        this->id = id_set;
        for (int i = 0; i < 4; i++)
            this->door[i] = door_set[i];
    };
};

#endif /* Room_h */
