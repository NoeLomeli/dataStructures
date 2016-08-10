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

// This is the main function that will call all other functions in order
// to convert the expression from infix to postfix
void convertInfixToPostfix();

// determines whether the character passed as an argument is an operator
bool isOperator(char op);

// determines whether the precedence of first character is greater than
// or equal to the second character, and if so, it returns true
bool precedence(char op1, char op2);

int main()
{
  convertInfixToPostfix();

} // end main

void convertInfixToPostfix()
{
  string infix = "";
  string postfix = "";
  Postfix< char > charStack; // create Stack of chars
  charStack.push('(');

  std::cout << "Enter an arithmetic expression: ";
  std::getline(std::cin, infix);
  infix += ')'; // append a right parenthesis to the expression
  int i = 0;
  char popChar;
  char operator1;
  char operator2;
  while(!charStack.isStackEmpty())
  {
    if(infix[i] == ' ')
      i++;
    if(isdigit(infix[i]))
    {
      postfix += infix[i]; // digits get copied to postfix
    }
    if(infix[i] == '(')
    {
      charStack.push('(');
    }
    if(isOperator(infix[i]))
    {
      operator1 = charStack.topElement();
      operator2 = infix[i];

      if(!isOperator(operator1)) // stack does not contain an operator
      {
        charStack.push(operator2);
      }
      else
      {
        // determine if the operator on the stack is greater than the one on infix variable
        if(precedence(operator1, operator2))
        {
          charStack.pop(popChar); // add popped element to postfix
          postfix += popChar;
          charStack.push(operator2);
        }
        else
        charStack.push(operator2);
      }
    }
    if(infix[i] == ')')
    {
      while(charStack.topElement() != '(')
      {
        charStack.pop(popChar);
        cout << "\npopChar " << popChar << endl;
        postfix += popChar;

      }
      charStack.pop(popChar);
    }

    cout << "i: " << i << endl;
    cout << "post: " << postfix << endl;
    i++;
  }  // end while

  return;
}// end convertInfixToPostfix

bool isOperator(char op)
{
  if(op == '%' || op == '/' || op == '*' || op == '+' || op == '-' || op == '^')
    return true;
  else
    return false;
}// end isOperator

bool precedence(char op1, char op2)
{
  bool isGreater;
  if(op1 == '^')
    isGreater = true;
  if(op2 == '^' && op1 != '^')
    isGreater = false;
  if(op1 == '*' || op1 == '/' || op1 == '%')
    isGreater = true;
  else if(op1 == '+' || op1 == '-')
  {
    if(op2 == '*' || op2 == '/' || op2 == '%')
      isGreater = false;
    else
      isGreater = true;
  }// end else if
  return isGreater;

}//end precedence
