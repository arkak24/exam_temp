// creating a linked list 

#include<stdio.h>
#include<stdlib.h>

int main(){

    typedef struct node{
        int data;
        struct node* next;
    }node;

    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    int choice;

    while(1){

        printf("\n1.Enter a node\n");
        printf("2.Done\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice == 1){
            int value;
            printf("Enter the value for the node : ");
            scanf("%d", &value);

            temp = (node*)malloc(sizeof(node));
            temp -> data = value;
            temp -> next = NULL;

            if(head == NULL){
                head = temp;
            }
            else{
                p = head;
                while(p -> next != NULL){
                    p = p -> next;
                }
                p -> next = temp;
            }
        }

        // the linked list can be created without using the while loop
        
        // if(choice == 1){
        //     int value;
        //     printf("Enter the value for the node : ");
        //     scanf("%d", &value);

        //     p = temp;

        //     temp = (node*)malloc(sizeof(node));
        //     temp -> data = value;
        //     temp -> next = NULL;

        //     if(head == NULL){
        //         head = temp;
        //     }
        //     if(p != NULL){
        //         p -> next = temp;
        //     }
        // }

        else if(choice == 2){
            break;
        }

        else{
            printf("Invalid choice!!!\n");
        }

    }

    printf("\nThe linked list is : ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");

    temp = head;
    while (temp != NULL) {
        node* tempNext = temp->next;
        free(temp);
        temp = tempNext;
    }
    head = NULL;  

    return 0;
}

// -------------------------------------------------------------------