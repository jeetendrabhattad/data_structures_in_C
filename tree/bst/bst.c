#include "bst.h"
#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

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

void NonRecursivePreorder(TREENODE_T * root)
{
    if(root == NULL)
        return;
    STACK_T st;
    st.STACK = NULL;

    InitStack(&st, 20);

    Push(&st, *root);
    while(!IsEmpty(&st))
    {
        TREENODE_T current = Pop(&st);
        printf("%d ", current.data);
        if(current.right)
            Push(&st, *(current.right));
        if(current.left)
            Push(&st, *(current.left));
    }
    DeInitStack(&st);
}
TREENODE_T* lowestCommonAncestor(TREENODE_T* root, int value1, int value2)
{
    while(root)
    {
        int value = root->data;
        if(value1 < root->data && value2 < root->data)
            root = root->left;
        else if(value1 > root->data && value2 > root->data)
            root = root->right;
        else
            return root;
    }   
    return NULL;
}

_Bool IsSubTree(TREENODE_T *main_tree, TREENODE_T *sub_tree, _Bool compare)
{
    if(NULL == sub_tree && NULL == main_tree)
        return  true;
    if(NULL == sub_tree || NULL == main_tree)
        return false;
    if(main_tree->data == sub_tree->data)
    {
        if(main_tree->left == NULL && main_tree->right == NULL && sub_tree->left == NULL && sub_tree->right == NULL)
        {
            printf("Data Same and left right null hence returning true\n");
            return true;        
        }
        printf("Date same hence calling for left and right\n");
        return IsSubTree(main_tree->left, sub_tree->left, true) && IsSubTree(main_tree->right, sub_tree->right, true);
    }
    else if(compare == false)
    {
        printf("Compare is false checking for other part\n");
        if(main_tree->data > sub_tree->data)
            return IsSubTree(main_tree->left, sub_tree, false);
        else
        {
            return IsSubTree(main_tree->right, sub_tree, false);
        }
    }
    return false;
}

void RotateRight(TREENODE_T **root)
{
    if(root && *root && (*root)->left)
    {
        TREENODE_T *newRoot = (*root)->left;
        (*root)->left = newRoot->right;
        newRoot->right = *root;
        *root = newRoot;
    }
}

void RotateLeft(TREENODE_T **root)
{
    if(root && *root && (*root)->right)
    {
        TREENODE_T *newRoot = (*root)->right;
        (*root)->right = newRoot->left;
        newRoot->left = *root;
        *root = newRoot;
    }
}

int DepthOfTree(TREENODE_T *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int left_depth = DepthOfTree(root->left);
    int right_depth = DepthOfTree(root->right);
    if(left_depth > right_depth)
        return 1+left_depth;
    else
        return 1+right_depth;
}

_Bool IsTreeBalanced(TREENODE_T *root)
{
    if(root)
    {
        if(abs(DepthOfTree(root->left) - DepthOfTree(root->right)) < 2)
            return true;
        return false;
    }
    return true;
}

TREENODE_T* GetUnBalancedRoot(TREENODE_T *root)
{
    if(root)
    {
        if(!IsTreeBalanced(root))
            return root;
        if(root->left)
        {
            return GetUnBalancedRoot(root->left);
        }
        if(root->right)
        {
            return GetUnBalancedRoot(root->right);
        }
    }
    return NULL;
}
