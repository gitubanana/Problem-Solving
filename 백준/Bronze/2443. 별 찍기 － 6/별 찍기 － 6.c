#include<stdio.h>

int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //별 찍기
    for(int i = n; i>0; i--){
        for(int k = 0; k<n-i; k++)
            printf(" ");
        for(int j = 0; j<2*i-1; j++)
            printf("*");
        printf("\n");
    }
    
}