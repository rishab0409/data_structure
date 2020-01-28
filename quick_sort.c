#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int lb,int ub)
{
int pivot =a[lb];
int start=lb;
int end=ub;
while(start<end)
{
    while(a[start]<=pivot)
       start++;
       while(a[end]>pivot)
       end--;

if(start<end)
   swap(&a[start],&a[end]);
} 
swap(&a[lb],&a[end]);

return end;

}

void quicksort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
         quicksort(a,loc+1,ub); 
    }
}

void display(int a[],int lb,int ub)
{
    int i;
    for(i=lb;i<ub;i++)
     printf("%d \n",a[i]);
}
void main()
{
    int a[]={3,54,7,8,1,78,90};
    quicksort(a,0,7);
    display(a,0,7);
}