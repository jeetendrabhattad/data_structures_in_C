#ifndef SINGLY_CIRCULAR_H
#define SINGLY_CIRCULAR_H

typedef struct Node
{
    int data;
    struct Node *next; //self referntial stucture
}NODE_T;

NODE_T* create(const unsigned noOfNodes);
NODE_T* insert(NODE_T* head, const int data, const unsigned position);//kashyat insert karycha, konala insert karycha, kuthlya position la insert karycha
NODE_T* delete(NODE_T* head, const unsigned position);
void    display(NODE_T* head);
void    freeAll(NODE_T* head);
#endif
