#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //total 선언
    int total = 0;
    
    //dial 선언 및 입력받기
    char* dial = (char*)malloc(sizeof(char) * 16);
    scanf("%s",dial);
    
    //시간(초) 구하기
    for(int i = 0,n = strlen(dial); i < n; i++){
        if(dial[i] <= 'C'){ // A,B,C
            total+=3;
        }
        else if(dial[i] <= 'F'){ // D,E,F
            total+=4;
        }
        else if(dial[i] <= 'I'){ // G,H,I
            total+=5;
        }
        else if(dial[i] <= 'L'){ // J,K,L
            total+=6;
        }
        else if(dial[i] <= 'O'){ // M,N,O
            total+=7;
        }
        else if(dial[i] <= 'S'){ // P,Q,R,S
            total+=8;
        }
        else if(dial[i] <= 'V'){ // T,U,V
            total+=9;
        }
        else { // W,X,Y,Z
            total+=10;
        }
    }
    
    //출력하기
    printf("%d",total);
    
    
}