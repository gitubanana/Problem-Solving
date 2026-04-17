#include<stdio.h>
int main(){
    int arr[5]={0,};
    int i,j,tmp;
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            fscanf(stdin,"%d",&tmp);
            arr[i]+=tmp;
        }
    }
    
    tmp=0;
    for(i=0; i<5; i++){
        if(tmp<arr[i]){
            tmp=arr[i];
            j=i;
        }
    }
    
    fprintf(stdout,"%d %d",j+1,tmp);
    
}