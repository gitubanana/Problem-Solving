#include<stdio.h>
#include<string.h>
int main(){
    //개수(n) 선언 및 입력받기
    int n,i=0,l,r,flag;
    fscanf(stdin,"%d",&n);
    
    for(i=0; i<n; i++){
        char arr[51];
        fscanf(stdin,"%s",arr);
        l=r=flag=0;
        for(int j=0,n=strlen(arr); j<n; j++){
            if(r>l){
                flag=1;
                break;
            }
            if(arr[j]=='(')
                l++;
            else
                r++;
        }
        if(!flag && l==r)
            fprintf(stdout,"YES\n");
        else
            fprintf(stdout,"NO\n");
    }
    
}