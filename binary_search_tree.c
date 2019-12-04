#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
}*root=NULL,*r;


void insert_r(struct node *t,int key)//r is a tail pointer which follows the t pointer since after the last iteration the t pointer is zero
{
struct node *p;
while(t!=NULL)
{    r=t;
    if(t->data==key)
    {
        return;
       
    }
    else if(key<t->data)
    {
        t=t->left;
    }
    else
    {
        t=t->right;
    }
}
p=(struct node *)malloc(sizeof(struct node));
p->data=key;
p->left=NULL;
p->right=NULL;
if(key<r->data)
r->left=p;
else
{
    r->right=p;
}

}


struct node *insert( struct node *t,int key) 
{
    struct node *p;
  if(t==NULL)
  {
      p=(struct node *)malloc(sizeof(struct node));
      p->data=key;
      p->left=NULL;
      p->right=NULL;
      return p;
  }    
  
   if(key<t->data)
  {
      t->left=insert(t->left,key);
  }
  else if(key>t->data){
      t->right=insert(t->right,key);
  }
  return t;  // important:see this line their are two return statement one for the last function call when a new node is created and one return when node is not created so after first function call if the node is not created then t->left=t->left;
}

struct node *search (struct node *t,int key)
{
 
 
 if(t->data==key)
 return t;
 else if(key <t->data)
 return search(t->left,key);// remember to return the recurive function when called. Since the inside recursive function returns the nodes but to get the final ans return is required or all the other returns would go to compiler which will be of no use. 
 else if(key>t->data)
 return search(t->right,key);
 else
 {
     return NULL;
 }
    
}
struct node *inpre(struct node *t)//se diary
{ while(t && t->right!=NULL)
t=t->right;
return t;

}
struct node *insuc(struct node *t)//se diary
{ while(t && t->left!=NULL)
t=t->left;
return t;

}


int Height(struct node *t)//returns height of tree +1
{
    int x,y;
     if(t==NULL)
     return 0;
     
     x=Height(t->left);
     y=Height(t->right);
     return y>x?y+1:x+1; 
    }

struct node *delete(struct node *t,int key)
{
    struct node *q;

    if(t==NULL)
    return NULL;
    if(t->left==NULL && t->right==NULL)
    {    if(t==root)
    root=NULL;
        free(t);
        return NULL;
    }

    if(key < t->data)
    {
        t->left=delete(t->left,key);

    }   
    else if(key > t->data)
    {
        t->right=delete(t->right,key);
    } 

    else
    {
        if(Height(t->left)>Height(t->right))
        {
            q=inpre(t->left);
            t->data=q->data;
            t->left=delete(t->left,q->data);

        }
        else if(Height(t->right)>Height(t->left))
        {
            q=insuc(t->right);
            t->data=q->data;
            t->right=delete(t->right,q->data);
        }
    }
    return t;
}
void inorder(struct node *st)//  Inorder of a binary search tree is sorted
{
if(st)
{
inorder(st->left);
printf("\n%d",st->data);
inorder(st->right);

}
}

void create(struct node *t,int *array,int size)
{
    int i;
   // struct node *p;
   /* if(t==NULL)
    {
         p=(struct node *)malloc(sizeof(struct node));
         p->data=array[0];
         p->left=NULL;
         p->right=NULL;
         t=p; 
    }*/
    for(i=0;i<size;i++)
    {
      if(search(t,array[i])==NULL)
      {
        insert_r(t,array[i]);

      }
      else
      {
          printf("element already exists");
      }
      
    }


}

void main()
{
    


root=insert(root,25);
insert(root,30);
insert(root,35);
insert(root,60);
delete(root,35);
int array[10]={1,2,3,4,5,6,7,8,9,10};
//create(root,array,10); not working



inorder(root);
printf("\n");

}