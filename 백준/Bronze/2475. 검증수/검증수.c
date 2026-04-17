#include<stdio.h>
#include<string.h>

int main(){
    //합계(total) 선언
    int total = 0;
    
    //배열(arr) 선언 및 5개 숫자 입력받기
    char arr[6];
    scanf("%c %c %c %c %c",&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    
    //검증수 계산하기
    for(int i = 0; i<5; i++)
        total += (arr[i]-'0')*(arr[i]-'0');
    
    //출력
    printf("%d",total%10);
    
}