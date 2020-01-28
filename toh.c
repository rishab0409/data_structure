#include<stdio.h>

void toh(int num,char from,char aux,char to)
{
   if(num==1)
   {
       printf("\n move disk 1 from %c to %c",from,to);
       return;
   }
   toh(num-1,from,to,aux);
   printf("\n move disk %d from %c to %c",num,from,to);
   toh(num-1,aux,from,to);

}

void main()
{
toh(3,'A','B','C');

}