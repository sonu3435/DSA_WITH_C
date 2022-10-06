#include<stdio.h>
#include<stdlib.h>
#define size 5
int FRONT = -1,REAR = -1;
int Queue[size];

void insertion()
{
   int data;
   if((FRONT ==0 && REAR == size-1 ) || (REAR+1 == FRONT)){
    printf("Overflow\n");
   }
   else {
    printf("Enter the element \n");
    scanf("%d",&data);  
      if(REAR == -1){
        FRONT = 0; 
        REAR = 0;
      }
      else if(REAR ==  size-1){
        REAR = 0;
      }
      else {
        REAR++;
      }
      Queue[REAR] = data;
   }
}
void deletion()
{
    int q;
  if(FRONT == -1){
     printf("UnderFlow\n");
  }
  else{

    q = FRONT[Queue];
    if(FRONT == REAR){
        FRONT = -1;
        REAR = -1;
    }
    else if(FRONT == size-1){
        FRONT = 0;
    }
    else {
        FRONT++;
    }
    printf("%d item deleted \n",q);
  }
}
void traverse()
{
  int i,j;
   if(FRONT > REAR)
   {
      for(i = FRONT; i <= size-1; i++ )
      {
        printf("%d ",Queue[i]);
      }
      for(j = 0; j <= REAR; j++)
      {
        printf("%d ",Queue[j]);
      }
   }
   else{
       
       for(j=FRONT; j <= REAR; j++){

        printf("%d ",Queue[j]);
       }
   }
}
int main()
{
    int choice;
   while(1){
    printf("\n\nEneter your choice");
    printf("\n1.Insert()\n");
    printf("2.dalete()\n");
    printf("3.traverse()\n");
    printf("4.Exit()\n\n");
    scanf("%d",&choice);
    switch(choice){

    case 1:
    insertion();
    break;

    case 2:
    deletion();
    break;

    case 3:
    traverse();
    break;

    case 4:
    exit(0);
    }
   }

   
}