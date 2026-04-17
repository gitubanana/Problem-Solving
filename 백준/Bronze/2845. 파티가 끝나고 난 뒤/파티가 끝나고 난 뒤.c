#include<stdio.h>
int main(){
    int n,m,i,tmp;
    fscanf(stdin,"%d %d",&n,&m);
    n=n*m;
    for(i=0; i<5; i++){
        fscanf(stdin,"%d",&tmp);
        fprintf(stdout,"%d ",tmp-n);
    }
    
    
    
    
}