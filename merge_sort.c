#include<stdio.h>

void merge(int array[], int low, int mid, int high){
      int temp[high-low+1];
      int left = low;
      int right = mid+1;
      int i = 0;
      while(left <= mid && right <= high){
            if(array[left] <= array[right]){
                  temp[i] = array[left];
                  left++;
            }
            else{
                  temp[i] = array[right];
                  right++;
            }
            i++;
      }
      while(left <= mid){
            temp[i] = array[left];
            i++;
            left++;
      }
      while(right <= high){
            temp[i] = array[right];
            i++;
            right++;
      }
      // put the elements of the temp array into the original array
      for(int i = 0; i < high-low+1; i++){
            array[low+i] = temp[i];
      }
}

void merge_sort(int array[], int low, int high){
      if(low >= high) return;
      int mid = (low + high)/2;
      merge_sort(array, low, mid);
      merge_sort(array, mid+1, high);
      merge(array, low, mid, high);
}

int main(){
      int number_of_elements;
      printf("Enter the number of elements : ");
      scanf("%d", &number_of_elements);

      int array[number_of_elements];
      printf("Enter the elements of the array : ");
      for(int i = 0; i < number_of_elements; i++){
            scanf("%d", &array[i]);
      }
      merge_sort(array, 0, number_of_elements-1);

      // printing the sorted array
      for(int i = 0; i < number_of_elements; i++){
            printf("%d  ", array[i]);
      }
      return 0;
}