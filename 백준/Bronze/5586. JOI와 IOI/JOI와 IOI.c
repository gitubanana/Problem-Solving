#include<stdio.h>
int main(){
    int len=0,i=0,ioi=0,joi=0;
    char arr[10001];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len-2; i++){
        if(arr[i]=='J' && arr[i+1]=='O' && arr[i+2]=='I')
            joi++;
        else if(arr[i]=='I' && arr[i+1]=='O' && arr[i+2]=='I')
            ioi++;
    }
    
    fprintf(stdout,"%d\n%d",joi,ioi);
}