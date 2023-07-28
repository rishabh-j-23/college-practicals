#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int low, int high) {
  
  int pivot = a[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
    int pa = partition(a, low, high);
    quickSort(a, low, pa - 1);
    quickSort(a, pa + 1, high);
  }
}

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int binarysearch(int arr[], int val, int start, int end){
    int mid;
    if(start <= end){
        mid = (start + end)/2;
    }
    if(arr[mid] == val){
        return mid;
    }
    else if(val > arr[mid]){
        return binarysearch(arr, val, mid+1, end);
    }
    else {
        return binarysearch(arr, val, start, mid-1);
    }
    return -1;
}

float run_time(clock_t start, clock_t end){
    
    float ms = (end-start);
    ms = ms/(float)CLK_TCK;

    return ms;
}

void main() {
    int n = 10000;
    int arr[n];

    clock_t start, end;

    // merge sort
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = n-i;
    }
    mergeSort(arr, 0, n-1);
    end = clock();
    printf("time (merge sort) : %fs\n", run_time(start, end));

    // quick sort
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = n-i;
    }
    quickSort(arr, 0, n-1);
    end = clock();
    printf("time (quick sort) : %fs\n", run_time(start, end));

    // binary search
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    int s = binarysearch(arr, 2, 0, n-1);
    end = clock();
    printf("time (binary search) : %fs\n", run_time(start, end));
}