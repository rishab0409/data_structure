#include<stdio.h>
#include<stdlib.h>


struct queue{
int size;
int top;
int rear;
int *p
};

void create(struct queue* q){
q->top=-1;
q->rear=-1;
q->p=(int *)malloc(sizeof(int)*q->size);


}

void inqueue(struct queue* q,int x )
{
if(q->rear==q->size-1)
        printf("stack is full");
else{

    q->rear++;
    q->p[q->rear]=x;

}


}
int dequeue(struct queue* q)
{

    if(q->top==q->rear)
        printf("the stack is empty");
    else
    {
        q->top++;
        return q->p[q->top];
    }

}
void printqueue(struct queue* q)
{
    int i=0;
    while(i<q->size){
    printf("\nthe elements in queue are: %d",q->p[i]);
    i++;
    }
}
void main(){
struct queue q;
printf("enter the size of the queue");
scanf("%d",&q.size);
create(&q);

inqueue(&q,10);
inqueue(&q,20);
inqueue(&q,30);
inqueue(&q,40);
inqueue(&q,50);
inqueue(&q,60);

printqueue(&q);

int y=dequeue(&q);


printf("\n the deleted element is :%d",y);
int z=dequeue(&q);

printf("\n the deleted element is :%d",z);





}
