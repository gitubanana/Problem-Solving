#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int c = a; a = b; b = c;}
void quick_sort(int arr[],int left,int right);
int bin_search(int arr[],int target,int left,int right);
int main(){
    //첫 번째 수의 개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //첫 번째 배열(arr1) 선언 및 입력받기
    int* arr1 = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++)
        scanf("%d",&arr1[i]);
    
    //두 번째 수의 개수(m) 선언 및 입력받기
    int m;
    scanf("%d",&m);
    
    //두 번째 배열(arr2) 선언 및 입력받기
    int* arr2 = (int*)malloc(sizeof(int) * m);
    for(int i = 0; i<m; i++)
        scanf("%d",&arr2[i]);
    
    //arr1 정렬하기(오름차순)
    quick_sort(arr1,0,n-1);
    
    //수가 존재하는지 확인 및 출력
    for(int i = 0; i<m; i++){
        if(bin_search(arr1,arr2[i],0,n-1))
           printf("1\n"); 
        else
            printf("0\n");
    }
}

int bin_search(int arr[],int target,int left,int right){
    if(left>right)
        return 0;
    
    int mid = (left+right)/2;
    
    if(arr[mid]==target)
        return 1;
    else if(arr[mid]>target)
        return bin_search(arr,target,left,mid-1);
    else
        return bin_search(arr,target,mid+1,right);
}

void quick_sort(int arr[],int left,int right){
    int L = left,R = right;
    int pivot = arr[(left+right)/2];
    do{
        while(arr[L]<pivot)
            L++;
        while(arr[R]>pivot)
            R--;
        if(L<=R){
            SWAP(arr[L],arr[R]);
            L++;
            R--;
        }
    }while(L<=R);
    
    if(left<R)
        quick_sort(arr,left,R);
    if(L<right)
        quick_sort(arr,L,right);
}