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
    findMaxAndMin();
}

void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/wmil5119/Desktop/C++/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int index = 1; index < myData.size(); index++)
    {
        if(myData [minIndex] > myData [index])
        {
            minIndex = index;
        }
        else if(myData [maxIndex] < myData[index])
        {
            maxIndex = index;
        }
    }
    searchTimer.stopTimer();
    cout << "The smallest crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest crime stat is at "  << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}
