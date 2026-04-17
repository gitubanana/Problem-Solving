#include<stdio.h>
#include<stdlib.h>
typedef struct time{
	int x;
	int y;
}time;

int cmp(const void *a,const void *b){
	time *x=(time *)a;
	time *y=(time *)b;
	if(x->y==y->y){
		return x->x > y->x;
	}
	else{
		return x->y > y->y;
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	time *t=(time *)calloc(n,sizeof(time));
	for(int i=0;i<n;i++)
		scanf("%d %d",&t[i].x,&t[i].y);
	
	qsort(t,n,sizeof(time),cmp);
	
	int cnt=1;
	int std_1=t[0].x;
	int std_2=t[0].y;
	for(int i=1;i<n;i++){
		if(std_2<=t[i].x){
			std_1=t[i].x;
			std_2=t[i].y;
			cnt++;
		}
	}
	printf("%d",cnt);
	
	return 0;
}