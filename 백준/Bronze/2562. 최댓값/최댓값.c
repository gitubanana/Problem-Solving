#include<stdio.h>
int main(){
    int arr = 0,max = 0,idx = 0;
    scanf("%d",&arr);
    max = arr;
    for(int i = 1;i<9;i++){
        scanf("%d ",&arr);
        if(arr>max){
            max = arr;
            idx = i;
        }
    }
    printf("%d\n",max);
    printf("%d\n",idx+1);    
    
    
}