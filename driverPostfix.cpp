// Noé Lomelí
// August 9, 2016
// Infix-to-Postfix Conversion Program
// Summary: The user will input an arithmetic expression in infix notation
// format. This program will convert the expression into postfix notation
// and return it as a string value

#include "Postfix.h"
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  Postfix< char > charStack; // create Stack of chars
  charStack.push('(');
  cout << charStack.topElement() << endl;
  //charStack.convertToPostfix();

} // end main
