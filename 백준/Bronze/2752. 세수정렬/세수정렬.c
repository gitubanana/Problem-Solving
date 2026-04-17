#include<stdio.h>
#define SWAP(a,b){int c=a;a=b;b=c;}
int main(){
    //배열(arr) 선언 및 입력받기
    int arr[3];
    for(int i=0; i<3; i++)
        scanf("%d",&arr[i]);
    
    //정렬하기
    for(int i=0,j,tmp; i<3; i++){
        tmp = arr[(j=i)];
        while(--j>=0 && arr[j]>tmp)
            SWAP(arr[j],arr[j+1]);
    }
    
    //출력하기
    for(int i=0; i<3; i++)
        printf("%d\n",arr[i]);
}