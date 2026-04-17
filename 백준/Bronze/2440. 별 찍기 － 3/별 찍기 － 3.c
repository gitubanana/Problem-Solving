#include<stdio.h>

int main(){
    //개수(n) 선언
    int n;
    scanf("%d",&n);
    
    //별 찍기
    for(int j = 0; j<n; j++){
        for(int i = n-j; i>0; i--){
            printf("*");
        }
        printf("\n");
    }
}