#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,nc=0,c=0,tmp;
    fscanf(stdin,"%d",&n);
    
    for(int i=0; i<n; i++){
        fscanf(stdin,"%d",&tmp);
        if(tmp)
            c++;
        else
            nc++;
    }
    if(nc>c)
        fprintf(stdout,"Junhee is not cute!");
    else
        fprintf(stdout,"Junhee is cute!");
    
    
}