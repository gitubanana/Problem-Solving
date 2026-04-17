#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,total=0,tmp=0;
    scanf("%d",&n);

    int* arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
        if(arr[i]){
            if(i!=0 && arr[i-1]){
                tmp++;
            }
            else{
                tmp=1;
            }
        }
        else{
            tmp=0;
        }
        total+=tmp;
    }
    
    printf("%d",total);
    
    free(arr);
}