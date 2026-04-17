#include<stdio.h>
int main(){
    int n,i=0,len=0,a=0;
    char arr[51];
    fscanf(stdin,"%s %d",arr,&n);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        if(arr[i]>=65){ //문자일 때
            a*=n;
            a+=arr[i]-55;
        }
        else{ //숫자일 때
            a*=n;
            a+=arr[i]-'0';
        }
    }
    
    fprintf(stdout,"%d",a);
}