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

int binarySearch(int array[], int size, int key){
  int low = 0;
  int high = size-1;
  int mid; 

  while(low < high){
    
    mid = (low + high)/2;
    int mid_element = array[mid];

    if(mid_element == key){
      break;

    }else if(mid_element < key){
      low = mid + 1;

    }else if(mid_element > key){
      high = mid - 1;

    }else{
      return -1;
    }
  }

  return mid;
}

int main(){
  int size, search_key;

  printf("Enter the size of the array: "); 
  scanf("%d", &size);

  int array[size];

  printf("Enter the elements in the array: ");
  for(int i = 0; i<size; i++){
    scanf("%d", &array[i]);
  }

  sortArray(array, size);

  printf("Enter the key to search: ");
  scanf("%d", &search_key);

  int index = binarySearch(array, size, search_key);

  if(index){
    printf("Element found at index %d.", index);
  }else{
    printf("Element not found.");
  }
}