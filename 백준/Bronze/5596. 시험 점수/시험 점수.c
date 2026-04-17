#include<stdio.h>

int main(){
    int minkuk[4],mansae[4];
    int i,total1=0,total2=0;
    
    for(i=0; i<4; i++){
        scanf("%d",&minkuk[i]);
        total1 += minkuk[i];   
    }
    
    for(i=0; i<4; i++){
        scanf("%d",&mansae[i]);
        total2 += mansae[i];
    }
    
    total1 > total2 ? printf("%d",total1) : printf("%d",total2);
}