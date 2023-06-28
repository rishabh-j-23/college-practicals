#include <stdio.h>
#include <pthread.h>

int m3[3][3];
int m1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};    
int m2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int row = 0, col = 0;

void* matMultiplyByRow(){
    int i = row++;
    for(int j =0; j < 3; j++){
        for (int k = 0; k < 3; k++){
            m3[i][j] += m1[i][k] * m2[k][j];     
        }
    }
}
void fillmat(int m[3][3], int val){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            m[i][j] = val;
        }
    }
}
void printMatrix(int m[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d  ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    fillmat(m3, 0);
    
    pthread_t th1, th2, th3;
    printf("thread 1\n");
    pthread_create(&th1, NULL, matMultiplyByRow, NULL);
    pthread_join(th1, NULL);
    printMatrix(m3);

    printf("thread 2\n");
    pthread_create(&th2, NULL, matMultiplyByRow, NULL);
    pthread_join(th2, NULL);
    printMatrix(m3);

    printf("thread 3\n");
    pthread_create(&th3, NULL, matMultiplyByRow, NULL);
    pthread_join(th3, NULL);
    printMatrix(m3);
    return 0;
}