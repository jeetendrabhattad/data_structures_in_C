#include "bst.h"
#include "stdio.h"
#include "stdlib.h"

TREENODE_T *
CreateBST (int noOfNodes)
{
	TREENODE_T *root = NULL;
	for( int i = 0 ; i < noOfNodes ; i++ )
	{
		int data;
		printf("Enter data to add in BST:-");
		scanf("%d", &data);
		root = Insert(root, data);
	}
	return root;
}

TREENODE_T *
Insert (TREENODE_T * root, int data)
{
	TREENODE_T *treenode = (TREENODE_T*)malloc(sizeof(TREENODE_T));
	if(NULL == treenode)
	{
		printf("Failed to create treenode.\n");
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
			TREENODE_T *traverse = root;
			while(1)
			{
				if(treenode->data >= traverse->data)
				{
					if(traverse->right == NULL)
					{
						traverse->right = treenode;
						break;
					}
					else
					{
						traverse = traverse->right;
					}
				}
				else
				{
					if(traverse->left == NULL)
					{
						traverse->left = treenode;
						break;
					}
					else
					{
						traverse = traverse->left;
					}
				}
			}
		}
	}
	return root;
}

_Bool
Search (TREENODE_T * root, int data)
{
}

void
PreOrder (TREENODE_T * root)
{
  if (root == NULL)
    return;
  printf ("%d ", root->data);
  PreOrder (root->left);
  PreOrder (root->right);
}

void
InOrder (TREENODE_T * root)
{
  if (root == NULL)
    return;
  InOrder (root->left);
  printf ("%d ", root->data);
  InOrder (root->right);
}

void
PostOrder (TREENODE_T * root)
{
  if (root == NULL)
    return;
  PostOrder (root->left);
  PostOrder (root->right);
  printf ("%d ", root->data);
}

void
FreeAllTreeNodes (TREENODE_T * root)
{
  if (root == NULL)
    return;
  FreeAllTreeNodes (root->left);
  FreeAllTreeNodes (root->right);
  free (root);
}
