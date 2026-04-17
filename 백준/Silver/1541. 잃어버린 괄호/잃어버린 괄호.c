#include<stdio.h>
#include<string.h>
int main(){
    int i=0,len=0,a=0,flag=0,total=0;
    char arr[51];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        if(arr[i]=='+'){
            if(flag){
                a*=-1;
                total+=a;
                a=0;
            }
            else{
                total+=a;
                a=0;
            }
        }
        else if(arr[i]=='-'){
            if(flag){
                total+=a*(-1);
            }
            else{
                total+=a;
            }
            a=0;
            flag=1;
        }
        else{//숫자일 때
            a*=10;
            a+=arr[i]-'0';
        }
    }
    if(flag){
        a*=-1;
        total+=a;
    }
    else{
        total+=a;
    }
    
    fprintf(stdout,"%d",total);
}