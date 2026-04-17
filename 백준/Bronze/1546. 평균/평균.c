#include<stdio.h>
int main(){
    int n = 0,max = 0,total = 0,temp = 0;;
    scanf("%d",&n); // 개수 입력 받기
    for(int i = 0;i<n;i++){
        scanf("%d",&temp);
        if(max<temp){max = temp;}
        total+=temp;
    }
    printf("%.2lf",((double)total/max * 100)/n);
   
}