#include<stdio.h>
int main(){
    int i=0;
    char arr[101];
    fscanf(stdin,"%s",arr);
    while(arr[i]!='\0'){
        i++;
    }
    printf("%d",i);
}