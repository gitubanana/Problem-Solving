#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    printf("%d",fibo(n));
}
int fibo(int n){
    if(n==0 || n==1)
        return n;
    return fibo(n-1)+fibo(n-2);
}