#include<stdio.h>

int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //별 찍기
    for(int i = 0; i<n; i++){
        for(int j = 1; j<n-i; j++)
            printf(" ");
        for(int k = 0; k<2*i+1; k++)
            printf("*");
        printf("\n");
    } 
}