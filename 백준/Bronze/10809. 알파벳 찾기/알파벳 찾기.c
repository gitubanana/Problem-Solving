#include<stdio.h>
#include<string.h>

int main(){
    //arr선언
    char arr[101] = {""};
    int a = 0;
    
    //arr 입력받기
    scanf("%s",arr);
    
    for(int i = 97, n = strlen(arr); i < 123; i++){
        a = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == (char)i){
                a = printf("%d ",j);
                break;
            }
        }
        if(!a)
            printf("%d ",-1);
    }
}



