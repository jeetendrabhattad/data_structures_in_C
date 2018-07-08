#include "singly_circular.h"
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
    newNode->next = NULL;
    newNode->data = data;
    
    if(position == 1)
    {
        if(head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            NODE_T* traverse = head;
            while(traverse->next != head)
            {
                traverse = traverse->next;
            }
            newNode->next = head;
            traverse->next = newNode;
            head = newNode;
        }
    }
    else
    {
        NODE_T *traverse = head;
        int pos = position;
        while(traverse->next != head && pos-2 !=0 )
        {
            traverse=traverse->next;
            pos--;
        }
        newNode->next=traverse->next;
        traverse->next=newNode;
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
            NODE_T* traverse = head;
            while(traverse->next != head)
            {
                traverse = traverse->next;
            }
            temp = head;
            if(head->next != head)
                head = head->next;
            else
                head = NULL;
            traverse->next = head;
            temp->next = NULL;
        }
        else
        {
            NODE_T *traverse = head;
            int pos = position;
            while(traverse->next != head && pos-2)
            {
                traverse = traverse->next;
                pos--;
            }
            if(pos-2 == 0)
            {
                temp = traverse->next;
                traverse->next = temp->next;
                temp->next = NULL;
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
    if(head)
    {
        NODE_T *traverse = head;
        do
        {
            printf("\nData=%d", traverse->data);
            traverse = traverse->next;
        }while(traverse != head);
    }
}

void    freeAll(NODE_T* head)
{
    while(head)
    {
        head = delete(head, 1);
    }
}
