// ListNode class-template definition

#ifndef LISTNODE_H
#define LISTNODE_H

// class list required in order to be able to make List a friend
template< typename NODETYPE > class List;
template< typename NODETYPE >
class ListNode
{
  friend class List< NODETYPE >; // make List a friend

public:
  explicit ListNode( const NODETYPE &info ) // constructor
    : data(info), nextPtr(nullptr)
    {
      //empty body
    }// end constructor
    NODETYPE getData() const; //return data in node
    {
      return data;
    } // end getData
private:
  NODETYPE data;
  ListNode< NODETYPE > *nextPtr; //next node in list

}; // end class ListNode
#endif
