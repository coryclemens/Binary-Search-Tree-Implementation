#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include "TreeNodeFinal.h"
#include <iostream>
using namespace std;
typedef int DataType;
class BST
{
 public:

  BST();

  bool empty() const; //!!

  bool search(const DataType & item) const; //!!

  void insert(const DataType & item); //!! (Necissary for homework)

  void remove(const DataType & item); //!!

  void inorder(ostream & out) const; //!!

  void postorder(ostream & out) const; //!!

  void preorder(ostream & out) const; //!!

  void graph(ostream & out) const;  //From textbook

 private:

  typedef TreeNode* NodePointer;
  friend class TreeNode;

  void parentSearch(const DataType & item, bool & found,
               NodePointer & locptr, NodePointer & parentNode) const;  //Locates node and its parent

  void inorderAux(ostream & out, NodePointer subtreePtr) const;  //!!
  void postorderAux(ostream & out, NodePointer subtreePtr) const; //!!
  void preorderAux(ostream & out, NodePointer subtreePtr) const; //!!

  void graphAux(ostream & out, int indent, NodePointer subtreeRoot) const; //From textbook

      //Data Members//
    NodePointer treeRoot;

};


#endif

