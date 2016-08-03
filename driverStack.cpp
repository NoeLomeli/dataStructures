// Noé Lomelí
// August 3, 2016
// A simple stack program

#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
  Stack< int > intStack; // create stack of ints

  cout << "Processing an integer Stack" << endl;

  //push integers onto Stack
  for(int i = 0; i < 3; i++)
  {
    intStack.push(i);
    intStack.printStack();
  }// end for

  int popInteger; // store int popped from Stack
  //pop integers from intStack
  while(!intStack.isStackEmpty())
  {
    intStack.pop(popInteger);
    cout << popInteger << " popped from stack" << endl;
    intStack.printStack();
  }// end while

  Stack< double > doubleStack; // create a Stack of doubles
  double value = 1.1;
  cout << "Processing a double Stack" << endl;
  //push floating point values onto doubleStack
  for(int j = 0; j < 3; j++)
  {
    doubleStack.push(value);
    doubleStack.printStack();
    value += 1.1;
  }// end for

  double popDouble; // store double popped from stack
  //pop floating point values from doubleStack
  while(!doubleStack.isStackEmpty())
  {
    doubleStack.pop(popDouble);
    cout << popDouble << " popped from stack" << endl;
    doubleStack.printStack();
  }// end while
  
}// end main
