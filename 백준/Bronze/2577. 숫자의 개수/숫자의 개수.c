#include<stdio.h>
int main(){
    int a,b,c;
    int abc = 0;
    int arr[10] = {0,};
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    abc = a*b*c;
    int i = 0;
    while(abc>0){
        ++arr[abc%10];
        abc/=10;
    }
    for(int i = 0;i<10;i++){
        printf("%d\n",arr[i]);
    }
    
    
    
}