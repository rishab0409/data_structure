#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *right;
    struct node *left;
    int height;
}*first=NULL;
 int height(struct node * t)
 {
     int x,y;

     if(t==NULL)
     return 0;
     x=height(t->left);
     y=height(t->right);
     return y>x?y+1:x+1;
 }

 int balancefac(struct node *t)
 {
     int l=height(t->left);
     int r=height(t->right);

     return l-r;
 }
 struct node *llrotation(struct node *t)
 {
     struct node *root_l,*root_lr;
     root_l=t->left;
     root_lr=root_l->right;
     t->left=root_lr;
     root_l->right=t;

     if(t==first)
    first=root_l;

    return root_l;  //always remember to return this ie the left of the node which is being rotated since the left or right of t in parameter changes from t->left=t->left to t->left=root_l 

 }
struct node *insert(struct node *t,int data)
{
    struct node *r;
    if(t==NULL)
    {
        r=(struct node *)malloc(sizeof(struct node ));
        r->right=NULL;
        r->left=NULL;
        r->data=data;
        return r;
    }
    else 
    {
         if(data==t->data)
        return NULL;

        else if(data<t->data)
        t->left =insert(t->left,data);
        else if(data>t->data)
        t->right=insert(t->right,data);
    }
       if(balancefac(t)==2 &&balancefac(t->left)==1) //see diary 
           return llrotation(t);
           if(balancefac(t)==2 && balancefac(t->left)==-1)//LR rotation condition
    return t;
}

void inorder(struct node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d\n",t->data);
        inorder(t->right);
    }
}
void preorder(struct node *t)
{
    if(t!=NULL)
    {
         printf("%d\n",t->data);

        preorder(t->left);
       
        preorder(t->right);
    }
}
void postorder(struct node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
       
        postorder(t->right);
        
         printf("%d\n",t->data);
    }
}

void main()
{
    first=insert(first,30);
    first=insert(first,20);
    first=insert(first,40);
    first=insert(first,10);
    first=insert(first,5);
    // insert(first,0);
    // insert(first,10);
    inorder(first);
    printf(" preorder \n");
    preorder(first);
    printf("\npostorder");
    postorder(first);
   // printf("the height of the tree is :%d",height(first));
}