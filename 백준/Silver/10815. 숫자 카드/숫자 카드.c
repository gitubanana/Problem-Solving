#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int c=a;a=b;b=c;}
int compare(const void* a,const void* b);
int bin_search(int arr[],int target,int left,int right);
int main(){
    int n,m,i,j,tmp;
    scanf("%d",&n);
    
    int* cards=malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d",&cards[i]);
    
    //cards 정렬(오름차순)
    qsort(cards,n,sizeof(int),compare);
    
    scanf("%d",&m);
    
    for(i=0; i<m; i++){
        scanf("%d",&tmp);
        printf("%d ",bin_search(cards,tmp,0,n-1));
    }
    
    free(cards);
}
int compare(const void* a,const void* b){
    int n1=*(int*)a,n2=*(int*)b;
    if(n1>n2)
        return 1;
    else if(n1<n2)
        return -1;
    else
        return 0;
}
int bin_search(int arr[],int target,int left,int right){
    if(left>right)
        return 0;
    int mid=(left+right)/2;
    if(target==arr[mid])
        return 1;
    else if(target>arr[mid])
        return bin_search(arr,target,mid+1,right);
    else
        return bin_search(arr,target,left,mid-1);
}
