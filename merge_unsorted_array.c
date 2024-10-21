// merging two unsorted array

#include<stdio.h>

int main(){
      int n1,n2;
      printf("Enter the number of elements of the first and the second array : ");
      scanf("%d %d", &n1, &n2);

      int arr1[n1], arr2[n2];
      printf("Enter the number of elements of the first array : ");
      for(int i=0; i<n1; i++) scanf("%d", &arr1[i]);
      printf("Enter the number of elements of the second array : ");
      for(int i=0; i<n2; i++) scanf("%d", &arr2[i]);

      int arr3[n1+n2];
      for(int i=0; i<n1; i++) {arr3[i] = arr1[i];}
      for(int i=n1; i<n1+n2; i++) {arr3[i] = arr2[i-n1];}
      for(int i=0; i<n1+n2; i++) printf("%d     ", arr3[i]);
      return 0;
}