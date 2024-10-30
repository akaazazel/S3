#include <stdio.h>

int merge(int arr[], int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++){
    leftArray[i] = arr[left + i];
  }
  
  for(int i = 0; i < n1; i++){
    rightArray[i] = arr[mid + i + 1];
  }

  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2){
    if(leftArray[i] < rightArray[j]){
      arr[k] = leftArray[i];
      i++;
    }else if(leftArray[i] > rightArray[j]){
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    arr[k] = leftArray[i];
    i++; k++;
  }
  while(j < n2){
    arr[k] = rightArray[j];
    j++; k++;
  }
}

int mergeSort(int arr[], int left, int right){
  if(left < right){
    int mid = (left + (right - left) / 2);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main(){
  int arr[] = {4,7,2,9,6,1,8};
  int size = (sizeof(arr)/sizeof(arr[0]));

  mergeSort(arr, 0, size-1);

  for(int i = 0; i < size; i++){
    printf("%d", arr[i]);
    if(i < size - 1){
      printf(", ");
    }
  }
}