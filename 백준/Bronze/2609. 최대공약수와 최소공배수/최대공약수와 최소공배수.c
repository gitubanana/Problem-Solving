#include<stdio.h>

int gcd(int a, int b);
int lcm(int a, int b, int gcd);
int main(){
    int a,b,c;
    scanf("%d %d",&a,&b);
    
    c=gcd(a,b);
    printf("%d\n%d", c, lcm(a,b,c));
    
}
int gcd(int a, int b){
    while(a!=0 && b!=0){
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    return a+b;
}
int lcm(int a, int b, int gcd){
    return a*b/gcd;
}
