//
//  Controller.hpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "Tools/Timer.hpp"
#include "FileController.hpp"
#include "../Model/Structures/Array.hpp"

class Controller
{
private:
    void findMaxAndMin();
    void testArray();
public:
    void start();
};

#endif /* Controller_hpp */
