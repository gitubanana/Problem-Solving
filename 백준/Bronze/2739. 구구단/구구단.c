#include<stdio.h>
int main(){
    int dan = 0;
    scanf("%d",&dan);
    for(int i = 0; i<9; i++){
        printf("%d * %d = %d\n",dan,i+1,dan*(i+1));
    }
    
    return 0;
}