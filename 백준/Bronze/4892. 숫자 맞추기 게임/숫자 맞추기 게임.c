#include<stdio.h>
int main(){
    int n,cnt=0;
    
    while(1){
        cnt++;
        scanf("%d",&n);
        if(n){
            if(3*n%2==0)
                printf("%d. even %d\n",cnt,n/2);
            else
                printf("%d. odd %d\n",cnt,(n-1)/2);
        }
        else{
            break;
        }
    }
    
}