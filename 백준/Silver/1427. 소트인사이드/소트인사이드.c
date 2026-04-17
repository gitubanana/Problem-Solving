#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int c = a; a = b; b = c;}
int main(){
    //배열(arr) 선언 및 입력받기
    char* arr = (char*)malloc(sizeof(char) * 11);
    scanf("%[^\n]",arr);
    
    //정렬하기
    for(int i = 1,j,tmp; arr[i]!='\0'; i++){
        tmp = arr[(j=i)]-'0';
        while(--j>=0 && (arr[j]-'0')<tmp)
            SWAP(arr[j],arr[j+1]);
    }
    
    //출력하기
    printf("%s",arr);
    
    //해제
    free(arr);
}