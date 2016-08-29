#include "binary_tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static QUEUE_T queue={NULL, NULL};

TREENODE_T* Create(int noOfNodes){
	TREENODE_T *root = NULL;
	for( int i = 0 ; i < noOfNodes ; i++ )
	{
		int data;
		printf("Enter data to add into Tree:-");
		scanf("%d",& data);
		root = Insert(root, data);
	}
	return root;
}

static TREENODE_T* GetParentNode(TREENODE_T *root){
	if(root->left == NULL || root->right == NULL)
		return root;
#ifdef DEBUG
	printf("left:-%x", root->left);
	printf("right:-%x", root->right);
#endif
	Enqueue(&queue, root->left);
	Enqueue(&queue, root->right);
#ifdef DEBUG
	Display(&queue);
#endif
	return GetParentNode(Dequeue(&queue));
}

TREENODE_T* Insert(TREENODE_T *root, int data){
	TREENODE_T *treenode = (TREENODE_T*)malloc(sizeof(TREENODE_T));
	if(NULL == treenode)
	{
		printf("Failed to create a TreeNode\n");
	}
	else
	{
		treenode->data = data;
		treenode->left = NULL;
		treenode->right = NULL;
		if(NULL == root)
		{
			root = treenode;
		}
		else
		{
			TREENODE_T *traverse = GetParentNode(root);
#ifdef DEBUG
			printf("Treenode =%x traverse = %x\n", treenode, traverse);
#endif
			if(traverse->left == NULL)
				traverse->left = treenode;
			else if(traverse->right == NULL)
				traverse->right = treenode;
			else
				printf("You have done some logical mistake\n");
		}
	}
	FreeAll(&queue);
	return root;
}

void PreOrder(TREENODE_T* root){
	if(root == NULL)
		return;
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(TREENODE_T* root){
	if(root == NULL)
		return;
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(TREENODE_T* root){
	if(root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

_Bool IsBST(TREENODE_T *root)
{
	if(root == NULL)
		return true;
	TREENODE_T *left = root->left;
	TREENODE_T *right = root->right;
	if(left && right) 
	{
			if(root->data > left->data && root->data < right->data)
				return IsBST(root->right) && IsBST(root->left);
			return false;
	}
	else if(left)
	{
		if(root->data > left->data)
			return IsBST(root->left);
		return false;
	}
	else if(right)
	{
		if(root->data < right->data)
			return IsBST(root->right);
		return false;	
	}
	return true;
}

void FreeAllTreeNodes(TREENODE_T *root)
{
	if(root == NULL)
		return;
	FreeAllTreeNodes(root->left);
	FreeAllTreeNodes(root->right);
	free(root);	
}
