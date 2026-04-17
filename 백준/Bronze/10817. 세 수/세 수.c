#include<stdio.h>

int main(){
    //선언
    int arr[3] = {0,},max = 0,cnt = 0;
    
    //입력받기
    for(int i = 0; i<3; i++){
        scanf("%d",&arr[i]);
        if(arr[max]<arr[i]){
            max = i;
            cnt++;
        }
    }
    
    //2번째 큰 수 
    if(cnt == 2){
        printf("%d",arr[1]);
    }
    else if(cnt == 0){
        printf("%d",arr[1]>arr[2]?arr[1]:arr[2]);
    }
    else{
        if(max==1){
            printf("%d",arr[0]>arr[2]?arr[0]:arr[2]);
        }
        else {
            printf("%d",arr[0]>arr[1]?arr[0]:arr[1]);
        }
    }
    
}