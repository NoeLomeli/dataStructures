// Noé Lomelí
// August 3, 2016
// Creating and Traversing a binary Tree

#include <iostream>
#include <iomanip>
#include "Tree.h"
using namespace std;

int main()
{
  Tree< int > intTree; // create Tree of int values
  cout << "Enter 10 integer values:\n";

  //insert 10 integers to int Tree
  for(int i = 0; i < 10; i++)
  {
    int intValue = 0;
    cin >> intValue;
    intTree.insertNode(intValue);
  }// end for

  cout << "\nPreorder traversal \n";
  intTree.preOrderTraversal();

  cout << "\nInorder traversal\n";
  intTree.inOrderTraversal();

  cout << "\nPostorder traversal\n";
  intTree.postOrderTraversal();

  Tree< double > doubleTree;

  cout << fixed << setprecision(1) << "\n\nEnter 10 double values:\n";
  for(int j = 0; j < 10; j++)
  {
    double doubleValue = 0.0;
    cin >> doubleValue;
    doubleTree.insertNode(doubleValue);
  }//end for

  cout << "\nPreorder traversal \n";
  doubleTree.preOrderTraversal();

  cout << "\nInorder traversal\n";
  doubleTree.inOrderTraversal();

  cout << "\nPostorder traversal\n";
  doubleTree.postOrderTraversal();
  cout << endl;

}// end main
