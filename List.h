// Noé Lomelí
// August 01, 2016
// List class-template definition
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
template < typename NODETYPE >
class List
{
public:
  List() // default constructor
    : fistPtr(nullptr), lastPtr(nullptr)
  {
    // empty body
  } // end list constructor

  ~List() // destructor
  {
    if(!isEmpty) // list is not empty
    {
      std::cout << "Destroying nodes...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr = nullptr;

      while(currentPtr != nullptr) //delete remaining nodes
      {
        tempPtr = currentPtr;
        std::cout << tempPtr->data << '\n';
        currentPtr = currentPtr->next;
        delete tempPtr;
      } // end while
    } //end if
    std::cout << "All nodes destroyed \n\n";

    // insert node at front of list
    void insertAtFront(const NODETYPE &value)
    {
      ListNode< NODETYPE > *newPtr = getNewNode(value); // new node
      if(isEmpty()) // list is empty
        firstPtr = lastPtr = newPtr; new list has onlu one node
      else
      {
        newPtr->nextPtr = firstPtr; // point new node to old 1st node
        firstPtr = newPtr; // point firstPtr at new node
      }// end else
    }// end insertAtFront

    void insertAtBack(const NODETYPE &value)
    {
      ListNode< NODETYPE > *newPtr = getNewNode(value); //new node
      if(isEmpty())
        firstPtr = lastPtr = newPtr;
      else
      {
        lastPtr->nextPtr = newPtr; // update previous last node
        lastPtr = newPtr; // new last node
      }// end else
    }// end insertAtBack
  }
}; // end class List
#endif
