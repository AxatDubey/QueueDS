#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     // struct node *la;
     struct node *next;
     struct node *pre;
} *front = NULL, *rear = NULL;

void enqueue_from_front(int x)
{
     struct node *p;
     p = (struct node *)malloc(sizeof(struct node));
     if (p == NULL)
     {
          printf("queue is full!");
     }
     else
     {
          p->data = x;
         p->next = NULL;
          if (front == NULL)
          {
               front = rear = p;
          }
          rear->next =p;

          rear = p;
     }
}
void enqueue_from_rear(int x)
{
     struct node *p;
     p = (struct node *)malloc(sizeof(struct node));
     if (p == NULL)
     {
          printf("queue is full!");
     }
     else
     {
          p->data = x;
          p->pre = NULL;
         
          if (front == NULL)
          {
               front = rear = p;
          }
          rear->pre = p;
          rear = p;
     }
}
int dequeue_from_front()
{
     int x = -1;
     struct node *p;
     if (front)
     {
          printf("queue is empty !");
     }
     else
     {
          x = front->data;
          p = front;
          front = front->next;
          free(p);
     }
     return x;
}
int dequeue_from_rear()
{
     int x = -1;
     struct node *p;
     if (front)
     {
          printf("queue is empty !");
     }
     else
     {
          x = rear->data;
          p = rear;
          rear = rear->pre;
          free(p);
     }
     return x;
}
void Display(){
     struct node *p = rear;
    do
     {
          printf("%d\t" , p->data);
          p = p->next;
     }while(p!= NULL);
     struct node *q = front;
     while (q!= NULL)
     {
          printf("%d\t" , q->data);
          q = q->next;
     }
}int main(){
     enqueue_from_rear(21);
     enqueue_from_rear(22);
     enqueue_from_rear(23);
     enqueue_from_rear(24);
     enqueue_from_rear(25);
     enqueue_from_front(20);
     enqueue_from_front(19);
     enqueue_from_front(18);


     Display();
     return 0 ;


}
