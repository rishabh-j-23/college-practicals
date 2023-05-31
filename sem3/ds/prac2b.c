#include <stdio.h>
int strlength(char str[]){
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
    
}
void reverse(char str[]){
    char reverse[100];
    for(int i = 0; str[i] != '\0'; i++){
        reverse[i] = str[strlength(str)-i-1];
    }
    printf("Reversed String : %s", reverse);
}
int main(){
    char src[100];
    printf("String : "); 
    gets(src);
    
    reverse(src);    
    return 0;
}