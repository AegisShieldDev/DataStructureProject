//
//  FileController.cpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "FileController.hpp"

using namespace std;

vector <CrimeData> FileController :: readCrimeDataToVector(string gilename)
{
    std :: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.isOpen())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            if(rowCount != 0)
            {
                CrimeData row(currentCSVLine);
                crimeVector.push_back(row);
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimeVector;
}


