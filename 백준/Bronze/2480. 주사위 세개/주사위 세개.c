#include<stdio.h>
int main(){
    int n1=0,n2=0,n3=0;
    int total = 0;
    scanf("%d %d %d",&n1,&n2,&n3);
    if(n1==n2 && n2==n3){
        total = 10000+n1*1000;
    }else if(n1==n2 || n1==n3 || n2==n3){
        if(n1==n2){
            total=1000+n1*100;
        }else if(n2==n3){
            total=1000+n2*100;
        }else{
            total=1000+n3*100;
        }
    }else{
        if(n1>n2 && n1>n3){
            total = n1*100;
        }else if(n2>n1 && n2>n3){
            total = n2*100;
        }else{
            total = n3*100;
        }
    }
    
    printf("%d",total);
    
    return 0;
}