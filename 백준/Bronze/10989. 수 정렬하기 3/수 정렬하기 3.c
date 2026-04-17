#include <stdio.h>
int main(void) {
	int num;
	int a;
	int count = 1;
	int j;
	int c[10001] = { 0 };
	scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &a);
			c[a] += 1;
		}
	while (count < 10001) {
		j = 0;
			while (j<c[count]) {
				printf("%d\n", count);
				j += 1;
			}
			count += 1;
	}
}