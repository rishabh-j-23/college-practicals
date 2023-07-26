#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int pd[2];
    char buffer[100];
    int returnStatus = pipe(pd);

    pid_t pro = fork();

    if(pro == 0){
        read(pd[0], buffer, 100);
        printf("%s ", buffer);
    } else {
        char a[5] = "abcde";
        gets(a);
        write(pd[1], a, 5);
        printf(" %s ", a);
    }


    return 0;    
}