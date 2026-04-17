#include<stdio.h>
int fact(int n){
    if(n<=1){
        return 1;
    }
    return n * fact(n-1);
}

int main(){
    //n 선언 및 입력받기
    int n = 0;
    scanf("%d",&n);
    
    //출력하기
    printf("%d\n",fact(n));
}