#include<stdio.h>
#include<stdlib.h>

struct node {

int data;
struct node *lchild;
struct node *rchild;
};



struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the data for node(-1 for  no data) ");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }
    else{
        newnode->data=x;
        printf("\n enter the left element for %d",x);
        newnode->lchild=create();

        printf("\n enter the right element for %d ",x);
        newnode->rchild=create();
        }

   return newnode;
}

void preorder(struct node *r)
{struct node *t;
t=r;
if(t){
 printf("\n %d",t->data);

 preorder(t->lchild);
 preorder(t->rchild);
}
    }

    void  inorder(struct node *r)
    {
        struct node *t;
        t=r;
        if(t)
        {   inorder(t->lchild);
            printf("\n %d",t->data);
            inorder(t->rchild);

        }
    }

    void postorder(struct node *r)
    {
        struct node *t;
        t=r;
        if(t)
        {
            postorder(t->lchild);
            postorder(t->rchild);
            printf("\n %d",t->data);
        }
    }
    int num_nodes(struct node *r)
    {
     struct node *t;
     t=r;

     static int count;
     if(t!=NULL)
     {
           count++;
         num_nodes(t->lchild);
         num_nodes(t->rchild);

     }
        return count;
    }

    int num_leafs(struct node *r)
    {
        struct node *t;
        t=r;
        static int countl=0;
          if(t){
        if(t->lchild==NULL && t->rchild==NULL)
        {
           countl=countl+1;


        }
         num_leafs(t->lchild);
           num_leafs(t->rchild);
          }

   return countl;
    }

int main()
{int num_of_nodes,num_of_leafs;
struct node *root;
  root=create();
preorder(root);
num_of_nodes=num_nodes(root);

printf("\n %d",num_of_nodes);
num_of_leafs=num_leafs(root);
printf("\n %d",num_of_leafs);

return 1;


}
