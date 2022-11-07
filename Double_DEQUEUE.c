#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;

} *front = NULL, *rear = NULL;

void frontenqueue(int x)
{
     struct node *p;
     p = (struct node *)malloc(sizeof(struct node));
     if (p == NULL)
          printf(" Queue is FULL !");

     else
     {
          p->data = x;
          p->next = NULL;
           if (front == NULL)
          {
               front = rear = p;
          }
          rear->next = p;
          rear = p;
     }
}
void endenqueue(int x)
{
     struct node *p;
     p = (struct node *)malloc(sizeof(struct node));
     if (p == NULL)
          printf(" Queue is FULL !");

     else
     {
          p->data = x;
          p->next = NULL;
           if (front == NULL)
          {
               front = rear = p;
          }
          front->next = p;
          front = p;
     }
}

