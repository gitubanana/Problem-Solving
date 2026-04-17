#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int c = a; a = b; b = c;}
int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //배열(arr) 선언 및 입력받기
    int* arr = (int*)malloc(sizeof(n) * n);
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);
    
    //정렬하기
    quick_sort(arr,0,n-1);
    
    //출력하기
    for(int i = 0; i<n; i++)
        printf("%d\n",arr[i]);
    
    //해제
    free(arr);
    
}

void quick_sort(int arr[],int left,int right){
    int L = left,R = right;
    int pivot = arr[(left+right)/2];
    do{
        while(arr[L]>pivot)
            L++;
        while(arr[R]<pivot)
            R--;
        if(L<=R){
            SWAP(arr[R],arr[L]);
            L++;
            R--;
        }
    }while(L<=R);
    
    if(left<R)
        quick_sort(arr,left,R);
    if(L<right)
        quick_sort(arr,L,right);
}

