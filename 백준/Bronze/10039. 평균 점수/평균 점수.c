#include<stdio.h>

int main(){
    // total,tmp 선언
    int total = 0,tmp = 0;
    
    //입력받기
    for(int i = 0; i < 5; i++){
        scanf("%d",&tmp);
        if(tmp>=40){
            total+=tmp;
        }else{
            total+=40;
        }
    }

    //출력하기
    printf("%d\n",total/5);
}