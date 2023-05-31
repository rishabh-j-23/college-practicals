#include <stdio.h>
int binarysearch(int arr[], int val, int start, int end){
    int mid;
    if(start <= end){
        mid = (start + end)/2;
    }
    if(arr[mid] == val){
        return mid+1;
    }
    else if(val > arr[mid]){
        return binarysearch(arr, val, mid+1, end);
    }
    else {
        return binarysearch(arr, val, start, mid-1);
    }
    return -1;
}

int main(){
    int n = 0;
    printf("No. of array elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array elements in ascending order : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Value to search in array : ");
    int val;
    scanf("%d", &val);
    
    int res = binarysearch(arr, val, 0, n-1);
    printf("%d at pos %d", val, res);
    return 0;
}