#include<stdio.h>
#include<stdlib.h>

typedef struct node{
      int data;
      struct node* next_address;
}node;

node* top = NULL;
node* new_node = NULL;
node* temp = NULL;

void push();
void pop();
void peek();
void display();
void free_memory();

int main(){
      int choice;
      while(1){
            printf("\n1.Push\n");
            printf("2.Pop\n");
            printf("3.Peek\n");
            printf("4.Display\n");
            printf("5.Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch(choice){
                  case 1 : push();
                  break;

                  case 2 : pop();
                  break;

                  case 3 : peek();
                  break;

                  case 4 : display();
                  break;

                  case 5 : free_memory();
                  exit(0);
                  
                  default : printf("Invalid input !\n");
            }
      }
      system("pause");
      return 0;
}

void push(){
      int value;
      printf("Enter the value to insert : ");
      scanf("%d", &value);

      new_node = (node*)malloc(sizeof(node));
      new_node -> data = value;
      new_node -> next_address = top;
      
      top = new_node;
}

void pop(){
      if(top == NULL){
            printf("The stack is empty\n");
      }
      else{
            node* temp_memory = top;
            top = top -> next_address;
            printf("%d is popped from the stack\n", temp_memory -> data);
            free(temp_memory);
      }
}

void peek(){
      if(top == NULL){
            printf("The stack is empty\n");
      }
      else{
            printf("%d is the top element\n", top -> data);
      }
}

void display(){
      if(top == NULL){
            printf("The stack is empty\n");
      }
      else{
            temp = top;
            while(temp != NULL){
                  printf("%d -> ", temp -> data);
                  temp = temp -> next_address;
            }
            printf("NULL\n");
      }
}

void free_memory(){
      temp = top;
      while(temp != NULL){
            node* temp_mem = temp -> next_address;
            free(temp);
            temp = temp_mem;
      }
}
