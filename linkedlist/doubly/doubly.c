#include "doubly.h"
#include <stdio.h>
#include <stdlib.h>

NODE_T* create(const unsigned noOfNodes)
{
    NODE_T* head = NULL;
    for(int i = 0 ; i < noOfNodes ; i++)
    {
        int data;
        printf("\nEnter data to insert:");
        scanf("%d",&data);
        head = insert(head, data, i+1);
    }
    return head;
}

NODE_T* insert(NODE_T* head, const int data, const unsigned position)
{
    NODE_T *newNode = (NODE_T*)malloc(sizeof(NODE_T));
    if(NULL == newNode)
        return head;
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    
    if(position == 1)
    {
        if(head)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        NODE_T *traverse = head;
        int pos = position;
        while(traverse->next && pos-2 !=0 )
        {
            traverse=traverse->next;
            pos--;
        }
        newNode->prev = traverse;
        newNode->next = traverse->next;
        traverse->next=newNode;
        if(newNode->next)
            newNode->next->prev = newNode;
    }
    return head;
}

NODE_T* delete(NODE_T* head, const unsigned position)
{
    if(head)
    {
        NODE_T *temp = NULL;
        if(position == 1)
        {
            temp = head;
            head = head->next;
            if(head)
                head->prev = NULL;
            temp->next = NULL;
        }
        else
        {
            NODE_T *traverse = head;
            int pos = position;
            while(traverse->next && pos-2)
            {
                traverse = traverse->next;
                pos--;
            }
            if(pos-2 == 0)
            {
                temp = traverse->next;
                traverse->next = temp->next;
                if(temp->next)
                {
                    temp->next->prev = traverse;
                }
                temp->next = NULL;
                temp->prev = NULL;
            }
            else
            {
                printf("\nLooks like you forgot number of nodes in linkedlist and hence giving wrong position as input for delete.");
            }
        }
        if(temp)
            free(temp);
    }
    return head;
}

void    display(NODE_T* head)
{
    while(head)
    {
        printf("\nData=%d", head->data);
        head = head->next;
    }
}

void    reverseDisplay(NODE_T* head)
{
    while(head->next)
    {
        head = head->next;
    }
    while(head)
    {
        printf("\nData=%d", head->data);
        head = head->prev;
    }
}

void    freeAll(NODE_T* head)
{
    while(head)
    {
        head = delete(head, 1);
    }
}

// write a function to find out length of a linkedlist
// write a function to delete all nodes based on data
// write a function to print singly linked list in reverse order
// write a function to print middle node information traversing linkedlist only once (length should not be used)
// write a program to implement stack using linkedlist
// write a program to implement queue using linkedlist
// write a insert function which inserts data in ascending order of sorting i.e sorted linkedlist
unsigned int length(NODE_T *head)
{
    unsigned int length = 0;
    for(NODE_T *traverse = head ; traverse != NULL ; traverse = traverse->next)
    {
        length++;
    }
    return length;
}
// write a function to delete all nodes based on data
NODE_T* deleteBasedOnData(NODE_T *head, int data)
{
    if(head)
    {
        NODE_T *traverse = head;
        NODE_T *temp = NULL;
        //this loop handles 1st position having required data as well as it considers if whole linkedlist has same data.
        while(traverse)
        {
            if(head->data == data)
            {
                temp = head;
                head = head->next;
                temp->next = NULL;
                free(temp);
                traverse = head;
            }
            else
            {
                break;
            }
        }
        while(traverse && traverse->next)
        {
            if(traverse->next->data == data)
            {
                temp = traverse->next;
                traverse->next = temp->next;
                if(temp->next)
                {
                    temp->next->prev = traverse;
                }
                temp->next = NULL;
                free(temp);
            }
            else
            {
               traverse = traverse->next;
            }
        }
    }
    return head;
}

NODE_T* middleNode(NODE_T *head)
{
    NODE_T *traverse1 = head;
    NODE_T *traverse2 = head;
    while(traverse2 && traverse2->next && traverse2->next->next)
    {
        traverse1 = traverse1->next;
        traverse2 = traverse2->next->next;
    } 
    return traverse1;
}
