#include<stdio.h>
int main(){
    int n,v,e;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d",&v,&e);
        printf("%d\n",e-v+2);
    }
    
    
}