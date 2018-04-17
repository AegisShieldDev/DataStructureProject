//
//  BinarySearchTree_hpp
//  DataStructureProject
//
//  Created by Miller, Wyatt on 3/29/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    int calculateSize(BinaryTreeNode<Type> * current);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * current);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * startingNode);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * startingNode);
    
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
    void destroyTree(BinaryTreeNode<Type> * node);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTreeNode<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type itemToFind);
    void insert(Type itemToInsert);
    void remove(Type getRidOfMe);
    
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return calculateSize(current->getLeft()) + calculateSize(current->getRight()) + 1;
    }
    return 0;
}
template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * startNode)
{
    return calculateHeight(this->root);
}
template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeft());
    rightHeight = calculateHeight(current->getRight());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeft());
    bool rightBalanced = isBalanced(current->getRight());
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
    
}
template<class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    destroyTree(this->root);
}
template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
    if(node != nullptr)
    {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}
template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    if(index >= size)
    {
        return false;
    }
    
    return(isComplete(startNode->getLeft(), 2 * index + 1, size) && isComplete(startNode->getRight(), 2 + index + 2, size));
}
template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while(currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getRight();
    }
    
    return previous;
}
template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while(currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getLeftNode();
    }
    
    return previous;
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    
    previous = removeMe->getRoot();
    
    if(removeMe->getRight() == nullptr && removeMe->getLeft() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        delete temp;
    }
    else if(removeMe->getRight() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeft();
        
        if(previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        removeMe->setRootNode(previous);
        delete temp;
    }
    if(removeMe->getLeft() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRight();
        
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        removeMe->setRootNode(previous);
        delete temp;
    }
    else{
        current = getRightMostChild(removeMe->getLeft());
        
        previous = current->getRoot();
        removeMe->setData(current->getData());
        
        if(previous == nullptr)
        {
            removeMe->setLeftNode(current->getLeft());
        }
        else
        {
            previous->setRightNode(current->getLeft());
        }
        if(current->getLeft() != nullptr)
        {
            current->getLeft()->setRootNode(removeMe);
        }
        delete current;
    }
    if(removeMe == nullptr || removeMe->getRoot() == nullptr)
    {
        this->root = removeMe;
    }
    
}

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    
}

template <class Type>
BinaryTreeNode<Type> * getRoot()
{
    
}
template <class Type>
void setRoot(BinaryTreeNode<Type> * root)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeft());
        cout << inStart->getData() << endl;
        inOrderTraversal(inStart->getRight());
    }
}
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
        cout << preStart->getData() << endl;
        preOrderTraversal(preStart->getLeft());
        preOrderTraversal(preStart->getRight());
    }
}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * postStart)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeft());
        postOrderTraversal(postStart->getRight());
        cout << postStart->getData() << endl;
        
    }
}
template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps(BinaryTreeNode<Type> * start)
{
    if(start != nullptr)
    {
        cout << "Check if left is here" << endl;
        demoTraversalSteps(start->getLeft());
        cout << "Return to root" << endl;
        cout << "Check if right is here" << endl;
        demoTraversalSteps(start->getRight());
    }
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}
template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return -1;
}
template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    return false;
}
template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if(itemToFind < current->getData())
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }
        }
        return false;
    }
}
    
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getData())
            {
                current = current-> getLeft();
            }
            else if(itemToInsert > current->getData())
            {
                current = current-> getRight();
            }
            else
            {
                delete insertMe;
                return;
            }
        }
        
        if(previous->getData() > itemToInsert)
        {
            previous->setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
        
}
template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
        cout << "Empty tree s removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getRight();
                }
                else
                {
                    current = current->getRight();
                }
            }
        }
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == this->root)
            {
                removeNode(this->root);
            }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeft());
            }
            else
            {
                removeNode(previous->getRight());
            }
        }
    }
    
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
}
template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData();
}

#endif /* BinarySearchTree_hpp */
