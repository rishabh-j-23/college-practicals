#include <stdio.h>

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


int main(){
    int response, n;
    printf("No. of elements in Array : ");
    scanf("%d", &n);
   
    int arr[n];
    char con;
    do{
        printf("Elements of array : ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Sort using : \n\t1.Quick Sort \n\t2.Merge Sort");
        printf("\nResponse : ");
        scanf("%d", &response);

        switch (response){
            case 1:
            quickSort(arr, 0, n-1);
                break;
            case 2:
            mergeSort(arr, 0, n-1);
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
}