#include<stdio.h>
int main(){
    int a;
    char b[4];
    int dap[4] = {0,};
    scanf("%d",&a);
    scanf("%s",b);
    dap[0] = a * ((int)b[2]-48);
    dap[1] = a * ((int)b[1]-48);
    dap[2] = a * ((int)b[0]-48);
    dap[3] = dap[0]+dap[1]*10+dap[2]*100;
    
    for(int i = 0;i<4;i++){
        printf("%d\n",dap[i]);
    }
    
    return 0;
}