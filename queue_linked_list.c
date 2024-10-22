#include<stdio.h>
#include<stdlib.h>

typedef struct node{
      int data;
      struct node* next_address;
}node;

node* head = NULL;
node* new_node = NULL;
node* temp = NULL;

void enqueue(){
      int value;
      printf("Enter the value to insert : ");
      scanf("%d", &value);

      new_node = (node*)malloc(sizeof(node));
      new_node -> data = value;
      new_node -> next_address = NULL;

      if(head == NULL){
            head = new_node;
      }
      else{
            temp = head;
            while(temp -> next_address != NULL){
                  temp = temp -> next_address;
            }
            temp -> next_address = new_node;
            printf("%d added to the queue\n", value);
      }
}

void dequeue(){
      if(head == NULL){
            printf("Queue empty\n");
      }
      else{
            node* temp_storage = head;
            head = head -> next_address;
            printf("%d dequeued from the queue\n", temp_storage -> data);
            free(temp_storage);
      }
}

void peek(){
      if(head == NULL){
            printf("Queue is empty\n");
      }
      else{
            printf("%d is the front element\n", head -> data);
      }
}

void display(){
      if(head == NULL){
            printf("Queue is empty\n");
      }
      else{
            temp = head;
            while(temp != NULL){
                  printf("%d -> ", temp -> data);
                  temp = temp -> next_address;
            }
            printf("NULL\n");
      }
}

void free_queue(){
      temp = head;
      while(temp != NULL){
            node* temp_memory = temp -> next_address;
            free(temp);
            temp = temp_memory;
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

                  case 5 : free_queue();
                  exit(0);
                  break;

                  default : printf("Invalid input\n");
            }
      }
      return 0;
}
