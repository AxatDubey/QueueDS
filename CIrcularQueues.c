#include <stdio.h>
#include <stdlib.h>

struct queue
{
     int *Q;
     int size;
     int front;
     int rear;
};

void creat(struct queue *q, int x)
{
     q->front = q->rear = -1;
     q->size = x;
     q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
{
     if ((q->rear + 1) % q->size == q->front)
     {
          printf("queue is FULL ");
     }
     else
     {
          q->rear = (q->rear + 1) % q->size;
          q->Q[q->rear] = x;
     }
}

int dequeue(struct queue *q)
{
     int x = -1;
     if (q->front == q->rear)
     {
          printf("queue is Empty");
     }
     else
     {
          q->front = (q->front + 1) % q->size;
          x = q->Q[q->front];
     }
     return x;
}
void display(struct queue q)
{
     int i = q.front + 1;
     do
     {
          printf("%d\t", q.Q[i]);
          i = (1 + i) % q.size;

     } while (i != (q.rear + 1) % q.size);
}

int main()
{
     struct queue q;
     creat(&q, 5);

     enqueue(&q, 10);
     enqueue(&q, 20);
     enqueue(&q, 30);
     enqueue(&q, 40);
     enqueue(&q, 50);
     // enqueue(&q, 60);

     display(q);
     printf("\n%d\n", dequeue(&q));
     enqueue(&q, 60);

     display(q);
     return 0 ;
}
