#include<stdio.h>
#include<string.h>
int main(){
    int n,i,a=0,total;
    char arr[10];
    fscanf(stdin,"%d",&n);
    
    for(i=0; i<n; i++){
        fscanf(stdin,"%s",arr);
        if(arr[0]=='P'){
            fprintf(stdout,"skipped\n");
            continue;
        }
        total=a=0;
        for(int j=0,n=strlen(arr); j<n; j++){
            if(arr[j]=='+'){
                total+=a;
                a=0;
            }
            else{
               a*=10; 
               a+=arr[j]-'0';
            }
        }
        fprintf(stdout,"%d\n",total+a);
    }
    
}