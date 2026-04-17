#include<stdio.h>
#include<stdlib.h>
int main(){
    //배열(arr)와 문자의 개수(cnt) 선언
    char* arr = (char*)malloc(sizeof(char) * 1000001);
    int cnt = 0,i=0;
    
    //입력받기
    scanf("%[^\n]",arr);
    
    //공백문자 개수 세기
    for(i = 0; arr[i]!='\0'; i++){
        if(arr[i]==' ')
            cnt++;
    }
    
    //첫 번째 문자가 공백이면
    if(arr[0]==' ')
        cnt--;
    
    //마지막 문자가 공백이면
    if(arr[i-1]==' ')
        cnt--;
    
    //출력하기
    printf("%d",cnt+1);
    
    //해제
    free(arr);
    
}