#include<stdio.h>
int main(){
    int i=0,len=0,tmp=1;
    char arr[51];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        switch(arr[i]){
            case 'A':
                if(tmp==1)
                    tmp=2;
                else if(tmp==2)
                    tmp=1;
                break;
            case 'B':
                if(tmp==2)
                    tmp=3;
                else if(tmp==3)
                    tmp=2;
                break;
            case 'C':
                if(tmp==1)
                    tmp=3;
                else if(tmp==3)
                    tmp=1;
                break;
        }
    }
    
    fprintf(stdout,"%d",tmp);
    
}