#include <stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node *next;

}*first=NULL;
void create(){



struct node *p1,*p2;
p1=(struct node*)malloc(sizeof(struct node));
p1->data=1;
first =p1;

for(int i=2;i<7;i++){
            p2=(struct node*)malloc(sizeof(struct node));

    p2->data=i;

    p1->next=p2;
    p1=p2;
}
    p2->next=first;
}
// void delete1(int a){
//  struct node *p5;
//  p5=first;
//  int i=1;

//  if(a==1){
// while( i<6){
//     p5=p5->next;
//     i++;

// }
// p5->next=first->next;
// first=first->next;

//  }
// }

void delete(int a)
{
struct node *p,*r;
p=first;

while(p->data!=a)
{
    r=p;
    p=p->next;
}
r->next=p->next;
}
 void delete_first()
 { int i=1;
 struct node *p;
 p=first;
     while(p->next!=first)
     {
           p=p->next;
     }
     p->next=first->next;
     first=first->next;

 }

int count(){
    struct node *p5;
    int count =1;
    p5 =first;
    while(p5->next!=first){
        count=count+1;
        p5=p5->next;
    }
  //  printf("%d",count);
   // printf("\n");
   return count;
}
void delete_last()
{   struct node *p;
p=first;
    int i;
    for(i=1;i<count()-1;i++)
    {
        p=p->next;

    }
    p->next=first;
}

void display()
{
    struct node *p3;
  p3=first;
  while(p3->next !=first){
    printf("%d\n",p3->data);
    p3=p3->next;

}
printf("%d",p3->data);

}
void main(){

create();
//count();
delete(3);
delete_first();
delete_last();

// struct node *p3;
// p3=first;
// while(p3->next !=first){

//     printf("%d\n",p3->data);
//     p3=p3->next;


// }
// printf("%d",p3->data);

// //printf("\n %d",count());
display();


}

