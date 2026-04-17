#include<stdio.h>

int main(){
    int total = 0,temp = 0;
    int sum = 0;
    
    scanf("%d",&total);
    
    for(int i = 0; i < 9; i++){
        scanf("%d",&temp);
        sum+=temp;
    }
    
    printf("%d",total-sum);
    
}