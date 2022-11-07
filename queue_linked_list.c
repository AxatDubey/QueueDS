#include<stdio.h>
#include<stdlib.h>
struct Node {
     int data;
     struct Node* next;
};

struct Node* rear = NULL;
struct Node* front = NULL;

void enqueue_rear(int data) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
     newNode->data = data;
     newNode->next = NULL;
     if(rear == NULL) {
          front = rear = newNode;
     }
     else {
          rear->next = newNode;
          rear = newNode;
     }
}
void enqueue_front(int data) {
     struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
     newNode->data = data;
     newNode->next = NULL;
     if(front == NULL && rear == NULL) {
          rear = front = newNode;
     }
     else {
          struct Node* t;
          t = front;
          front = newNode;
          newNode->next = t;
     }
}


void display() {
     struct Node* temp = front;
     while(temp != NULL) {
          printf("%d ",temp->data);
          temp = temp->next;
     }
}
int main() {
     printf("Adding at rear");
     enqueue_rear(10);
     enqueue_rear(20);
     enqueue_rear(30);
     display();
     printf("\nAdding at front");
     enqueue_front(40);
     enqueue_front(50);
     enqueue_front(60);
     display();
     
    
     return 0;
}