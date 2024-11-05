#include <stdio.h>
void insertionSort(int arr[], int size){
  int temp, i, j;

  for(i=1; i<size; i++){
    temp = arr[i];
    j = i - 1;
    while(j >= 0 && temp < arr[j]){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

int main(){
  int array[] = {6,3,8,9,2,3,1,5};
  int size = sizeof(array)/sizeof(array[0]);

  insertionSort(array, size);
  for(int i = 0; i<size; i++){
    printf("%d ", array[i]);
  }
}