#include<stdio.h>

int main(){
      int number_of_elements;
      printf("Enter the number of elements in the array : ");
      scanf("%d", &number_of_elements);

      int array[number_of_elements];
      printf("Enter the elements of the array : ");
      for(int i = 0; i < number_of_elements; i++){
            scanf("%d", &array[i]);
      }

      int to_search;
      printf("Enter the value to search in the array : ");
      scanf("%d", &to_search);

      for(int i = 0; i < number_of_elements; i++){
            if(array[i] == to_search){
                  printf("Value present in the array at index %d\n", i);
                  // break;
            }
      }
      return 0;
}