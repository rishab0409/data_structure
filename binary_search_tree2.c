#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
}*first=NULL;

struct node *insert(struct node *t,int data)
{
    struct node *p;
    
    if(t==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=data;
        p->right=NULL;
        p->left=NULL;
        return p;
    }
    else
    {
        if(data==t->data)
        return NULL;
        else if(data < t->data)
        
         t->left=insert(t->left,data); 
        
        else if(data> t->data)
        t->right=insert(t->right,data);
    }
   return t;
}
void insert_i(struct node *t,int data)
{ struct node *r,*p;
  while(t!=NULL)
  {
     
          r=t; 
       if(t->data==data)
         return ;
      
      else if(data<t->data)
        t=t->left;
      else if(data >t->data)
        t=t->right;
     
      



  }
  if(data<r->data)
       {
            p=(struct node *)malloc(sizeof(struct node));
            p->data=data;
            p->right=NULL;
            p->left=NULL;
            r->left=p;
       }
       if(data>r->data)
       {
            p=(struct node *)malloc(sizeof(struct node));
            p->data=data;
            p->right=NULL;
            p->left=NULL;
            r->right=p;
  
}}

void inorder(struct node *t)
{
 
 if(t!=NULL){
 inorder(t->left);
 printf("\n%d",t->data);
 inorder(t->right);
 }
}

int height(struct node *t)
{
        int x,y;
        if(t==NULL)
        return 0;

        x=height(t->left);
        y=height(t->right);
        return x>y?x+1:y+1;
}

struct node *inpre(struct node *t)
{
     while(t &&t->right !=NULL)
     t=t->right;
     return t;
}

struct node *insuc(struct node *t)
{
    while(t && t->left !=NULL)
    t=t->left;
    return t;
}

void delete(struct node *t,int key)
{
    struct node *r;
    if(t->left ==NULL && t->right==NULL)
    {
       if(t==first)
         first==NULL;
         free(t);
         return NULL; 
    }

    else 
    {
      if(key<t->data)
      delete(t->left,key);
      else if(key>t->data)
      delete(t->right,key);

      else 
      {
         if(height(t->left)>height(t->right))
          {
            r=inpre(t->left);
            t->data=r->data;
             delete(t->left,r->data);
          }
          else if(height(t->right)>height(t->left))
          {
              r=insuc(t->right);
              t->data=r->data;
              delete(t->right,r->data);
          }
          
      }
    }

}

int main()
{
     first=insert(first,1);
     first=insert(first,2);
     first=insert(first,3);
     first=insert(first,4);
     first=insert(first,5);
     first=insert(first,6);
     insert_i(first,7);

     delete(first,3);
     
   printf("height of tree is :%d",height(first));
     inorder(first);
}