#include <stdio.h>

int main() {

    int num = 0, count = 0;

    printf("Number : ");
    scanf("%d", &num);

    while(num != 0){
        count++;
        num /= 10;
    }

    printf("Number of digits : %d", count);
}