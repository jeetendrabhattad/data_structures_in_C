#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Menu()
{
    int choice;
    printf("\n1. Insert\n2. Search\n3. Delete\n4. Exit :");
    scanf("%d", &choice);
    return choice;
}

int Hash(int data, int size)
{
    return data%size;
}
void Delete(int *hash_table, int data, int size)
{
    if(hash_table)
    {
        int key = Hash(data, size);
        for(int i = key ; i < size ; i++)
        {
            if(hash_table[i] == data)
            {
                hash_table[i] = -1;
                break;
            }
        }
    }
}

int Search(int *hash_table, int data, int size)
{
    int retVal = 0;
    if(hash_table)
    {
        int key = Hash(data, size);
        for(int i = key ; i < size ; i++)
        {
            if(hash_table[i] == data)
            {
                retVal = 1;
                break;
            }
        }
    }
    return retVal;
}

void Insert(int *hash_table, int data, int size)
{
    if(hash_table)
    {
        int key = Hash(data, size);
        if(hash_table[key] == -1)
        {
            hash_table[key] = data;
        }
        else
        {
            printf("Its Collision.....\n");
            for(int i = key+1 ; i < size ; i++)
            {
                if(hash_table[i] == -1)
                {
                    hash_table[i] = data;
                    break;
                }
            }
        }
    }
}

int main()
{
    printf("Welcome to Hashing Demo....\n");
    int data_size;

    printf("\nEnter the number of integers that you are going to enter:");
    scanf("%d", &data_size);

    int *hash_table;
    hash_table = (int*)malloc(data_size*sizeof(int));
    memset(hash_table, -1, data_size*sizeof(int));

    while(1)
    {
        switch(Menu())
        {
            case 1:
            {
                int data;
                printf("\nEnter data to insert:-");
                scanf("%d", &data);
                Insert(hash_table, data, data_size);
                for(int i = 0 ; i < data_size; i++)
                    printf("%d ", hash_table[i]);
            }
            break;
            case 2:
            {
                int data;
                printf("\nEnter data to search:-");
                scanf("%d", &data);
                if(Search(hash_table, data, data_size))
                {
                    printf("Data %d found in hash table\n", data);
                }
            }
            break;
            case 3:
            {
                int data;
                printf("\nEnter data to delete:-");
                scanf("%d", &data);
                Delete(hash_table, data, data_size);
                for(int i = 0 ; i < data_size; i++)
                    printf("%d ", hash_table[i]);
            
            }
            break;
            case 4:
                free(hash_table);
                exit(0);
        }
    }
    printf("\n");
    return 0;
}
