#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int d)
{
  struct node *n=(struct node *)malloc(sizeof(struct node));
  n->data=d;
  n->left=NULL;
  n->right=NULL;
  return n;
}

struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->data)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void display(struct node *first)
{
  if(first==NULL)
  {
    printf("\nEmpty tree\n");
    //return 0;
  }
  else
  {
  if(first->left!=NULL)
    display(first->left);
  printf("%d ",first->data);
  if(first->right!=NULL)
    display(first->right);
  }
}

void main()
{
  struct node *root = NULL;
  int d,i=0,j;
  printf("how many element you want to insert: ");
  scanf("%d",&j);
  while(i<j)
  {
    printf("enter element: ");
    scanf("%d",&d);
    root = insert(root, d);
    i++;
  }
  //root = insert(root, 8);
  //root = insert(root, 3);
  //root = insert(root, 1);
  display(root);
}
