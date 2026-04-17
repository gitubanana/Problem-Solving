#include<stdio.h>
#define SWAP(a,b){int c=a;a=b;b=c;}
int main(){
    int a,b;
    
    while(1){
        scanf("%d %d",&a,&b);
        if(a!=0 && b!=0){
            if(b%a==0 && b>a){
                printf("factor\n");
            }
            else if(a%b==0 && a>b){
                printf("multiple\n");
            }
            else{
                printf("neither\n");
            }
        }
        else{
            break;
        }
    }
    
    
    
}