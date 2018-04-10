//
//  BinaryTreeTester.cpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester:: doTreeStuff()
{
    testTree.insert("Lorem");
    testTree.insert("ipsum");
    testTree.insert("dolor");
    testTree.insert("sit");
    testTree.insert("amet,");
    testTree.insert("consectetur");
    testTree.insert("adipiscing");
    testTree.insert("elit.");
    testTree.insert("Morbi");
    testTree.insert("aliquam");
    testTree.insert("elit");
    testTree.insert("eget");
    //testTree.insert("d");
    
    cout << "InOrder" << endl;
    testTree.inOrderTraversal();
    cout << "Pre" << endl;
    testTree.preOrderTraversal();
    cout << "Post" << endl;
    testTree.postOrderTraversal();
}
