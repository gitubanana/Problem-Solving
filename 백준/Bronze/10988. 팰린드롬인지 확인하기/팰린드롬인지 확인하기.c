#include<stdio.h>
int main(){
    int len=0,i=0,flag=0;
    char str[101];
    fscanf(stdin,"%s",str);
    
    while(str[i++]!='\0')
        len++;
    
    for(i=0; i<len/2; i++){
        if(str[i]!=str[len-i-1]){
            flag=1;
            break;
        }
    }
    
    fprintf(stdout,"%d",flag?0:1);
    
    
}