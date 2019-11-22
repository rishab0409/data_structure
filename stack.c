#include <stdio.h>
#include<stdlib.h>
struct stack{

int size;
int top;
int* p;
};

void create(struct stack* st)
{
    st->top=-1;
    printf("enter the size of  stack :");
    scanf("%d",&st->size);
    st->p=(int*)malloc(st->size*sizeof(int));


}

void push(struct stack *st,int  x){

if(st->top==st->size)
    printf("stack overflow");

    else{

     st->top++;
     st->p[st->top]=x;

    }

}

int pop(struct stack* st){
int x;
if(st->top==-1)
    printf("stack under flow");

    else{

        x=st->p[st->top];
        st->top--;
        }

return x;

}


void display(struct stack* st){
int i;
for(i=st->top;i>=0;i--)
    printf("\n first element: %d",st->p[i]);
}
void topofstack(struct stack *st){

if(st->top==-1)
    printf("stack underflow");
else{

    printf("\n the peek element is :%d",st->p[st->top]);

}

}

void peek(struct stack* st,int pos){
int  index=(st->top)+1-pos;
if(index==-1)
printf("stack underflow");
else{

    printf("\n the element is :%d",st->p[index]);
}

}
void main(){
struct stack st;
create(&st);


 push(&st,10);
 push(&st,20);
 push(&st,30);
 push(&st,40);


 display(&st);
peek(&st,3);
 printf("\n after  popping \n");
pop(&st);
pop(&st);
display(&st);
topofstack(&st);
}
