#include<stdio.h>
#include<string.h>
int main(){
    char string[101];
    scanf("%s",string);
    for(int i=0,n=strlen(string); i<n; i++){
        if(string[i]>=65 && string[i]<=90)
            printf("%c",string[i]);
    }
    
    
}