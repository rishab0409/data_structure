#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    
    temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int a[]={4,5,2,3,6,7,9,8};
 int n=8;
    int i,j;

    for(i=0;i<n-1;i++)
    {
           for(j=0;j<n-i-1;j++)
           {
               if(a[j]>a[j+1])
               swap(&a[j],&a[j+1]);
           }
    }

    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}