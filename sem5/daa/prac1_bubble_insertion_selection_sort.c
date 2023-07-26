#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    b = temp;
}
void bubblesort(int arr[], int n){
    int temp;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[], int n){
    int min, temp;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j=i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

    // bubble
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = rand()%n;
    }
    bubblesort(arr, n);
    end = clock();
    printf("time (bubble sort) : %fs\n", run_time(start, end));

    // insertion
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = rand()%n;
    }
    insertionSort(arr, n);
    end = clock();
    printf("time (insertion sort) : %fs\n", run_time(start, end));

    // selection
    start = clock();
    for(int i = 0; i < n; i++){
        arr[i] = rand()%n;
    }
    selectionsort(arr, n);
    end = clock();
    printf("time (selection sort) : %fs\n", run_time(start, end));


}