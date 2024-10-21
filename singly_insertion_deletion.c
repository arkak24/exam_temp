// insertion and deletion in singly linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
      int data;
      struct node* next_address;
}node;

node* head = NULL;
node* new_node = NULL;
node* temp = NULL;

int count_nodes();
void insert_node();
void delete_node();
void the_loop_thing();
void print_list();
void free_list();

int main(){

      // at first taking a linked list in which the operation will be done
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
      print_list();

      the_loop_thing();

      return 0;
}

void the_loop_thing(){
      int insertion_deletion_choice;
      while(1){
            printf("\n1.Insert a new node\n");
            printf("2.Delete a node\n");
            printf("3.Print list\n");
            printf("4.Done\n");
            printf("Enter you choice : ");
            scanf("%d", &insertion_deletion_choice);

            switch(insertion_deletion_choice){
                  case 1 : insert_node();
                  break;

                  case 2 : delete_node();
                  break;

                  case 3 : print_list();
                  break;

                  case 4 : free_list();
                  exit(0);
                  break;

                  default : printf("Invalid choice !\n");
            }
      }
}

int count_nodes(){
      int count = 0;
      temp = head;
      while(temp != NULL){
            count++;
            temp = temp -> next_address;
      }
      return count;
}

void insert_node(){
      int position, add_data;
      int count = count_nodes();
      printf("Enter the position to insert : ");
      scanf("%d", &position);

      if(position > count+1){
            printf("The position should be less than or equal to %d\n", count+1);
            the_loop_thing();
      }
      printf("Enter the value to insert : ");
      scanf("%d", &add_data);

      node* new_insert = (node*)malloc(sizeof(node));
      new_insert -> data = add_data;

      if(position == 1){      
            new_insert -> next_address = head;
            head = new_insert;
      }
      else{
            temp = head;
            for(int i = 1; i <= position-2; i++){     // run the loop 2 times less than the position number
                  temp = temp -> next_address;
            }
            new_insert -> next_address = temp -> next_address;
            temp -> next_address = new_insert;
      }
}

void delete_node(){
      node* abc = NULL;
      node* xyz = (node*)malloc(sizeof(node));
      int count = count_nodes();
      int position;
      printf("Enter the node position to delete : ");
      scanf("%d", &position);

      if(count == 1 && position == 1){
            head = NULL;
      }
      else if(count == 0 && position == 1){
            printf("No element in the list\n");
      }
      else{
            if(position > count){
                  printf("The position should be less than or equal to %d\n", count);
                  the_loop_thing();
            }
            else if(position == count){
                  temp = head;
                  while((temp -> next_address) -> next_address != NULL){
                        temp = temp -> next_address;
                  }
                  temp -> next_address = NULL;
            }
            else if(position == 1){
                  abc = head;
                  head = head -> next_address;
                  free(abc);
            }
            else{
                  temp = head;
                  for(int i = 1; i < position-1; i++){   // run the loop 2 times less than the position number
                        temp = temp -> next_address;
                  }
                  xyz = temp -> next_address;
                  temp -> next_address = (temp -> next_address) -> next_address;
                  free(xyz);
            }
      }
}

void print_list(){
      temp = head;
      while(temp != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> next_address;
      }
      printf("NULL\n");
}

void free_list(){
      temp = head;
      while(temp != NULL){
            node* temp_memory = temp -> next_address;
            free(temp);
            temp = temp_memory;
      }
}
