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
  explicit ListNode( const NODETYPE &info ){ data = info, nextPtr = nullptr;}

  NODETYPE getData() const{ return data;} // end getData
private:
  NODETYPE data;
  ListNode< NODETYPE > *nextPtr; //next node in lists

}; // end class ListNode
#endif
