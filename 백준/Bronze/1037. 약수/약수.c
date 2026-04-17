#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int c=a;a=b;b=c;}
int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //arr 선언 및 입력받기
    int* arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    
    for(int i=1,j,tmp; i<n; i++){
        tmp=arr[(j=i)];
        while(--j>=0 && tmp<arr[j])
            SWAP(arr[j],arr[j+1]);
    }
    
    
    
    //출력
    if(n==1)
        printf("%d",arr[0]*arr[0]);
    else
        printf("%d",arr[0]*arr[n-1]);

    free(arr);
    
}