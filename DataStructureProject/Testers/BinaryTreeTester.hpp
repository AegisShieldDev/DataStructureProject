//
//  BinaryTreeTester.hpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include "../Model/Node/BinaryTreeNode.hpp"
#include "../Model/Structures/NonLinear/BinarySearchTree.hpp"
#include <ioStream>

class BinaryTreeTester
{
private:
    BinarySearchTree<int> testTree;
public:
    void doTreeStuff();
};

#endif /* BinaryTreeTester_hpp */
