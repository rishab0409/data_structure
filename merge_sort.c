#include<stdio.h>

void merge(int a[],int lb,int mid,int ub)
{
  int i=lb;
  int j=mid+1;
  int k=lb;
   int b[ub+1];
  while(i<=mid &&j<=ub)
  {
      if(a[i]<=a[j])
      {
        b[k]=a[i];
        i++;k++;
      }
      else
      {
          b[k]=a[j];
          k++;j++;
      }
      
  }
  
      while(j<=ub)
      {
          b[k]=a[j];
          k++;j++;
      }
  

  
      while(i<=mid)
      {
          b[k]=a[i];
          k++;i++;
      }
  
  for(i=lb;i<=ub;i++)
    a[i]=b[i];
 }
// void merge(int arr[], int l, int m, int r) 
// { 
//     int i, j, k; 
//     int n1 = m - l + 1; 
//     int n2 =  r - m; 
  
//     /* create temp arrays */
//     int L[n1], R[n2]; 
  
//     /* Copy data to temp arrays L[] and R[] */
//     for (i = 0; i < n1; i++) 
//         L[i] = arr[l + i]; 
//     for (j = 0; j < n2; j++) 
//         R[j] = arr[m + 1+ j]; 
  
//     /* Merge the temp arrays back into arr[l..r]*/
//     i = 0; // Initial index of first subarray 
//     j = 0; // Initial index of second subarray 
//     k = l; // Initial index of merged subarray 
//     while (i < n1 && j < n2) 
//     { 
//         if (L[i] <= R[j]) 
//         { 
//             arr[k] = L[i]; 
//             i++; 
//         } 
//         else
//         { 
//             arr[k] = R[j]; 
//             j++; 
//         } 
//         k++; 
//     } 
  
//     /* Copy the remaining elements of L[], if there 
//        are any */
//     while (i < n1) 
//     { 
//         arr[k] = L[i]; 
//         i++; 
//         k++; 
//     } 
  
//     /* Copy the remaining elements of R[], if there 
//        are any */
//     while (j < n2) 
//     { 
//         arr[k] = R[j]; 
//         j++; 
//         k++; 
//     } 
// } 
  

void mergesort(int a[],int lb,int ub)
{
    
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);

    }
}
void display(int a[],int lb,int ub)
{
   for(int i=0;i<=ub;i++)
   printf("%d\n",a[i]);
}
void main()
{
    int a[]={3,4,1,78,90,56,98};
    mergesort(a,0,6);
    display(a,0,6);
}