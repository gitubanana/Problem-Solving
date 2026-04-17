#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	char *s1 = (char *)a;
	char *s2 = (char *)b;
	
	if(strlen(s1) == strlen(s2))
		return strcmp(s1,s2);
	else {
		if(strlen(s1)<strlen(s2)) return -1;
		else return 1;
	}
}

int main(){
	
	int n;
	scanf("%d",&n);
	char arr[n][51];
	for(int i=0;i<n;i++){	
		scanf("%s",arr[i]);
	}
	
	qsort(arr,n,sizeof(arr[0]),compare);
	
	int temp=0;
	char* curText = "A";
	while(temp != n){
		if(strcmp(arr[temp],curText) != 0){
			if(temp != n-1)
				printf("%s\n",arr[temp]);
			else printf("%s",arr[temp]);
			curText = arr[temp];
		}
		temp++;
 	}
}