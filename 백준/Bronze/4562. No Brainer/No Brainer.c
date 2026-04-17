#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0,x,y; i<n; i++){
        scanf("%d %d",&x,&y);
        if(x<y)
            printf("NO BRAINS\n");
        else
            printf("MMM BRAINS\n");
    }
    
}