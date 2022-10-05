#include<stdio.h>
void swap(int *a,int *b)
{
   int temp = *a;
   *a  = *b;
   *b  =  temp;
}
int partition(int array[],int low,int high)
{
    int pivot = array[high];
    int i = (low -1);
    for(int j = low; j < high; j++)
    {
        if(array[j] <= pivot)
        {
           ++i;
           swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return (i+1);
}
void QuickSort(int array[],int low, int high)
{
    if(low < high)
    {
        int pi = partition(array,low,high);
        QuickSort(array,low,pi-1);
        QuickSort(array,pi+1,high);
    }
}
void display(int array[],int size)
{
    printf("Sorted Array\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
}
int main()
{
    int array[10],n;
    printf("Enter the size of array :");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Unsorted Array \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    QuickSort(array,0,n-1);
    display(array,n);

    return 0;
}