#include<stdio.h>
#include<stdlib.h>
#define size 5
int FRONT = 0;
int REAR = 0;
int Queue[size];
void insert(int data)
{
   
}
void delete()
{
    if(REAR == FRONT)
    {
        printf("Underflow\n");
    }
    else{
        int ele = 0;
        ele += Queue[FRONT];
        printf("%d - Item Dleted\n",ele);
        for(int i = FRONT; i < REAR-1; i++)
        {
            Queue[i] = Queue[i+1];
        }
        --REAR;
    }
}
void traverse()
{
    if(REAR == FRONT)
    {
        printf("No Element Found\n");
    }
    else 
    {
        printf("Queue data\n");
        for(int i = FRONT; i < REAR; i++)
        {
            printf("%d ",Queue[i]);
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    int data;
    while(1){
        printf("Enter ur choice : \n");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Traverse");
        printf("\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter the data \n");
            scanf("%d",&data);
            insert(data);
            break;

            case 2:
            delete();
            break;

            case 3:
            traverse();
            break;

            case 4:
            exit(0);
        }
    }
}