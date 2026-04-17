#include<stdio.h>
#include<stdlib.h>
int main(){
    //개수(n) 선언 및 입력받기
    int n,temp,i,j,total = 0;
    scanf("%d",&n);
    
    //시간 저장할 배열(time) 선언
    int* time = (int*)calloc(n,sizeof(int));
    
    //시간 입력받기
    for(i = 0; i<n; i++)
        scanf("%d",&time[i]);
    
    //정렬(오름차순) 하기
    for(i = 0,j = 0; i<n;i++){
        temp = time[(j = i)];
        while(--j>=0 && time[j] > temp){
            time[j+1] = time[j];
            time[j] = temp;
        }
    }
    
    //최소 시간 구하기
    for(i = 0,j = 0; i<n; i++){
        temp = time[i] + j;
        total += temp;
        j += time[i];
    }
    
    //출력하기
    printf("%d",total);
}