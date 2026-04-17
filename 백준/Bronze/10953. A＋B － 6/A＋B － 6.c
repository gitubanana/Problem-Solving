#include<stdio.h>
int main(){
    int n = 0;
    scanf("%d",&n);
    for(int i=0,a=0,b=0;i<n;i++){
        scanf("%d,%d",&a,&b);
        printf("%d\n",a+b);
    }
}