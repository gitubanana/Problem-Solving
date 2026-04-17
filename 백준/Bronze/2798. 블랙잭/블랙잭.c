#include<stdio.h>
#include<stdlib.h>

int main(){
    //변수(n,m) 선언 및 입력받기
    int n,m,max = 0;
    scanf("%d %d",&n,&m);
    
    //배열(arr) 선언 및 입력받기
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);
    
    //계산하기
    for(int i = 0; i<n-2; i++){
        for(int j = i+1; j<n-1; j++){
            for(int k = j+1; k<n; k++){
                if(max<arr[i]+arr[j]+arr[k] && arr[i]+arr[j]+arr[k]<=m)
                    max = arr[i]+arr[j]+arr[k];
            }
        }
    }
    
    //출력하기
    printf("%d",max);
    
    //해제
    free(arr);
    
}