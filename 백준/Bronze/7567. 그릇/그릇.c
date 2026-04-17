#include<stdio.h>
int main(){
    int len=0,i=0,total=0;
    char arr[51];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len-1; i++){
        if(arr[i]!=arr[i+1])
            total+=10;
        else
            total+=5;
    }
    
    fprintf(stdout,"%d",total+10);
    
    
    
}