#ifndef BST_H_
#define BST_H_
#include <stdbool.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TREENODE_T;

TREENODE_T *CreateBST(int noOfNodes);
TREENODE_T *Insert(TREENODE_T *root, int data);
_Bool Search(TREENODE_T *root, int data);
void PreOrder(TREENODE_T*);
void InOrder(TREENODE_T*);
void PostOrder(TREENODE_T*);
void FreeAllTreeNodes(TREENODE_T *root);

#endif
