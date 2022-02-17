#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *lptr;
    struct node *rptr;
};

void display(struct node *first)
{
  if(first==NULL)
  {
    printf("\nEmpty tree\n");
    //return 0;
  }
  else
  {
    printf("%c ",first->data);
  if(first->lptr!=NULL)
    display(first->lptr);
  if(first->rptr!=NULL)
    display(first->rptr);
  }
}

void displayIn(struct node *first)
{
  if(first==NULL)
  {
    printf("\nEmpty tree\n");
    //return 0;
  }
  else
  {
  if(first->lptr!=NULL)
    displayIn(first->lptr);
  printf("%c ",first->data);
  if(first->rptr!=NULL)
    displayIn(first->rptr);
  }
}

void displayPost(struct node *first)
{
  if(first==NULL)
  {
    printf("\nEmpty tree\n");
    //return 0;
  }
  else
  {
  if(first->lptr!=NULL)
    displayPost(first->lptr);
  if(first->rptr!=NULL)
    displayPost(first->rptr);
  printf("%c ",first->data);
  }
}

void main()
{
    int c;
    struct node *first,*bnode,*cnode,*dnode,*enode,*fnode,*gnode;
    first=(struct node *)malloc(sizeof(struct node));
    bnode=(struct node *)malloc(sizeof(struct node));
    cnode=(struct node *)malloc(sizeof(struct node));
    dnode=(struct node *)malloc(sizeof(struct node));
    enode=(struct node *)malloc(sizeof(struct node));
    fnode=(struct node *)malloc(sizeof(struct node));
    gnode=(struct node *)malloc(sizeof(struct node));
    
    first->data='A';
    bnode->data='B';
    cnode->data='C';
    dnode->data='D';
    enode->data='E';
    fnode->data='F';
    gnode->data='G';

    first->lptr=bnode;
    first->rptr=dnode;
    bnode->lptr=cnode;
    bnode->rptr=NULL;
    cnode->lptr=NULL;
    cnode->rptr=NULL;
    dnode->lptr=enode;
    dnode->rptr=gnode;
    enode->lptr=NULL;
    enode->rptr=fnode;
    fnode->lptr=NULL;
    fnode->rptr=NULL;
    gnode->lptr=NULL;
    gnode->rptr=NULL;

    printf("\nPre order ");
    display(first);
    printf("\nIn order ");
    displayIn(first);
    printf("\nPost order ");
    displayPost(first);
}
