#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node *next;
struct node *previous;

}*first=NULL;




void create(int A[],int n){

struct node *last,*t;
int i;
first =(struct node *)malloc(sizeof(struct node));
t=first;
t->data=A[0];
t->previous =NULL;
t->next=NULL;

last=first;
for(i=1;i<n;i++){

    t=(struct node *)malloc(sizeof(struct node));
    last->next=t;
    t->next=NULL;
    t->data=A[i];
    t->previous=last;
    last=t;

}
last->next=NULL;
}

void display(){
struct node *p;
p=first;
while(p!=NULL){
    printf("\n %d",p->data);
    p=p->next;
}

}

void delete(int index){

struct node * p1,*p2;
int i;
p1=first;
for (i =1;i<index+1;i++){
    p1=p1->next;
    if(i==(index-2))
        p2=p1;



}
p2->next=p1;
p1->previous =p2;

}

void insert(int element,int index){

struct node *p3,*p4,*t1;

p3=first;
int i;
for(i =0;i<index;i++){

p3=p3->next;
}
p4=p3;
t1=(struct node *)malloc(sizeof(struct node));
t1->data=element;
t1->next =p4;
t1->previous =p4->previous;
(p4->previous)->next=t1;
p4->previous=t1;
}


void main(){
int array[10]={1,2,3,4,5,6,7,8,9,10};
create(array,10);

//delete(6);


insert(13,5);
display(array,10);
}
