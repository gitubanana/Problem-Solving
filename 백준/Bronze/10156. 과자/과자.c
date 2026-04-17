#include<stdio.h>
int main(){
    int k,n,m;
    fscanf(stdin,"%d %d %d",&k,&n,&m);
    
    fprintf(stdout,"%d",k*n>m?k*n-m:0);
    
}