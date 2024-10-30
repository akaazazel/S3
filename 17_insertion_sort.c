#include <stdio.h>

int insertionSort(int arr[], int n){
  int temp, i, j;

  for(i = 1; i < n; i++){
    temp = arr[i];
    j = i - 1;
    while(j >= 0 && temp < arr[j]){
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}

int main(){
  int arr[] = {4,7,2,9,6,1,8};
  int size = (sizeof(arr)/sizeof(arr[0]));

  insertionSort(arr, size);

  for(int i = 0; i < size; i++){
    printf("%d", arr[i]);
    if(i < size - 1){
      printf(", ");
    }
  }
}