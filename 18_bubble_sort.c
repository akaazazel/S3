#include <stdio.h>

int sortArray(int array[], int n){
  for(int i = 0; i<n-1; i++){
    for(int j = 0; j<n-1; j++){
      if(array[j] > array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

int main(){
  int size;

  printf("Enter the size of the array: "); 
  scanf("%d", &size);

  int array[size];

  printf("Enter the elements in the array: ");
  for(int i = 0; i<size; i++){
    scanf("%d", &array[i]);
  }

  sortArray(array, size);

  for(int i = 0; i<size; i++){
    printf("%d ", array[i]);
  }
}