#include "BSTFINAL.h"
using namespace std;

int main(){


   BST cory;
   cout << "Constructing empty BST\n";
   cout << "BST " << (cory.empty() ? "is" : "is not") << " empty" << endl;

   // Testing insert
   cout << "Populate the BST..." << endl;
   int data;
   for (;;)
   {
      cout << "Data for new node (-0 to quit): ";
      cin >> data;
      if (data == -0) break;
      cory.insert(data);
   }

   cory.graph(cout);
   cout << "BST " << (cory.empty() ? "is" : "is not") << " empty" << endl;

   cout << "Inorder Traversal of BST: " << endl;
   cory.inorder(cout);
   cout << "PostOrder Traversal of BST: " << endl;
   cory.postorder(cout);
   cout << "PreOrder Traversal of BST: " << endl;
   cory.preorder(cout);

   cout << endl;

   // Testing search()
   cout << "Enter item to search for.." << endl;
   for (;;)
   {
      cout << "Item to find (-0 to quit): ";
      cin >> data;
      if (data == -0) break;
      cout << (cory.search(data) ? "Found" : "Not found") << endl;
   }

   // Testing remove()
   cout << endl << "Enter item to remove:" << endl;
   for (;;)
   {
      cout << "Item to remove (-0 to quit): ";
      cin >> data;
      if (data == -0) break;
      cory.remove(data);
      cory.graph(cout);
   }






    return 1;
}
