#include<stdio.h>

int main(){
	int size, temp;
	printf("Enter the size of the array : ");
	scanf("%d", &size);

	int arr[size];
	printf("Enter the elements of the array : ");
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	//array before sorting
	for(int i=0; i<size; i++){
		printf("%d	", arr[i]);
	}
	printf("\n");

	//sorting array
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-1-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	//array after sorting
	for(int i=0; i<size; i++){
		printf("%d	", arr[i]);
	}
	return 0;
}
