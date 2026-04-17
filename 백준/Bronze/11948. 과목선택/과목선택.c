#include<stdio.h>
#include<stdlib.h>
int compare(const void* a,const void* b){
    return *(int*)b-*(int*)a;
}

int main(){
    int i;
    int sci[4];
    int soc[2];
    for(i=0; i<4; i++)
        fscanf(stdin,"%d",&sci[i]);
    for(i=0; i<2; i++)
        fscanf(stdin,"%d",&soc[i]);
    
    qsort(sci,sizeof(sci)/sizeof(int),sizeof(int),compare);
    qsort(soc,sizeof(soc)/sizeof(int),sizeof(int),compare);
    
    fprintf(stdout,"%d",sci[0]+sci[1]+sci[2]+soc[0]);
}