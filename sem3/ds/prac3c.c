#include <stdio.h>
int main() {
    int rows, spaces, i;
    printf("Number of rows : ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++){
        for (spaces = 1; spaces <= rows - i; spaces++)
            printf("  ");
        for (spaces = 1; spaces <= 2 * i - 1; spaces++)
            printf("* ");
        printf("\n");
    }
    
    for (i = 1; i <= rows - 1; i++){
        for (spaces = 1; spaces <= i; spaces++)
            printf("  ");
        for (spaces = 1; spaces <= 2 * (rows - i) - 1; spaces++)
            printf("* ");
        printf("\n");
    }
    return 0;
}