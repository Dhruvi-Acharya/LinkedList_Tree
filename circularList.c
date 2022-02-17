#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* last = NULL;

void insertAtFront()
{
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted: \n");
    scanf("%d", &data);
 
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
 
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
    }
}

void addatlast()
{
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted : \n");
    scanf("%d", &data);
 
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void deletefirst()
{
    struct node* temp;
    if (last == NULL)
        printf("\nList is empty.\n");
    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void deletelast()
{
    struct node* temp;
    if (last == NULL)
        printf("\nList is empty.\n");
 
    temp = last->next;
    while (temp->next != last)
        temp = temp->next;
    temp->next = last->next;
    last = temp;
}

void viewList()
{
    if (last == NULL)
        printf("\nList is empty\n");
    else {
        struct node* temp;
        temp = last->next;
       do {
            printf("\n%d ", temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}

int main()
{
  int c;
  choice: printf("\n1.Insert a node at First position\n2.Insret a node at last position\n3.Delete first node\n4.Delete last node\n5.Display Linked list\n6.Exit\n");
  printf("\nEnter your choice:\n");
  scanf("%d",&c);
  switch(c)
  {
    case 1: 
      insertAtFront();
      goto choice;
    case 2: 
      addatlast();
      goto choice;
    case 3: 
      deletefirst();
      goto choice;
    case 4: 
      deletelast();
      goto choice;
    case 5:
      viewList();
      goto choice;
    case 6:
      exit(0);
  }    
return 0;
}
