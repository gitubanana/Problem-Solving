#include<stdio.h>

int main(){
    //변수 선언
    int min1,min2;
    int burger[3],beverage;
    
    //입력받으면서 최소 구하기
    scanf("%d",&burger[0]);
    min1 = burger[0];
    for(int i = 1; i<3; i++){
        scanf("%d",&burger[i]);
        if(burger[i]<min1)
            min1 = burger[i];
    }
    
    scanf("%d",&min2);
    scanf("%d",&beverage);
    if(min2>beverage)
        min2 = beverage;
    
    //출력하기
    printf("%d",min1+min2-50);


}