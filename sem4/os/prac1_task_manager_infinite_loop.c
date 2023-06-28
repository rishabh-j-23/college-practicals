#include <stdio.h>

int main()
{
    
    int nr = 22, dr = 7;

    while(1){
        printf("%d", nr/dr);
        nr = nr%dr;

    }

    return 0;
}
