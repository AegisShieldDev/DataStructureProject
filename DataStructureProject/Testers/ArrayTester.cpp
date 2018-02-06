//
//  ArrayTester.cpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 2/6/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "ArrayTester.hpp"

void ArrayTester :: testArrayUse()
{
    Array<int> firstArray(10);
    
    for(int i = 0; i < 10; i++)
    {
        firstArray.setAtIndex(i, i);
    }
    for(int i = 0; i < firstArray.getSize(); i++)
    {
        cout << firstArray[i] << endl;
    }
    
    Array<int> secondArray(400);
    
    cout << secondArray.getSize() << endl;
    cout << firstArray.getSize() << endl;
    
    Array<int> thirdArray(secondArray);
    
    cout << thirdArray.getSize() << endl;
    firstArray = thirdArray;
    cout << firstArray[4] << endl;
    
    thirdArray[5] = 123;
    cout << thirdArray[5] << endl;
    
    if(firstArray.getSize() >= 0)
    {
        cout << "getSize is successful" << endl;
    }
    
    firstArray.setAtIndex(1, 5);
    if(firstArray.getFromIndex(1) == 5)
    {
        cout << "getFromIndex is successful" << endl;
    }
    
}

void ArrayTester :: testAdvancedArray()
{
    vector<CrimeData> test = FileController :: readCrimeDataToVector("Users/");
}
