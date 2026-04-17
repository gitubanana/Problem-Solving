#include<stdio.h>

int main(){
    int hour,min;
    scanf("%d %d",&hour,&min);
    int con1=min-45<0;
    if(con1 && hour==0){
        hour = 23;
        printf("%d %d",hour,60+(min-45));
    }else if(con1){
        printf("%d %d",hour-1,60+(min-45));
    }else{
        printf("%d %d",hour,min-45);
    }
    
    
    
    return 0;
}