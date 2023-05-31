#include <stdio.h>

int main(){
    char srcstring[100], substring[100], result[100];
    int reslen = 0, flag = 0;
    printf("Source String : ");
    gets(srcstring);
    printf("Substring : ");
    gets(substring);

    for(int i = 0; substring[i] != '\0'; i++){
        for (int j = 0; srcstring[j] != '\0'; j++){
            if(substring[i] == srcstring[j]){
                result[reslen] = srcstring[j];
                substring[i] = 0;
                reslen++;
            }
        }
    }

    printf("Substring %s present in given source string", result);
    
    return 0;
}

