#include<stdio.h>
int main(){
    int alpha[26]={0,},len=0,i=0;
    char arr[101];
    
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++)
        alpha[arr[i]-'a']++;
    
    for(i=0; i<26; i++)
        fprintf(stdout,"%d ",alpha[i]);
}