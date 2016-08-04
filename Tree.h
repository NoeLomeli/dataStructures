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
  Tree(){rootPtr = nullptr;}

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
  TreeNode< NODETYPE > *rootPtr;

  // utility function called by insertNode: receives a pointer
  // to a pointer so that the function can modify pointer's value
  void insertNodeHelper(TreeNode< NODETYPE > **ptr, const NODETYPE &value)
  {
    // subtree is empty; create new TreeNode containing value
    if(*ptr == nullptr)
      *ptr = new TreeNode< NODETYPE >(value);
    else // subtree is not empty
    {
      //data to insert is less than data in current node
      if(value < (*ptr)->data)
        insertNodeHelper(&((*ptr)->leftPtr), value);
      else
      {
        //data to insert is greater than data in current node
        if(value > (*ptr)->data)
          insertNodeHelper(&((*ptr)->rightPtr), value);
        else // duplicate value ignored
          std::cout << value << " dup" << std::endl;
      } // end else
    }// end else
  }//end insertNodeHelper

  // utility function to perform preorder traversal of Tree
  void preOrderHelper( TreeNode< NODETYPE > *ptr) const
  {
    if(ptr != nullptr)
    {
      std::cout << ptr->data << ' '; //process node
      preOrderHelper(ptr->leftPtr); // traverse left subtree
      preOrderHelper(ptr->rightPtr); // traverse right subtree
    } // end if
  }// end preOrderHelper

  // utility function to perform inorder traversal of Tree
  void inOrderHelper( TreeNode< NODETYPE > *ptr) const
  {
    if(ptr != nullptr)
    {
      inOrderHelper(ptr->leftPtr);
      std::cout << ptr->data << ' ';
      inOrderHelper(ptr->rightPtr);
    }// end if
  }// end inOrderHelper

  // utility function to perform postOrder traversal
  void postOrderHelper( TreeNode< NODETYPE > *ptr) const
  {
    if(ptr != nullptr)
    {
      postOrderHelper(ptr->leftPtr);
      postOrderHelper(ptr->rightPtr);
      std::cout << ptr->data << ' ';
    }// end if
  }//end postOrderHelper
}; // end class Tree
#endif
