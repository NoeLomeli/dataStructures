// Noé Lomelí
// August 9, 2016
// Infix-to-Postfix Conversion Program
// Summary: The user will input an arithmetic expression in infix notation
// format. This program will convert the expression into postfix notation
// and return it as a string value


#ifndef POSTFIX_H
#define POSTFIX_H

#include "List.h"
#include <string>
#include <iostream>
template< typename STACKTYPE >
class Postfix : private List< STACKTYPE >
{
public:
  // topElement returns the top value of the stack without popping the stack
  STACKTYPE topElement() const
  {
    if(isStackEmpty())
    {
      std::cout << "Stack is empty" << std::endl;
      return ' ';
    }
    else
    {
      std::cout << "The top element is: ";
      return this->top();
    }
  }// end topElement

  // push calls the List function insertAtFront
  void push(const STACKTYPE &data)
  {
    this->insertAtFront(data);
  }// end push

  // pop calls the List function removeFromFront
  bool pop( STACKTYPE &data)
  {
    return this->removeFromFront(data);
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

  
private:
  std::string infix;
  std::string postfix;
}; // end class Stack
#endif
