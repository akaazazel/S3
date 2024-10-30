#include <stdio.h>

void selectionSort(int arr[], int n){
  for(int i = 0; i < n - 1; i++){
    int min_index = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[min_index]){
        min_index = j;
      }
    }
    if(min_index != i){
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }
  }
}

int main(){
  int arr[] = {4,7,2,9,6,1,8};
  int size = (sizeof(arr)/sizeof(arr[0]));

  selectionSort(arr, size);

  for(int i = 0; i < size; i++){
    printf("%d", arr[i]);
    if(i < size - 1){
      printf(", ");
    }
  }
}