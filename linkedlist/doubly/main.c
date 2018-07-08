#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

typedef enum
{
    CREATE =1,
    INSERT,
    DELETE,
    DISPLAY,
    EXIT
}LL_OPERATIONS_T;

int Menu()
{
    int choice = 0;
    do
    {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\nEnter your choice :-");
        scanf("%d", &choice);
    }while(choice < CREATE || choice > EXIT);
    return choice;
}
void SimulateSinglyLLOperations()
{
    NODE_T* head = NULL;
    while(1)
    {
        switch(Menu())
        {
            case CREATE:
            {
                if(head == NULL)
                {
                    int nodes = 0;
                    printf("\nEnter No Of Nodes To Create:-");
                    scanf("%d",&nodes);
                    head = create(nodes);
                }
                else
                {
                    printf("\nLinked List is already created, please use insert to add Nodes.");
                }
            }
            break;
            case INSERT:
            {
                int data = 0;
                unsigned int position = 0;
                printf("\nEnter position & data to insert:");
                scanf("%u%d", &position, &data);
                head = insert(head, data, position);
            }
            break;
            case DELETE:
            {
                unsigned int position = 0;
                printf("\nEnter position to delete:");
                scanf("%u", &position);
                head = delete(head, position);
            
            }
            break;
            case DISPLAY:
            {
                printf("\nDisplaying Linked List....");
                display(head);
            }
            break;
            case EXIT:
            {
                freeAll(head);
                exit(0);
            }
            break;
        }
    }
}

int main()
{
    SimulateSinglyLLOperations();
    return 0;
}
