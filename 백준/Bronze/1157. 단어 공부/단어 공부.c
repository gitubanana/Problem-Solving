#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    //선언
    int alpha[26] = { 0 };
    int tmp = 0,tmp2 = 0;
    
    //arr 선언 및 할당 됐는지 확인
    char* arr = (char*)calloc(1000001,sizeof(char));
    if(!arr){
        return 1;
    }
    
    //arr 입력받기
    scanf("%s",arr);
    
    //어떤 글자가 쓰였는지 저장
    for(int i = 0,n = strlen(arr); i < n; i++){
        tmp = (int)toupper(arr[i]) - 65;
        alpha[tmp]++;
    }
    
    //tmp에 0 대입
    tmp = 0;
    
    //뭐가 제일 많이 쓰였는지 확인
    for(int i = 1; i < 26; i++){
        if(alpha[tmp] < alpha[i]){
            tmp = i;
            tmp2 = 1;
        }
        else if(alpha[tmp] == alpha[i]){ 
            tmp2 = -1;
        }
    }
    
    // 출력
    if(tmp2 == -1){
        printf("?");
    }
    else{
        printf("%c",tmp+65);
    }
    
    //arr 해제
    free(arr);
}