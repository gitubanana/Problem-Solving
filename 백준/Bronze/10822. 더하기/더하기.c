#include<stdio.h>
#include<string.h>
int main(){
    int total=0;
    char s[101];
    scanf("%s",s);
    
    char* ptr=strtok(s,",");
    while(ptr!=NULL){
        total+=atoi(ptr);
        ptr=strtok(NULL,",");
    }
    
    printf("%d",total);
}