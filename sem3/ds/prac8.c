#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int arr[], int size, int ele){
    if(top == size-1){
        printf("Stack Overflow\n");
    } else {
        top = top+1;
        arr[top] = ele;
    }
}

void pop(){
    if(top < 0){
        printf("\nStack Underflow\n");
    } else {
        top = top - 1;
    }
}

void printStack(int arr[], int size){
    printf("[ ");
    for (int i = 0; i <= top; i++){
        printf("%d ", arr[i]);
    }
    printf("]");
}

int main(){
    int menu = 1, n = 0;
    printf("Size of stack : ");
    scanf("%d", &n);
    int arr[n];

    while(menu){
        printf("\n1. Push into stack\n");
        printf("2. Pop from stack\n");
        printf("3. Print stack\n");

        int response;
        printf("Response : ");
        scanf("%d", &response);
        switch(response){
            case 1:
                int pushRes= 1;
                while(pushRes){
                    int ele;
                    printf("\nElement to push : ");
                    scanf("%d", &ele);
                    push(arr, n, ele);

                    printf("%d ", top);
                    printf("Continue pushing? (0/1) : ");
                    scanf("%d", &pushRes);
                }
                break;

            case 2: 
                pop();
                printf("\nTop element popped");
                break;
            
            case 3:
                printStack(arr, n);
                break;

            default: 
                printf("\nenter valid response.");
                break;
        }

        fflush(stdin);
        printf("\nGo back to menu? (0/1) : ");
        scanf("%d", &menu);
    }
    return 0;
}