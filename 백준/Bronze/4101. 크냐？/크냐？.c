#include<stdio.h>
int main(){
    int a,b;
    
    while(1){
        scanf("%d %d",&a,&b);
        if(a && b)
            printf(a>b?"Yes\n":"No\n");
        else
            break;
    }
    
}