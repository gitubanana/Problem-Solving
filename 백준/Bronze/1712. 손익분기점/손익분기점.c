#include<stdio.h>
int main(){
    int a,b,c;
    fscanf(stdin,"%d %d %d",&a,&b,&c);
    
    if(b>=c){
        fprintf(stdout,"-1");
        return 0;
    }
    
    fprintf(stdout,"%d",a/(c-b)+1);
}