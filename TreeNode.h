// Noé Lomelí
// August 3, 2016
// TreeNode class template definition

#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of the class Tree
template< typename NODETYPE > class Tree;

template< typename NODETYPE >
class TreeNode
{
  friend class Tree< NODETYPE >;
public:
  //constructor
  TreeNode(const NODETYPE &d){leftPtr = nullPtr, data = d, rightPtr = nullPtr;}

  //return copy of node's data
  NODETYPE getData() const
  {
    return data;
  }// end getData
private:
  TreeNode< NODETYPE > *leftPtr;
  NODETYPE data;
  TreeNode< NODETYPE > *rightPtr;
}; // end class TreeNode
#endif
