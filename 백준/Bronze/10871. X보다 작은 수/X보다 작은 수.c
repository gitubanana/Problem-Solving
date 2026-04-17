#include<stdio.h>

int main(){
    int n = 0,x = 0;
    int temp = 0;
    scanf("%d %d",&n,&x);
    for(int i = 0;i<n;i++){
        scanf("%d",&temp);
        if(temp<x){
            printf("%d ",temp);
        }
    }
    
    
    
}