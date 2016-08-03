// Noé Lomelí
// August 3, 2016
// Stacks class definition

#ifndef STACK_H
#define STACK_H

#include "List.h"

template< typename STACKTYPE >
class Stack : private List< STACKTYPE >
{
public:
  // push calls the List function insertAtFront
  void push(const STACKTYPE &data)
  {
    insertAtFront(data);
  }// end push

  // pop calls the List function removeFromFront
  bool pop( STACKTYPE &data)
  {
    return removeFromFront(data);
  }// end pop

  // isStackEmpty calls the function isStackEmpty
  bool isStackEmpty() const
  {
    return this->isEmpty();
  }// end isStackEmpty

  // printStack calls the List function print
  void printStack() const
  {
    this->print();
  }// end printStack
}; // end class Stack
#endif
