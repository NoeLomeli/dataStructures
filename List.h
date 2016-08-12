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
    : firstPtr(nullptr), lastPtr(nullptr)
  {
    // empty body
  } // end list constructor

  ~List() // destructor
  {
    if(!isEmpty()) // list is not empty
    {
      std::cout << "Destroying nodes...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr = nullptr;

      while(currentPtr != nullptr) //delete remaining nodes
      {
        tempPtr = currentPtr;
        std::cout << tempPtr->data << '\n';
        currentPtr = currentPtr->nextPtr;
        delete tempPtr;
      } // end while
    } //end if
    std::cout << "All nodes destroyed \n\n";
  }// end list destructor

  // insert node anywhere on the list
  void insert(const NODETYPE &value)
  {
    ListNode< NODETYPE > *newPtr = getNewNode(value); // create new node
    // case 1 - Empty list
    if(isEmpty())
      firstPtr = lastPtr = newPtr; // new list has only one node
    else
    {
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *trailPtr = nullptr;
      // traverse the list to find insert location
      while(currentPtr != nullptr)
      {
        if(currentPtr->data >= newPtr->data)
          break;
        else
        {
          trailPtr = currentPtr;
          currentPtr = currentPtr->nextPtr;
        }// end else
      }// end while
      // Case 2 - Insert at head(not empty)
      if(currentPtr == firstPtr)
      {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
      }// end if
      else
      {
        //case 3 - Insert after the head(not empty)
        newPtr->nextPtr = currentPtr;
        trailPtr->nextPtr = newPtr;
      }// end else
    }// end else
  }// end insert

  // insert node at front of list
  void insertAtFront(const NODETYPE &value)
  {
    ListNode< NODETYPE > *newPtr = getNewNode(value); // new node
    if(isEmpty()) // list is empty
      firstPtr = lastPtr = newPtr; //new list has only one node
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

  // delete node from front of list
  bool removeFromFront(NODETYPE &value)
  {
    if(isEmpty())
      return false;
    else
    {
      ListNode < NODETYPE > *tempPtr = firstPtr; // hold item to delete
      if(firstPtr == lastPtr)
        firstPtr = lastPtr = nullptr; // no nodes remaining
      else
        firstPtr = firstPtr->nextPtr; // point to previous 2nd node

      value = tempPtr->data; // return data being removed
      delete tempPtr; // reclaim previous front node
      return true; // delete successful
    } // end else
  } // end removeFromFront

  //delete node from back of list
  bool removeFromBack(NODETYPE &value)
  {
    if(isEmpty())
      return false; // delete unsuccessful
    else
    {
      ListNode< NODETYPE > *tempPtr = lastPtr; // hold item to delete
      if(firstPtr == lastPtr) //list has one element
        firstPtr = lastPtr = nullptr; // no nodes remain after removal
      else
      {
        ListNode < NODETYPE > *currentPtr = firstPtr;
        // locate second-to-last element
        while(currentPtr->nextPtr != lastPtr)
          currentPtr = currentPtr->nextPtr; //move to next node
        lastPtr = currentPtr; // remove last node
        currentPtr->nextPtr = nullptr; // this is now the last node
      } // end else
      value = tempPtr->data; //return value from old last node
      delete tempPtr; // reclaim former last node
      return true; // delete successful
    }// end else
  }// end removeFromBack

  // is list empty
  bool isEmpty() const
  {
    return firstPtr == nullptr;
  } // end isEmpty

  // display contents of list
  void print() const
  {
    if(isEmpty())
    {
      std::cout << "The list is empty\n\n";
      return;
    }// end if
    ListNode< NODETYPE > *currentPtr = firstPtr;
    std::cout << "The list is: ";
    while(currentPtr != nullptr) // get element data
    {
      std::cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
    } // end while
    std::cout << "\n\n";
  }// end print

  NODETYPE top() const
  {
    ListNode< NODETYPE > *currentPtr = firstPtr;
    return currentPtr->data;
  }// end top
private:
  ListNode< NODETYPE > *firstPtr; // pointer to first node
  ListNode< NODETYPE > *lastPtr; // pointer to last node
  //utility function to allocate new node
  ListNode< NODETYPE > *getNewNode(const NODETYPE &value)
  {
    return new ListNode< NODETYPE > (value);
  }// end getNewNode
}; // end class List
#endif
