// array insertion and deletion considering all the cases

#include<stdio.h>
int main(){
      int number_of_elements, choice;
      printf("Enter the number of elements in the array : ");
      scanf("%d", &number_of_elements);

      int array[number_of_elements+1];
      printf("Enter the elements of the array : ");
      for(int i=0; i<number_of_elements; i++){
            scanf("%d", &array[i]);
      }

      printf("\n1.Insert element\n");
      printf("2.Delete element\n");
      printf("Enter your choice : ");
      scanf("%d", &choice);

      if(choice == 1){
            int value, position;
            printf("Enter the value to insert : ");
            scanf("%d", &value);
            printf("Enter the position to insert : ");
            scanf("%d", &position);

            if(position > number_of_elements+1){
                  printf("Cannot perform operation");
            }
            else{
                  for(int i=number_of_elements-1; i>=position-1; i--){
                        array[i+1] = array[i];
                  }
                  array[position-1] = value;

                  for(int i=0; i<number_of_elements+1; i++){
                        printf("%d  ", array[i]);
                  }
            }
      }
      else if(choice == 2){
            int position;
            printf("Enter the position : ");
            scanf("%d", &position);

            if(position > number_of_elements){
                  printf("Cannot perform operation");
            }
            else{
                  for(int i=position; i<number_of_elements; i++){
                        array[i-1] = array[i];
                  }
                  for(int i=0; i<number_of_elements-1; i++){
                        printf("%d  ", array[i]);
                  }
            }
      }
      else{
            printf("Invalid input");
      }
      return 0;
}

