#include<stdio.h>
#include<string.h>

int main(){
    int cnt=0,len=0,i=0;
    char arr[101];
    fscanf(stdin,"%s",arr);
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        switch(arr[i]){
            case 'c':
                if(i<len-1 && (arr[i+1]=='=' || arr[i+1]=='-')){
                    i++;
                }
                cnt++;
                break;
            case 'd':
                if(i<len-1 && arr[i+1]=='-'){
                    i++;
                }
                else if(i<len-2 && arr[i+1]=='z' && arr[i+2]=='='){
                    i+=2;
                }
                cnt++;
                break;
            case 'l':
                if(i<len-1 && arr[i+1]=='j'){
                    i++;
                }
                cnt++;
                break;
            case 'n':
                if(i<len-1 && arr[i+1]=='j'){
                    i++;
                }
                cnt++;
                break;
            case 's':
                if(i<len-1 && arr[i+1]=='='){
                    i++;
                }
                cnt++;
                break;
            case 'z':
                if(i<len-1 && arr[i+1]=='='){
                    i++;
                }
                cnt++;
                break;
            default:
                cnt++;
        }
    }
    
    fprintf(stdout,"%d",cnt);
}