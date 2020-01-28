#include<stdio.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int lower=0;
    int upper=9;
  int mid=0;
  int key=5;
    while(upper>=lower)
    {
         mid=(lower+upper)/2;
         if(a[mid]==key){
             printf("index of the element is: %d",mid);
             break;
         }
          else if(a[mid]>key)
          {
              upper=mid-1;
              
          }
          else
          {
              lower=mid+1;
          }
          
    }
}