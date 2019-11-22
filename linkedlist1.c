#include<stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node *next;

}*first=NULL; //declaring here make the pointer first global

void form(int array[],int n){
struct node *t,*copy;
first =(struct node *)malloc(sizeof(struct node));
first->data =array[0];
first->next =NULL;
copy =first;


for(int i=1;i<n;i++){

    t =(struct node *)malloc(sizeof(struct node));
    t->data=array[i];
    t->next=NULL;
    copy->next=t;
    copy=t;
    }

}

void deleteduplicate(){
struct node *p8,*p9,*p10;
p8=first;
while(p8 !=NULL){
p9 =p8;
    while(p9!=NULL){

p10 =p9;
   A: p9 =p9->next;

    if(p8->data == p9->data){

       p10->next =p9->next;
goto A;


    }


    }
    p8=p8->next;

}

}

void ifsorted(){
struct node *p7;
p7=first;
int a,count =0;;
while(p7->next !=NULL){
      a=p7->data;
      p7=p7->next;
if( a > p7->data)
{
printf("\n the linked list is not sorted");
count++;
break;
}
}
if(count==0)
printf("\n the linked list is sorted");

}

    int numofelements(){
    int count=0;
    struct node *c;
    c=first;
    while(c!=0){
        c=c->next;
        count=count+1;

    }
    return count;

    }

void insertingelementinlast(){

struct node *e,*r;
int n= numofelements();
e=first;
for (int i =1;i<n;i++){
    e=e->next;

}
r =(struct node *)malloc(sizeof(struct node));
r->data=11;
e->next=r;
r->next=NULL;
}

 void deletingelementatthebegining(){
first =first->next;



}

void searching(int a){

struct node *p6;
int i=1;
p6=first;
while(p6!=NULL){

    if(p6->data == a)
       {printf("\n the element is at position %d",i);
       break;}
    else
        p6=p6->next;
        i++;
}
}
 void deletingelementnatend(){
 struct node *u;
 u=first;
 int n=numofelements();

 for(int i=1;i<n-1;i++){

    u=u->next;

 }
 u->next=NULL;
 }

 void deletingelementatindex(int a){
     struct node *o,*d;
 int m=numofelements();
 o=first;
 if(a<=m){
 for(int i=0;i<a-1;i++){
    o=o->next;

 }
 d=o;
 for(int j=1;j<3;j++){

    d=d->next;

 }
 o->next=d;
 }
 }

void insertingelementinbeginning(){

struct node *w;



w=(struct node *)malloc(sizeof(struct node));
w->data=10;
w->next=first;
first=w;

}

void insertelementafterindex(int a){

struct node *begin,*end,*in;
int i=1,j=1;
in =(struct node *)malloc(sizeof(struct node));
in->data=15;
begin =first;
while(i<a){

    begin =begin->next;
    i=i+1;

}
end =first;
while(j<a+1){

end=end->next;
j=j+1;
}


begin->next=in;
in->next=end;

}



void main(){

int array[]={1,2,3,3,4,5,6,5,7},n;
n=9;

form(array,n);

numofelements();
//insertingelementinlast();
//insertingelementinbeginning();
//deletingelementatthebegining();
//deletingelementnatend();
//deletingelementatindex(4);
//insertelementafterindex(3);
searching(6);
//ifsorted();
deleteduplicate();
struct node *p;
p=first;
while(p!=0){


    printf("\n %d",p->data);
    p=p->next;


}



}







