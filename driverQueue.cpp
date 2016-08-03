// Noé Lomelí
// August 3, 2016
// Queue processing program

#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
  Queue< int > intQueue; // Queue class definition
  cout << "processing an integer Queue" << endl;
  // enqueue integers onto intQueue
  for(int i = 0; i < 3; i++)
  {
    intQueue.enqueue(i);
    intQueue.printQueue();
  }// end for

  int dequeueInteger; // store dequeued integer
  //dequeue integers from intQueue
  while(!intQueue.isQueueEmpty())
  {
    intQueue.dequeue(dequeueInteger);
    cout << dequeueInteger << " dequeued" << endl;
    intQueue.printQueue();
  }// end while

  Queue< double > doubleQueue; // create Queue of doubles
  double value = 1.1;
  cout << "processing a double Queue" << endl;
  //enqueue floating point values
  for(int j = 0; j < 3; j++)
  {
    doubleQueue.enqueue(value);
    doubleQueue.printQueue();
    value += 1.1;
  }// end for

  double dequeueDouble; // store dequeued double
  //dequeue floating point values
  while(!doubleQueue.isQueueEmpty())
  {
    doubleQueue.dequeue(dequeueDouble);
    cout << dequeueDouble << " dequeued" << endl;
    doubleQueue.printQueue();
  }// end while
}//end main

// g++ -std=c++11 List.h Queue.h ListNode.h driverQueue.cpp
