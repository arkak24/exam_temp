// reversing the elements in a singly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
      int data;
      struct node* next_address;
}node;

node* head = NULL;
node* new_node = NULL;
node* temp = NULL;
node* follower = NULL;

int main(){
      // taking input of a linked list at first
      int choice;
      while(1){
            printf("\n1.Enter node\n");
            printf("2.Done\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            if(choice == 1){
                  int value;
                  printf("Enter the value to insert : ");
                  scanf("%d", &value);

                  temp = new_node;

                  new_node = (node*)malloc(sizeof(node));
                  new_node -> data = value;
                  new_node -> next_address = NULL;

                  if(head == NULL){
                        head = new_node;
                  }
                  if(temp != NULL){
                        temp -> next_address = new_node;
                  }
            }
            else if(choice == 2){
                  break;
            }
            else{
                  printf("Invalid input !\n");
            }
      }

      // printing the linked list before
      printf("\nThe linked list before reversing is : \n");
      temp = head;
      while(temp != NULL){
            printf("< Adderess : %p, Data in adderess : %d, Next adderess : %p >\n", temp, temp -> data, temp -> next_address);
            // if(temp -> next_address != NULL) printf(" -> ");
            temp = temp -> next_address;
      }

      // reversing the linked list
      if(head == NULL || head -> next_address == NULL){
            // no need to reverse the linked list
      }
      else if((head -> next_address) -> next_address == NULL){
            temp = head -> next_address;
            temp -> next_address = head;
            head -> next_address = NULL;
            head = temp;
      }
      else{
            follower = head;
            temp = head -> next_address;
            head -> next_address = NULL;
            while(temp -> next_address != NULL){
                  head = temp -> next_address;
                  temp -> next_address = follower;
                  follower = temp;
                  temp = head;
            }
            temp -> next_address = follower;
      }
      

      // printing the linked list after
      printf("\nThe linked list after reversing is : \n");
      temp = head;
      while(temp != NULL){
            printf("< Adderess : %p, Data in adderess : %d, Next adderess : %p >\n", temp, temp -> data, temp -> next_address);
            // if(temp -> next_address != NULL) printf(" -> ");
            temp = temp -> next_address;
      }

      // freeing the memory
      temp = head;
      while(temp != NULL){
            node* temp_memory = temp -> next_address;
            free(temp);
            temp = temp_memory;
      }
}