#include <stdio.h>
int strlength(char str[]){
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
    
}
int isPalindrome(char str[]){
    char reverse[100]; 
    int flag = 0;
    for(int i = 0; str[i] != '\0'; i++){
        reverse[i] = str[strlength(str)-i-1];
    }
    for(int i = 0; str[i] != 0; i++){
        if(reverse[i] == str[i]){
            flag = 1;
        } else {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main(){
    char str[100];
    printf("String : ");
    gets(str);
    if(isPalindrome(str) == 1) printf("%s is a palindrome", str);
    else printf("%s is not apalindrome", str);
    return 0;
}