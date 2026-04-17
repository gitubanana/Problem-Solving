#include<stdio.h>
int main(){
    int n,i=0,total,min;
    scanf("%d",&n);
    
    while(i<n){
        total=0;
        min=100;
        int arr[7];
        for(int j=0; j<7; j++){
            scanf("%d",&arr[j]);
            if(arr[j]%2==0){
                min=min>arr[j]?arr[j]:min;
                total+=arr[j];
            }
        }
        printf("%d %d\n",total,min);
        i++;
    }
    
    
    
}