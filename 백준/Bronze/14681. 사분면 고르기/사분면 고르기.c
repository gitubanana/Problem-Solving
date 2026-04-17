#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int con1 = x>0,con2 = y>0;
    if(con1 && con2){
        printf("%d",1);
    }else if(!con1 && con2){
        printf("%d",2);
    }else if(!con1 && !con2){
        printf("%d",3);
    }else{
        printf("%d",4);
    }
    
    
}