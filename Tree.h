// Noé Lomelí
// August 3, 2016
// Tree class template

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "TreeNode.h"

// Tree class definition
template< typename NODETYPE > class Tree
{
public:
  //constructor
  Tree(){rootPtr = nullPtr;}

  // insert node in Tree
  void insertNode(const NODETYPE &value)
  {
    insertNodeHelper(&rootPtr, value);
  }// end insertNode

  // begin preorder traversal of Tree
  void preOrderTraversal() const
  {
    preOrderHelper(rootPtr);
  }// end preOrderTraversal

  // begin inorder traversal ot Tree
  void inOrderTraversal() const
  {
    inOrderHelper(rootPtr);
  }// end inOrderTraversal

  // begin postOrder traversal of Tree
  void postOrderTraversal() const
  {
    postOrderHelper(rootPtr);
  }// end postOrderTraversal

private:
  
}
