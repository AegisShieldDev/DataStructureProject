//
//  Controller.cpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Cooooooooode" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    
    for(int index = 0; index < 500; index++)
    {
        cout << "Index is " << index << "\t";
    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
