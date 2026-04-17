#include <stdio.h>

int v[53];

void clear(){
	int ch;
	
	while((ch=getchar()) != EOF && ch != '\n'){
		
	}
}

int main(void){
	int N, i, num, cnt=0;
	char    s;
    
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &num);
		v[num]++;
	}
	
	clear();
	for(i=0; i<N; i++){
		scanf("%c", &s);
		if(s==' '){
			v[0]--;
		}
		else if('A'<=s && s<='Z'){
			v[s-64]--;
		}
		else{
			v[s-70]--;
		}
	}
	
	for(i=0; i<53; i++){
		if(v[i]!=0){
			cnt++;
			break;
		}
	}
	
	if(cnt){
		printf("n");
	}
	else{
		printf("y");
	}
	
	return 0;
}