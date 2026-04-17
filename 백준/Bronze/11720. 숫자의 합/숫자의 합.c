#include<stdio.h>
#include<stdlib.h>
int main(){
    //total,n 선언
    int total = 0,n = 0;
    
    //n 입력받음
    scanf("%d",&n);
    
    //n+1만큼 할당 후 문자열 입력받음
    char* ch = (char*)malloc(sizeof(char) * (n+1));
    scanf("%s",ch);
    
    //total에 합 넣기,'0'은 아스키로 48
    for(int i = 0;i<n;i++)
        total += (int)ch[i] - 48;
    
    //ch 해제
    free(ch);
    
    //total 출력
    printf("%d\n",total);
    
}