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
    int a[]={3,5,1,7,9,56,4,35,0};
    int n =9;
    int i,d;

    for(i=0;i<n;i++)
    {
        d=i;
        while(d>0 &&a[d-1]>a[d])
        {
            swap(&a[d-1],&a[d]);
            d--;
        }
    }
      for(i=0;i<n;i++)
      printf("%d\n",a[i]);
}