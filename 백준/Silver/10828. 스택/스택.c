#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //개수(n) 선언 및 입력받기
    int n;
    scanf("%d",&n);
    
    //스택(stack)과 top 선언
    int* stack = (int*)calloc(n,sizeof(int));
    int top = -1;
    
    //명령 받을 배열(command) 선언
    char command[6];
    
    //명령실행
    for(int i = 0,tmp; i<n; i++){
        scanf("%s",command);
        if(!strcmp(command,"push")){
            scanf("%d",&tmp);
            stack[++top] = tmp;
        }
        else if(!strcmp(command,"pop")){
            if(top>=0){
                printf("%d\n",stack[top]);
                stack[top--]=0;
            }
            else{
                printf("-1\n");
            }
        }
        else if(!strcmp(command,"size")){
            printf("%d\n",top+1);
        }
        else if(!strcmp(command,"empty")){
            if(top<0)
                printf("1\n");
            else
                printf("0\n");
        }
        else{
            if(top>=0)
                printf("%d\n",stack[top]);
            else
                printf("-1\n");
        }
    }
    
    //해제하기
    free(stack);
    
}