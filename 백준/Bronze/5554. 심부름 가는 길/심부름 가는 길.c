#include<stdio.h>
int main(){
    int arr[4];
    int total=0;
    for(int i=0; i<4; i++){
        scanf("%d",&arr[i]);
        total+=arr[i];
    }
    
    printf("%d\n%d",total/60,total%60);
    
    
}