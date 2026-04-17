#include<stdio.h>
int main(){
    int len=0,i=0,cnt=0;
    char arr[101];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        if(arr[i]==',')
            cnt++;
    }
    
    fprintf(stdout,"%d",cnt+1);
    
}