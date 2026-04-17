#include<stdio.h>
int isprime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int len=0,i=0,total=0;
    char arr[21];
    fscanf(stdin,"%s",arr);
    
    while(arr[i++]!='\0')
        len++;
    
    for(i=0; i<len; i++){
        if(arr[i]>=97)
            total+=arr[i]-96;
        else
            total+=arr[i]-38;
    }
    
    fprintf(stdout,isprime(total)?"It is a prime word.":"It is not a prime word.");
}
