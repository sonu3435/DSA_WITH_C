#include<stdio.h>
#include<stdlib.h>
struct queue q;
struct queue{
    int f;
    int r;
    int size;
    int* arr;
};
int Isfull(){
    if((q.r == 0 && q.r== q.size-1)||(q.r+1 == q.f)){
        return 1;
    }
    else return 0;
}
int Isempty(){
    if(q.f == q.r) return 1;
    else return 0;
}

void Renque(){

    int data;
    if(Isfull()){
        printf("Queue is Full\n");
    }
    else{
        printf("Enter the data : ");
        scanf("%d",&data);
      
        if(q.r == -1){
        q.f = q.r = 0;
        q.arr[q.r] = data;
       }
       else {
          ++q.r;
          q.arr[q.r] = data;
       }
    }
}

void Fenque(){
    int data;
    if(Isfull()){
        printf("Queue is Full \n");
    }
    else {
        printf("Enter the data : ");
        scanf("%d",&data);
        if(q.f == -1){
            q.f = q.r = 0;
            q.arr[q.f] = data;
        }
        else if(q.f == 0){
            q.f = q.size-1;
            q.arr[q.f] = data;
        }
        else {
            --q.f;
            q.arr[q.f] = data;
        }
    }
}

void Rdeque(){
    if(Isempty()){
        printf("Queue is empty \n");
    }
    else if(q.r == 0){
        printf("\nItem deleted : %d",q.arr[q.r]);
        --q.r;
    }
    else {
        printf("\nitem deleted : %d",q.arr[q.r]);
        --q.r;
    }
}
void Fdeque(){
    if(Isempty()){
        printf("Queue is empty \n");
    }
    else if(q.f == q.size-1){
        printf("\nItem deleted : %d",q.arr[q.f]);
        q.f = 0;
    }
    else {
        printf("\nItem deleted : %d",q.arr[q.f]);
        ++q.f;
    }
}

void traverse(){
   int temp;
   if(Isempty()){
    printf("Queue is empty\n");
   }
   else {
    temp = q.f;
    while((temp)%q.size != q.r+1){
        printf("%d ",q.arr[temp]);
        temp = (temp+1)% q.size;
    }
    }
}
int main(){
    q.arr = (int*)malloc(q.size*sizeof(int));
    q.size = 5;
    q.f = q.r = -1;
    Fenque();
    Fenque();
    Fenque();
    Renque();
   traverse();
}