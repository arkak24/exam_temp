#include<stdio.h>

int binary_search(int array[], int size, int target){
      int low = 0; 
      int high = size-1;
      while(low <= high){
            int mid = (low + high)/2;
            if(array[mid] == target){
                  return mid;
            }
            else if(array[mid] < target){
                  low = mid+1;
            }
            else{
                  high = mid-1;
            }
      }
      return -1;
}

int main(){
      int number_of_elements;
      printf("Enter the number of elements in the array : ");
      scanf("%d", &number_of_elements);

      int array[number_of_elements];
      printf("Enter the elements of the array : ");
      for(int i = 0; i < number_of_elements; i++){
            scanf("%d", &array[i]);
      }

      int target;
      printf("Enter the value to search in the array : ");
      scanf("%d", &target);

      int temp = binary_search(array, number_of_elements, target);
      if(temp == -1){
            printf("Element not present in the array\n");
      }
      else{
            printf("Element present in the index %d", temp);
      }

      return 0;
}

// binary search with recursion
// int binary_search(int array[], int low, int high, int target){
//       if(low > high) return -1;
//       int mid = (low+high)/2;
//       if(array[mid] == target) return mid;
//       else if(array[mid] > target) return binary_search(array, mid+1, high, target);
//       else return binary_search(array, low, mid-1, target);
// }
