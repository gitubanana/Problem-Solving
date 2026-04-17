#include<stdio.h>
int main(){
    int arr[42] = {0,};
    int temp = 0,cnt = 0;
    for(int i = 0;i<10;i++){
        scanf("%d",&temp);
        arr[temp%42]=1;
    }
    for(int i = 0;i<42;i++){
        if(arr[i]==1){
            cnt++;
        }
    }
    printf("%d",cnt);
    
}