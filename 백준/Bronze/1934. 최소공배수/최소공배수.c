#include<stdio.h>
#include<stdlib.h>
int lcm(int a, int b){
    int gcd,mul=a*b;
    while(a!=0 && b!=0){
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    gcd=a+b;
    return mul/gcd;
}
int main(){
    int n,a,b;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",lcm(a,b));
    }
}