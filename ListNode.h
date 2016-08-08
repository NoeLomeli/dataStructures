// ListNode class-template definition

#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List in order to make List a friend
template< typename NODETYPE > class List;

template< typename NODETYPE >
class ListNode
{
  friend class List< NODETYPE >; // make List a friend

public:
  // constructor will initialize data and nextPtr
  explicit ListNode( const NODETYPE &info ){ data = info, nextPtr = nullptr;}
  // return data in node
  NODETYPE getData() const{ return data;} // end getData
private:
  NODETYPE data;
  ListNode< NODETYPE > *nextPtr; //next node in lists

}; // end class ListNode
#endif
