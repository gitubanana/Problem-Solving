#include<stdio.h>

int main(){
    char ch;
    int cnt = 0;
    
    while((ch=getchar())!='\n'){
        if(cnt<10){
            printf("%c",ch);
        }
        else if(cnt==10){
            printf("\n");
            printf("%c",ch);
            cnt = 0;
        }
        cnt++;
    }
    
    
}