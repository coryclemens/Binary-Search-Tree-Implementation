#ifndef TREE_NODE
#define TREE_NODE
#include <iostream>



class TreeNode{

public:
	TreeNode();
	TreeNode(int data);
	int getItem()const;


private:
    typedef TreeNode * nodePointer;
	friend class BST;
	int data;
	TreeNode * Lchild,
				*Rchild;

};

inline TreeNode::TreeNode()
    :Lchild(0), Rchild(0)
{

}

inline TreeNode::TreeNode(int data)
	: data(data), Lchild(0), Rchild(0)
{

}

inline int TreeNode::getItem() const
{
	return data;
}
#endif
