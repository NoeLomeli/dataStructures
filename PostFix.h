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
template< typename STACKTYPE >
class Stack : private List< STACKTYPE >
{
public:
  postfix(){infix = "", postfix = "";} // default constructor

  convertToPostfix()
  {
    std::cout " Enter an arithmetic expression: ";
    cin >> infix;
  }
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
  string infix;
  string postfix;
}; // end class Stack
#endif
