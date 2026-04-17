#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0,total,price,re,option,oprice; i<n; i++){
        total=0;
        scanf("%d",&price);
        scanf("%d",&re);
        for(int j=0; j<re; j++){
            scanf("%d %d",&option,&oprice);
            total+=option*oprice;
        }
        printf("%d\n",total+price);
    }
    
    
    
}