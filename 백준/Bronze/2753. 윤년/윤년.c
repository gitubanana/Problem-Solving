#include<stdio.h>

int main(){
    int year;
    scanf("%d",&year);
    if((year%100!=0 || year%400==0) && year%4==0){
        printf("%d",1);
    }
    else{
        printf("%d",0);
    }
    
    
    
    return 0;
}