#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //배열(order) 선언
    char order[6];
    
    //큐(queue) 선언
    int* queue = (int*)calloc(n,sizeof(int));
    int head = -1,tail = -1;
    
    //명령 실행
    for(int i = 0; i<n; i++){
        scanf("%s",order);
        if(!strcmp(order,"push")){
            if(head==tail){
                head = tail = 0;
                scanf("%d",&queue[tail++]);
            }
            else{
                scanf("%d",&queue[tail++]);
            }
        }
        else if(!strcmp(order,"pop")){
            if(head==tail){
                printf("-1\n");
            }
            else{
                printf("%d\n",queue[head]);
                queue[head++] = 0;
            }
        }
        else if(!strcmp(order,"size")){
            printf("%d\n",tail-head);
        }
        else if(!strcmp(order,"empty")){
            if(head==tail)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(!strcmp(order,"front")){
            if(head==tail)
                printf("-1\n");
            else
                printf("%d\n",queue[head]);
        }
        else{
            if(head==tail)
                printf("-1\n");
            else
                printf("%d\n",queue[tail-1]);
        }
        
    }
    
}