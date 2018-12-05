#include "BSTFINAL.h"

//CONSTRUCTOR//
BST::BST()
: treeRoot(0)
{}

bool BST::empty() const
{ return treeRoot == 0; }

bool BST::search(const DataType & item) const //Search for specific item in Tree
{
   NodePointer locptr = treeRoot;
   bool found = false;
   while (!found && locptr != 0)  //while not found and not end of tree
   {
      if (item < locptr->data)
        locptr = locptr->Lchild;
      else if (locptr->data < item)
        locptr = locptr->Rchild;
      else
        found = true;
   }
   return found;
}


void BST::insert(const DataType & item)
{
    NodePointer locptr = treeRoot,
    parentNode = 0;
   bool found = false;
   while (!found && locptr != 0)
   {
      parentNode = locptr;
      if (item < locptr->data)
         locptr = locptr->Lchild;
      else if (locptr->data < item)
         locptr = locptr->Rchild;
      else
         found = true;
   }
   if (!found)
   {
      locptr = new(nothrow) TreeNode(item);
      if (parentNode == 0)               // empty tree
         treeRoot = locptr;
      else if (item < parentNode->data )  // insert to Lchild of parentNode
         parentNode->Lchild = locptr;
      else                           // insert to Rchild of parentNode
         parentNode->Rchild = locptr;
   }
   else
      cout << "Item already in tree\n";
}


void BST::remove(const DataType & item)
{
   bool found;
   NodePointer deletePtr,             //points to deletion node
               parentNode;            //parentNode of deletePtr and succPtr
   parentSearch(item, found, deletePtr, parentNode); //find node to be deleted and its parent

   if (!found)
   {
      cout << "Item not in the BST\n";
      return;
   }
   if (deletePtr->Lchild != 0 && deletePtr->Rchild != 0) //if node has two child nodes, find successor
   {
      NodePointer succPtr = deletePtr->Rchild;
      parentNode = deletePtr;
      while (succPtr->Lchild != 0)       // descend to successor
      {
         parentNode = succPtr;
         succPtr = succPtr->Lchild;
      }



     deletePtr->data = succPtr->data; //swap the data from successor into delete node
     deletePtr = succPtr;
   }

   // Now proceed with case where node has 0 or 2 child
   NodePointer subtree = deletePtr->Lchild;             // pointer to a subtree of deletePtr
   if (subtree == 0)
      subtree = deletePtr->Rchild;
   if (parentNode == 0)                  // remove root
      treeRoot = subtree;
   else if (parentNode->Lchild == deletePtr)       // Lchild child of parentNode
      parentNode->Lchild = subtree;
   else                              // Rchild child of parentNode
      parentNode->Rchild = subtree;
   delete deletePtr;
}

//--- Definition of parentSearch()
void BST::parentSearch(const DataType & item, bool & found,
                            NodePointer & locptr,
                            NodePointer & parentNode) const
{
   locptr = treeRoot;
   parentNode = 0;
   found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend Lchild
      {
         parentNode = locptr;
         locptr = locptr->Lchild;
      }
      else if (locptr->data < item)  // descend Rchild
      {
         parentNode = locptr;
         locptr = locptr->Rchild;
      }
      else                           // item found
         found = true;
   }
}

// Definition of inorder() (LVR)
void BST::inorder(ostream & out) const
{
   inorderAux(out, treeRoot);
   out << endl;
}

void BST::inorderAux(ostream & out, NodePointer subtreeRoot) const
{
   if (subtreeRoot != 0)
   {
      inorderAux(out, subtreeRoot->Lchild);    // L
      out << subtreeRoot->data << "  ";      // V
      inorderAux(out, subtreeRoot->Rchild);   // R
   }

}

//Definition of preorder (VLR)
void BST::preorder(ostream & out)const
{
    preorderAux(out, treeRoot);
    out << endl;
}

void BST::preorderAux(ostream & out, NodePointer subtreeRoot)const
{
    if(subtreeRoot != 0)
    {
        out << subtreeRoot->data << "  ";     //V
        preorderAux(out, subtreeRoot->Lchild); //L
        preorderAux(out, subtreeRoot->Rchild);  //R

    }

}

//Definition of postorder (LRV)
void BST::postorder(ostream & out)const
{
    postorderAux(out, treeRoot);
    out << endl;
}

void BST::postorderAux(ostream & out, NodePointer subtreeRoot)const
{
    if(subtreeRoot != 0)
    {
       postorderAux(out, subtreeRoot->Lchild);  //L
       postorderAux(out, subtreeRoot->Rchild);  //R
       out << subtreeRoot->data << "  ";       //V

    }

}

//Definition of graphAux() from textbook solution
#include <iomanip>

void BST::graph(ostream & out) const
{ graphAux(out, 0, treeRoot); }

void BST::graphAux(ostream & out, int indent, NodePointer subtreeRoot) const
{
  if (subtreeRoot != 0)
    {
      graphAux(out, indent + 8, subtreeRoot->Rchild);
      out << setw(indent) << " " << subtreeRoot->data << endl;
      graphAux(out, indent + 8, subtreeRoot->Lchild);
    }
}
