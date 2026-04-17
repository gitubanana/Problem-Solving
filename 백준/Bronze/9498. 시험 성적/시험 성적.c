#include<stdio.h>
int main(){
    char result;
    int score;
    scanf("%d",&score);
    switch(score/10){
        case 10: case 9:
            result = 'A';
            break;
        case 8:
            result = 'B';
            break;
        case 7:
            result = 'C';
            break;
        case 6:
            result = 'D';
            break;
        default:
            result = 'F';
    }
    printf("%c",result);
    return 0;
}