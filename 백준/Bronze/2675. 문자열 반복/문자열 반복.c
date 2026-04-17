#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //n 선언 및 입력받기
    int n = 0;
    scanf("%d",&n);
    
    //arr 선언
    char* arr = (char*)malloc(sizeof(char) * 21);
    
    // 출력하기
    for(int i = 0,re = 0; i < n; i++){
        scanf("%d %s",&re,arr); // 반복할 횟수와 반복할 문자 입력받기
        for(int j = 0,leng = strlen(arr); j < leng; j++){ // 글자만큼
            for(int k = 0; k < re; k++){ // 반복해서 출력
                printf("%c",arr[j]);
            }
        }
       printf("\n");
    }
    
    //arr 해제
    free(arr);
}