#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;

} *front = NULL, *rear = NULL;

void enqueue(int x)
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
int dequeue()
{
     int x = -1;
     struct node *p;
     if (front == NULL)
          printf("queue is empty\n");
     else
     {
          x = front->data;
          p = front;
          front = front->next;
          free(p);
     }
     return x;
}
void display(){
     struct node *p = front;
     while (p!= NULL)
     {
          printf("%d\t" , p->data);
          p=p->next;
     }
     
}
int main ( ){
     enqueue(10);
     enqueue(30);
     enqueue(50);

     display();

     printf("%d" ,dequeue());

     return 0 ;
}