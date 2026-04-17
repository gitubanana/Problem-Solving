#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0,tmp; i<n; i++){
        scanf("%d",&tmp);
        printf("Pairs for %d: ",tmp);
        for(int j=1; j<=tmp/2; j++){
            if(j!=tmp-j){
                if(j==1) printf("%d %d",j,tmp-j);
                else printf(", %d %d",j,tmp-j);
            }   
        }
        printf("\n");
    }
    
}