// Noé Lomelí
// Linked list program allow user to add new nodes at the front or back of the list
// August 02, 2016

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

// display program instructions to user
void instructions()
{
  cout << "Enter one of the following:\n"
       << " 1 to insert at beginning of list\n"
       << " 2 to insert at end of list\n"
       << " 3 to delete from beginning\n"
       << " 4 to delete from end of list\n"
       << " 5 to end list processing\n";
}// end instructions

// function to test a list
template< typename T >
void testList(List< T > &listObject, const string &typeName)
{
  cout << "Testing a List of " << typeName << " values\n";
  instructions(); // display instructions
  int choice = 0;
  T value;

  do
  {
    cout << "? ";
    cin >> choice;
    switch(choice)
    {
      case 1: // insert at beginning
        cout << "Enter " << typeName << ": ";
        cin >> value;
        listObject.insertAtFront(value);
        listObject.print();
        break;
      case 2: // insert at end
        cout << "Enter " << typeName << ": ";
        cin >> value;
        listObject.insertAtBack(value);
        listObject.print();
        break;
      case 3: // remove from beginning
        if(listObject.removeFromFront(value))
          cout << value << " removed from list\n";
        listObject.print();
        break;
      case 4: // remove from end
        if(listObject.removeFromBack(value))
          cout << value << " removed from list\n";
        listObject.print();
        break;
    }// end switch
  } while(choice != 5); // end do...while
  cout << "End list test\n\n";
}// end testList

int main()
{
  // test List of int values
  List< int > integerList;
  testList(integerList, "integer");
  // test List of double values
  List< double > doubleList;
  testList(doubleList, "double");
  List< string > stringList;
  testList(stringList, "string");
}// end main
