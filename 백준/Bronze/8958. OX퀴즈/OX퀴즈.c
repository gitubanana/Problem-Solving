#include<stdio.h>
#include<string.h>
int main() {
    int n = 0, score = 0, total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char arr[81];
        total = score = 0;
        scanf("%s",arr);
        for(int j = 0;j<strlen(arr);j++){
            if(arr[j]=='O'){score++;}
            else{score = 0;}
            total+=score;
        }
        printf("%d\n", total);
    }



}