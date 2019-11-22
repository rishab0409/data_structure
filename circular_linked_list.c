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
void delete1(int a){
 struct node *p5;
 p5=first;
 int i=1;

 if(a==1){
while( i<6){
    p5=p5->next;
    i++;

}
p5->next=first->next;
first=first->next;

 }
}

void count(){
    struct node *p5;
    int count =1;
    p5 =first;
    while(p5->next!=first){
        count=count+1;
        p5=p5->next;
    }
    printf("%d",count);
    printf("\n");
}

void main(){

create();
count();
delete1(1);
struct node *p3;
p3=first;
while(p3->next !=first){

    printf("%d",p3->data);
    p3=p3->next;


}
printf("%d",p3->data);




}

