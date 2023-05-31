#include <stdio.h>

int linear_search(int arr[], int n, int val){
    for (int i = 0; i < n; i++){
        if (val == arr[i]){
            return i;
        }
    }
    return -1;    
}

int main(){
    int n = 0;
    printf("No. of array elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Value to search in array : ");
    int val;
    scanf("%d", &val);
    
    int res = linear_search(arr, n, val);
    printf("%d at index %d", val, res);
    return 0;
}