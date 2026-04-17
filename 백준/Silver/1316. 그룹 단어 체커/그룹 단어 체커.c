#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //n 선언
    int n;
    scanf("%d",&n);
    int cnt = n;
    
    //arr 선언
    char** arr = malloc(sizeof(char*) * n);
    for(int i=0; i<n; i++)
        arr[i] = malloc(sizeof(char) * 101);
    
    //입력받기
    for(int i=0; i<n; i++)
        scanf("%s",arr[i]);
    
    //확인하기
    for(int i=0,tmp,flag; i<n; i++){
        flag=0;
        for(int j=0,l=strlen(arr[i]); j<l-1; j++){
            if(flag) break;
            if(arr[i][j]!=arr[i][j+1]){
                tmp=j+1;
                for(int k=0; k<tmp; k++){
                    if(arr[i][k]==arr[i][tmp]){
                        cnt--;
                        flag++;
                        break;
                    }
                }
            }
            
        }
    }
    
    //출력
    printf("%d",cnt);

    //해제
    for(int i=0; i<n; i++)
        free(arr[i]);
    free(arr);
}
