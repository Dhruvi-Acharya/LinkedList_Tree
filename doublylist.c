#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};

void display(struct node *first)
{
  struct node *p;
  p=first;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->rlink;
  }
}

struct node* insertfirst(struct node *l,struct node *r,struct node *bn,int d)
{
  struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  if(r==NULL)
  {
    new->llink=NULL;
    new->rlink=NULL;
    l=r=new;
    return l;
  }
  else if(bn==l)
  {
      new->llink=NULL;
      new->rlink=bn;
      bn->llink=new;
      l=new;
      return l;
  }
  else
  {
    new->llink=bn->llink;
    new->rlink=bn;
    bn->llink=new;
    (new->llink)->rlink=new;
    return l;
  }
}

struct node* delete(struct node *l,struct node *r,struct node *d)
{
  if(r==NULL)
  {
    printf("underflow\n");
    return 0;
  }
  else if(l==r)
  {
    l=r=NULL;
    return 0;
  }
  else if(d==l)
  {
    l=l->rlink;
    l->llink=NULL;
    return l;
  }
  else if(d==r)
  {
    r=r->llink;
    r->rlink=NULL;
    return l;
  }
  else
  {
     d->llink->rlink=d->rlink;
     d->rlink->llink=d->llink;
     return l;
  }
  free(d);
}

void main()
{
  struct node *first,*second,*l,*r;
  first=(struct node *)malloc(sizeof(struct node));
  second=(struct node *)malloc(sizeof(struct node));
  first->data=10;
  first->llink=NULL;
  first->rlink=second;
  second->data=20;
  second->llink=first;
  second->rlink=NULL;
 
  l=first;
  r=second;

  display(first);
  l=insertfirst(l,r,first,30);
  printf("\nafter insertion at first\n");
  display(l);
  l=delete(l,r,first);
  printf("\nafter delete 10\n");
  display(l);
}
