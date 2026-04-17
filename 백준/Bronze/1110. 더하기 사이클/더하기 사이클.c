#include<stdio.h>

int main()
{
    int N,count=0;
    scanf("%d",&N);
    int A=N;
    while(1)
    {
        N=(N/10+N%10)%10+N%10*10,count++;
        if(N==A)
        {
            printf("%d",count);
            break;
        }
    } 
    return 0;
}