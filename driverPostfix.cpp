// Noé Lomelí
// August 9, 2016
// Infix-to-Postfix Conversion Program
// Summary: The user will input an arithmetic expression in infix notation
// format. This program will convert the expression into postfix notation
// and return it as a string value to be evaluated and return the correct result
// of the expression.

#include "Postfix.h"
#include <iostream>
#include <stack>
#include <cmath> // pow
#include <cstdlib> // atoi
using namespace std;

// This is the main function that will call all other functions in order
// to convert the expression from infix to postfix
string convertInfixToPostfix();

// determines if the expression being input by the user is valid
bool isValid(string expression, int size);

// determines whether the character passed as an argument is an operator
bool isOperator(char op);

// determines whether the precedence of first character is greater than
// or equal to the second character, and if so, it returns true
bool precedence(char op1, char op2);

// Two int variables and a character are passed as arguments into function
// The character will indicate which operation is being called to process
// the two ints
int calculator(int first, int second, char operator1);

// Evaluates a postfix expression that was previously validated
// and returns the result.
int postEvaluation(string expression);

int main()
{
  string conversion;
  conversion = convertInfixToPostfix();
  cout << "Conversion is: " << conversion << endl;

} // end main

string convertInfixToPostfix()
{
  string infix = "";
  string postfix = "";
  int length = 0;
  Postfix< char > charStack; // create Stack of chars
  charStack.push('(');

  std::cout << "Enter an arithmetic expression: ";
  std::getline(std::cin, infix);

  // test to see if the expression is valid
  length = infix.length();

  if(!isValid(infix, length))
  {
    cout << infix << " Is an invalid expression. Program terminated." << endl;
    exit(0);
  }


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
        charStack.push(operator2); // push the operator from infix to the stack
      }
      else // if stack contains an operator
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
        postfix += popChar;
      }
      charStack.pop(popChar); // this will pop the '(' on the stack
    }
    i++;
  }  // end while

  return postfix;
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

bool isValid(string expression, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(isdigit(expression[i]) || isOperator(expression[i])
      || expression[i] == ' ' || expression[i] == '(' || expression[i] == ')')
    {
      i++;
    }
    else
    {
      cout << expression[i] << " is an invalid element." << endl;
      return false;
    }
  }
  return true;
} // end isValid

int calculator(int first, int second, char operator1)
{
  int calculation = 0;
  if(operator1 == '/')
    calculation = first / second;
  if(operator1 == '*')
    calculation = first * second;
  if(operator1 == '^')
    calculation = pow(first, second);
  if(operator1 == '%')
    calculation = first % second;
  if(operator1 == '+')
    calculation = first + second;
  if(operator1 == '-')
    calculation = first - second;

  return calculation;
}// end calculator

int postEvaluation(string expression)
{
  int length = expression.length();
  Postfix< int > intStack; // create a Stack of ints
  int popInt = 0;
  int result = 0;
  int x = 0;
  int y = 0;
  char operatorA = ' ';

  // Analize the expression from left to right
  for(int i = 0; i < length; i++)
  {
    // if the current character is a digit
    if(isdigit(expression[i]))
    {
      //convert current character into an int
      int converted = expression[i] - '0';
      intStack.push(converted);
    }
    else // if the character is an operator
    {
      intStack.pop(popInt);
      x = popInt;
      intStack.pop(popInt);
      y = popInt;
      operatorA = expression[i];
      if(operatorA == '/' || operatorA == '-')
        result = calculator(y, x, operatorA);
      else
        result = calculator(x, y, operatorA);
    }// end else
  }// end for

  //pop the top element on the stack.  This is the result of the
  //postfix expression
  intStack.pop(popInt);
  return popInt;
}// end postEvaluation
