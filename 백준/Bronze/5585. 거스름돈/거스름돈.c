#include<stdio.h>
int main(){
    //돈 종류(coin) 선언
    int coin[6] = {500,100,50,10,5,1};
    
    //변수 선언과 내야할 돈(price) 선언 및 입력받기
    int price,change,num = 0;
    scanf("%d",&price);
    
    //거스름돈 구하기
    change = 1000-price;
    
    //개수 구하기
    for(int i = 0; i<6; i++){
        if(coin[i]<=change)
            num+=change/coin[i];
        change%=coin[i];
    }
    
    //출력하기
    printf("%d",num);
    
}