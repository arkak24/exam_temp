#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue(){
      if(rear == max-1){
            printf("Queue is already full\n");
      }
      else{
            int n;
            printf("Enter the value to enqueue : ");
            scanf("%d", &n);

            if(front == -1 && rear == -1){
                  front = rear = 0;
                  queue[rear] = n;
            }
            else{
                  rear++;
                  queue[rear] = n;
            }
      }
}

void dequeue(){
      if(front == -1 && rear == -1){
            printf("Queue is already empty\n");
      }
      else if(front == rear){
            printf("The dequeued value is %d\n", queue[front]);
            front = rear = -1;
      }
      else{
            printf("The dequeued value is %d\n", queue[front]);
            front++;
      }
}

void peek(){
      if(front == -1 && rear == -1){
            printf("Queue is empty\n");
      }
      else{
            printf("%d is the front element\n", queue[front]);
      }
}

void display(){
      if(front == -1 && rear == -1){
            printf("Queue is empty\n");
      }
      else{
            printf("The queue is : ");
            for(int i = front; i <= rear; i++){
                  printf("%d  ", queue[i]);
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
}
