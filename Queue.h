// Noé Lomelí
// August 3, 2016
// Queue class template

#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

template< typename QUEUETYPE >
class Queue : private List< QUEUETYPE >
{
public:
  //enqueue calls List member fuction insertAtBack
  void enqueue(const QUEUETYPE &data)
  {
    this->insertAtBack(data);
  }// end function enqueue

  //dequeue calls List member function removeFromFront
  bool dequeue(QUEUETYPE &data)
  {
    return this->removeFromFront(data);
  }// end dequeue

  // isQueueEmpty calls List member function isEmpty
  bool isQueueEmpty() const
  {
    return this->isEmpty();
  }// end isQueueEmpty

  //printQueue calls List member function print
  void printQueue() const
  {
    this->print();
  }// end printQueue
};
#endif
