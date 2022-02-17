#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

struct node *insertFirst(struct node *first,int d)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data=d;
  if(first==NULL)
  {
    first=n;
    first->link=NULL;
  }
  else
  {
    n->link=first;
    first=n;
  }
  return first;
}

struct node *insertend(struct node *first,int d)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  struct node *p = (struct node *)malloc(sizeof(struct node));
  n->data=d;
  if(first==NULL)
  {
    first=n;
    first->link=NULL;
  }
  else
  {
    p=first;
    while(p->link!=NULL)
	p=p->link;
    p->link=n;
    n->link=NULL;
  }
  return first;
}

struct node *deletenode(struct node *first,int d)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  struct node *p = (struct node *)malloc(sizeof(struct node));
  //n->data=d;
  p=first;
  if(first==NULL)
  {
    printf("empty list\n");
    return 0;
  }
  else if (p != NULL && p->data == d) {
        first = p->link; 
        free(p); 
        return first;
    }
  else
  {
    p=first;
    while(p!=NULL && p->data != d)
    {
	n=p; 
	p=p->link;
    }

    n->link = p->link;
    free(p);
    return first;
  }
}

struct node *insertorder(struct node *first,int d)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  struct node *p = (struct node *)malloc(sizeof(struct node));
  n->data=d;
    if(n->data <= first->data)
    {
      n->link=first;
      return n;
    }
    else
    {
      p=first;
      while(n->data >= p->link->data && p->link!=NULL)
	p=p->link;
      
    }
      n->link=p->link;
      p->link=n;
      return first;
}

struct node *copylist(struct node *first)
{
  if(first==NULL)
    printf("Empty list");
  else
  {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n=first;
    while(n->link !=NULL)
    {
      p->data=n->data;
      p->link=n->link;
      n=n->link;
    }
    printf("copied\n");
    return p;
  }
}

void display(struct node *first)
{
  if(first==NULL)
    printf("Empty list");
  else
  {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p=first;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->link;
    }
  }
}

void main()
{
  int c,d;
  struct node *first,*second;
  first=NULL;
  second=NULL;
  choice: printf("\n1.Insert a node at First position\n2.Insret a node at last position\n3.Insert a node in Ordered list\n4.Delete a node\n5.Copy linked list\n6.Display Linked list\n7.Exit\n");
  printf("\nEnter your choice:\n");
  scanf("%d",&c);
  switch(c)
  {
    case 1: 
      printf("Enter Data: ");
      scanf("%d",&d);
      first = insertFirst(first,d);
      goto choice;
    case 2: 
      printf("Enter Data: ");
      scanf("%d",&d);
      first = insertend(first,d);
      goto choice;
    case 3: 
      printf("Enter Data: ");
      scanf("%d",&d);
      first = insertorder(first,d);
      goto choice;
    case 4: 
      printf("Enter value you want to delete: ");
      scanf("%d",&d);
      first = deletenode(first,d);
      goto choice;
    case 5: 
      second = copylist(first);
      display(second);
      goto choice;
    case 6:
      display(first);
      goto choice;
    case 7:
      exit(0);
  }
}
