#include<stdio.h>

int main(){
    int n = 0;
    int max = 0,min = 0,temp = 0;
    scanf("%d",&n);
    scanf("%d",&temp);
    max = min = temp;
    for(int i = 1;i<n;i++){
        scanf("%d",&temp);
        if(max<temp){max = temp;}
        if(min>temp){min = temp;}
    }
    printf("%d %d",min,max);
    
}