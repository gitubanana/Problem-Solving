#include<stdio.h>
#include<stdlib.h>

int main(){
    //tmp_a,tmp_b 선언
    int tmp_a = 0,tmp_b = 0;
    
    // a와 b 선언
    char* a = (char*)malloc(sizeof(char) * 4);
    char* b = (char*)malloc(sizeof(char) * 4);
    
    //입력받기
    scanf("%s %s",a,b);
    
    //숫자로 바꾸기
    tmp_a = (a[0]-'0') + (a[1]-'0') * 10 + (a[2]-'0') * 100;
    tmp_b = (b[0]-'0') + (b[1]-'0') * 10 + (b[2]-'0') * 100;
    
    //출력하기
    if(tmp_a > tmp_b){
        printf("%d",tmp_a);
    }
    else{
        printf("%d",tmp_b);
    }
    
    //해제
    free(a);
    free(b);
    
}