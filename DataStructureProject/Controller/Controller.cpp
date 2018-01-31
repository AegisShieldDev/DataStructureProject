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

    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/wmil5119/Desktop/C++/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    for(int i = 200; i <= 215; i++)
    {
        cout << i << " is " << myData[i] << endl;
    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
