#include<stdio.h>
#include<stdlib.h>

int main(){
    //숫자의 개수(n) 선언 및 입력받기
    int n,cnt = 0;
    scanf("%d",&n);
    
    //배열(arr) 선언 및 입력받기
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0,tmp; i<n; i++){
        tmp = 0;
        scanf("%d",&arr[i]);
        for(int j = 1; j<arr[i]+1; j++){
            if(arr[i]%j==0)
                tmp++;
        }
        tmp==2 ? cnt++ : cnt;
    }
    
    
    //출력하기
    printf("%d",cnt);
}