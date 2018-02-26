//
//  TestingStacksAndQueues.hpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 2/26/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef TestingStacksAndQueues_hpp
#define TestingStacksAndQueues_hpp

#include <iostream>
#include "../Model/Structures/Linear/Stack.hpp"
#include "../Model/Structures/Linear/Queue.hpp"
#include "../Controller/FileController.hpp"
#include "../Controller/Tools/Timer.hpp"
#include "../Data/CrimeData.hpp"

class TestingStacksAndQueues
{
public:
    void stackVersusList();
    void stackVersusQueue();
    void queueVersusList();
};

#endif /* TestingStacksAndQueues_hpp */
