#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue(){
      if(front == (rear+1)%max){
            printf("Queue is full\n");
      }
      else{
            int n;
            printf("Enter the value to insert : ");
            scanf("%d", &n);

            if(front == -1 && rear == -1){
                  front = rear = 0;
                  queue[rear] = n;
            }
            else{
                  rear = (rear+1)%max;
                  queue[rear] = n;
            }
      }
}

void dequeue(){
      if(front == -1 && rear == -1){
            printf("Queue is empty\n");
      }
      else if(front == rear){
            printf("%d is dequeued from the queue\n", queue[front]);
            front = rear = -1;
      }
      else{
            printf("%d is dequeued from the queue\n", queue[front]);
            front = (front+1)%max;
      }
}

void peek(){
      if(front == -1){
            printf("Queue is empty\n");
      }
      else{
            printf("%d is the front element\n", queue[front]);
      }
}

void display(){
      if(front == -1){
            printf("Queue is empty\n");
      }
      else{
            if(front == rear){
                  printf("%d", queue[front]);
            }
            else if(front > rear){
                  // front to end, 0 to rear
                  for(int i = front; i < max; i++) printf("%d  ", queue[i]);
                  for(int j = 0; j <= rear; j++) printf("%d  ", queue[j]);
            }
            else{
                  // front to rear
                  for(int i = front; i <= rear; i++) printf("%d   ", queue[i]);
            }
            printf("\n");
      }  
}

int main(){
      int choice;
      while(1){
            printf("\n1.Enqueue\n");
            printf("2.Dequeue\n");
            printf("3.Peek\n");
            printf("4.Display\n");
            printf("5.Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch(choice){
                  case 1 : enqueue();
                  break;

                  case 2 : dequeue();
                  break;

                  case 3 : peek();
                  break;

                  case 4 : display();
                  break;

                  case 5 : exit(0);
                  break;

                  default : printf("Invalid input\n");
            }
      }
      return 0;
}