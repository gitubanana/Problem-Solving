#include<stdio.h>
inline int isprime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    
    for(i=n; i<=m; i++){
        if(isprime(i) && i!=1)
            printf("%d\n",i);
    }
    
    
}