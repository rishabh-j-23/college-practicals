#include <stdio.h>
void swap(int *a, int *b){
    int *temp = a;
    a = b;
    b = temp;
}
void bubblesort(int arr[], int n){
    int temp;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // swap(&arr[j], &arr[j+1]);
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

int main()
{
    int response, n;
    printf("No. of elements in Array : ");
    scanf("%d", &n);
   
    int arr[n];
    char con;
    printf("Elements of array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    do{
        printf("Sort using : \n\t1.Bubble Sort \n\t2.Selection Sort");
        printf("\nResponse : ");
        scanf("%d", &response);
       
        switch(response){
        case 1:
        bubblesort(arr, n);
        break;
       
        case 2:
        selectionsort(arr, n);
        break;
       
        default:
        printf("\nSelect valid response");
       
        }
       
        printf("\nAfter Sorting : ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
       
        printf("\nGo back to menu? (y/n) : ");
        scanf(" %c", &con);
       
    } while(con == 'y');

    return 0;
}