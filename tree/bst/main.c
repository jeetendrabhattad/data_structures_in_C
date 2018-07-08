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
    printf("\nNon Recursive Pre Order:-\n");
    NonRecursivePreorder(root);
    #if 0
    int value1, value2;
    printf("\nEnter 2 nodes whose least common ancestor is to be found:");
    scanf("%d%d", &value1, &value2);
    TREENODE_T *lcs = lowestCommonAncestor(root, value1, value2);
    if(lcs)
        printf("Lowest Common Ancestor Node is:%d", lcs->data);
    printf("\n Comparing 2 trees for subtree:-");
    int node_count;
	TREENODE_T *new_root = NULL;
	printf("Enter no of Nodes you want to create in tree:-");
	scanf("%d", &node_count);
	new_root = CreateBST(node_count);
    if( IsSubTree(root, new_root, false) )
    {
        printf("\nSubtree\n");
    }
    else
        printf("\nNot a Subtree\n");

    RotateRight(&root);
	printf("\nPre-Order Traversal:-\n");
	PreOrder(root);

    RotateLeft(&root);
	printf("\nPre-Order Traversal:-\n");
	PreOrder(root);
    #endif
    printf("\nDepth of Tree:-%d\n", DepthOfTree(root));

    TREENODE_T *test = GetUnBalancedRoot(root);
    if(test)
        printf("data of unbalanced node is %d\n", test->data);

    printf("\nLeaf Nodes:-%d", countLeafNodes(root));
	printf("\nNon Leaf Nodes:-%d", countNonLeafNodes(root));

    printf("\nThanks for using Binary Search Tree Demo, such codes are simple and one must be able do it on his own :) !!!\n");
	FreeAllTreeNodes(root);
	//FreeAllTreeNodes(new_root);
}
int main()
{
	SimulateBinarySearchTree();
	return 0;
}
