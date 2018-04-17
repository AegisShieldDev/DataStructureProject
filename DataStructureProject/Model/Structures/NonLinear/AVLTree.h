//
//  AVLTree.h
//  DataStructureProject
//
//  Created by Miller, Wyatt on 4/17/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinaryTreeNode<Type> * leftRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * insertNode(BinaryTreeNode<Type> * parent, value);
    BinaryTreeNode<Type> * removeNode(BinaryTreeNode<Type> * parent, value);
    
    int heightDifference(BinaryTreeNode<Type> * parent);
public:
    AVLTree;
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeft());
    int rightHeight = this->calculateHeight(node->getRight());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeft();
    
    parent->setLeftChild(changedNode->getRight());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRight();
    
    parent->setRightChild(changedNode->getLeft());
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRight();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: LeftRightRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeft();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree (BinaryTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeft()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRight()) > 0)
        {
            parent = rightRotation(parent);
        }
        else
        {
            parent = rightLeftRotation(parent);
        }
    }
    
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinaryTreeNode<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        return parent;
    }
    if(inserted < parent->getNode())
    {
        parent->setLeftChild(removeNode(parent->getLeft(), inserted));
    }
    else if(inserted > parent->getNode())
    {
        parent->setRightChild(removeNode(parent->getRight(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLeft() == nullptr && parent->getRight() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if(parent->getLeft == nullptr)
        {
            *parent = *parent->getRight();
        }
        else if(parent->getRight == nullptr)
        {
            *parent = *parent->getLeft();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild9parent->getRight());
            parent->setNodeData(leftMost->getNodeData());
            parent->setRightChild(removeNode->getRight(), leftMost->getNode()));
        }
    }
    if(parent == nullptr)
    {
        return parent;
    }
    
    return balanceSubTree(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNode())
    {
        parent->setLeft(insertNode(parent->getLeft(), inserted));
        parent = balancesubTree(parent);
    }
    else if(inserted > parent->getNode())
    {
        parent->setRight(insertNode(parent->getRight(), inserted));
        parent = balancesubTree(parent);
    }
    return parent;
}


#endif /* AVLTree_h */
