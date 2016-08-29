#include "binary_tree.h"
#include "stdio.h"

void SimulateBinaryTree()
{
	int noOfNodes;
	TREENODE_T *root = NULL;
	printf("Enter no of Nodes you want to create in tree:-");
	scanf("%d", &noOfNodes);
	root = Create(noOfNodes);
	printf("\nPre-Order Traversal:-\n");
	PreOrder(root);
	printf("\nPost-Order Traversal:-\n");
	PostOrder(root);
	printf("\nIn-Order Traversal:-\n");
	InOrder(root);
	printf("\nChecking if Binary Tree is BST as well :) %s\n", IsBST(root) ? "YES":"NO");

	printf("\nThanks for using Binary Tree Demo, such codes are exceptional and one should do it on his own :) !!!\n");

	FreeAllTreeNodes(root);
}
int main()
{
	SimulateBinaryTree();
	return 0;
}
