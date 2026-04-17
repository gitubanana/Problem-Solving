#include<stdio.h>
int main(){
    int n = 0;
    int total = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        total+=i+1;
    }
    printf("%d",total);
    
    
    return 0;
}