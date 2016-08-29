#include "bst.h"
#include "stdio.h"

void SimulateBinarySearchTree()
{
	int noOfNodes;
	TREENODE_T *root = NULL;
	printf("Enter no of Nodes you want to create in tree:-");
	scanf("%d", &noOfNodes);
	root = CreateBST(noOfNodes);
	printf("\nPre-Order Traversal:-\n");
	PreOrder(root);
	printf("\nPost-Order Traversal:-\n");
	PostOrder(root);
	printf("\nIn-Order Traversal:-\n");
	InOrder(root);
	printf("\nThanks for using Binary Search Tree Demo, such codes are simple and one must be able do it on his own :) !!!\n");
	FreeAllTreeNodes(root);
}
int main()
{
	SimulateBinarySearchTree();
	return 0;
}
