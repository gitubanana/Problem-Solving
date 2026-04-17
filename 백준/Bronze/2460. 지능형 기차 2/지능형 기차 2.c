#include<stdio.h>
#include<stdlib.h>

int main(){
    int* arr=calloc(10,sizeof(int));
    int tan,naelin,max=0;
    
    for(int i=0; i<10; i++){
        scanf("%d %d",&naelin,&tan);
        arr[i]+=tan-naelin;
        if(i<9){
            arr[i+1]=arr[i];
        }
    }
    
    for(int i=0;i<10;i++){
        if(max<arr[i])
            max=arr[i];
    }
    
    printf("%d",max);
    
    free(arr);
}