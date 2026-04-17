#include<stdio.h>
int main(){
    int arr[6];
    for(int i=0; i<6; i++){
        scanf("%d",&arr[i]);
        if(i==0){
            printf("%d ",1-arr[i]);
        }
        else if(i==1){
            printf("%d ",1-arr[i]);
        }
        else if(i==2){
            printf("%d ",2-arr[i]);
        }
        else if(i==3){
            printf("%d ",2-arr[i]);
        }
        else if(i==4){
            printf("%d ",2-arr[i]);
        }
        else if(i==5){
            printf("%d ",8-arr[i]);
        }
    }
}