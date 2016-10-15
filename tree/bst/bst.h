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
void NonRecursivePreorder(TREENODE_T*);
TREENODE_T* lowestCommonAncestor(TREENODE_T*, int, int);
void FreeAllTreeNodes(TREENODE_T *root);
_Bool IsSubTree(TREENODE_T *main_tree, TREENODE_T *sub_tree, _Bool);
void RotateRight(TREENODE_T **root);
void RotateLeft(TREENODE_T **root);
int DepthOfTree(TREENODE_T *root);
_Bool IsTreeBalanced(TREENODE_T *root);
TREENODE_T* GetUnBalancedRoot(TREENODE_T *root);
#endif
