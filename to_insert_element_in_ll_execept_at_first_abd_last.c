#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node *next;

}*first=NULL;


void create(int size)
{
    int i;
    struct node *t,*copy;
    first =(struct node*)malloc(sizeof(struct node));
    first->data=0;
    copy =first;

   for(i=1;i<size;i++)
   {
       t=(struct node *)malloc(sizeof(struct node));
       t->data=i;
       copy->next=t;
       copy=t;


   }
   copy->next=NULL;


}
void insert(int data){
struct node * t3;
t3=first;

}

void display(){
int i;
struct node *t1;
t1=first;
while(t1!=NULL)
{
printf("%d",t1->data);
    t1=t1->next;
}

}
void main()
{
    int size,dataf,datal;
printf("enter the initial size if linked list");
scanf("%d",&size);
 create(size);
 display();
 printf("\n enter the  element to insert at first :");
 scanf("%d",&dataf);
 insert_start(dataf);
 printf("\n enter the element to insert at last :");
 scanf("%d",&datal);
 insert_last(datal);
 display();
}
