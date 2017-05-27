#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TREENODE_T;

TREENODE_T* Create(int noOfNodes);
TREENODE_T* Insert(TREENODE_T *root, int data);
void PreOrder(TREENODE_T*);
void InOrder(TREENODE_T*);
void PostOrder(TREENODE_T*);
_Bool IsBST(TREENODE_T *root);
void FreeAllTreeNodes(TREENODE_T *root);
int CountLeafNodes(TREENODE_T *root);
int CountNonLeafNodes(TREENODE_T *root);
// write to program to count leaf nodes
// write to program to count non-leaf nodes
// write to program to count parents having 2 children
#endif
