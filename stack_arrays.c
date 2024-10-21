#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top = -1;

void push();
void pop();
void peek();
void display();

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

                  case 5 : exit(0);
                  
                  default : printf("Invalid input !\n");
            }
      }
      system("pause");
      return 0;
}

void push(){
      int value;     
      if(top == max-1){
            printf("Stack is already full\n");
      }
      else{
            printf("Enter the value to insert into the stack : ");
            scanf("%d", &value);
            top++;
            stack[top] = value;
      }
}

void pop(){
      if(top == -1){
            printf("There is no elements in the stack\n");
      }
      else{
            int temp = stack[top];
            top--;
            printf("%d is popped form the stack\n", temp);
      }
}

void peek(){
      if(top == -1){
            printf("There is no elements in the stack\n");
      }
      else{
            printf("The top element in the stack is %d\n", stack[top]);
      }
}

void display(){   
      if(top == -1){
            printf("There is no elements in the stack\n");
      }
      else{
            for(int i = 0; i <= top; i++){
                  printf("%d  ", stack[i]);
            }
            printf("\n");
      }
}
