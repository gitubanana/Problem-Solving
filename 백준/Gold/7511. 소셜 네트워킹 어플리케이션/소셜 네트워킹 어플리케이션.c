#include <stdio.h>
#define MAX_V 1000001

int vCnt;
int parents[MAX_V];

void init(void) {
	for (int v = 1; v <= vCnt; v++) {
		parents[v] = v;
	}
}

int getParent(int x) {
	if (parents[x] != x) {
		parents[x] = getParent(parents[x]);
	}
	return parents[x];
}

void group(int y, int x) {
	int yParent = getParent(y);
	int xParent = getParent(x);

	parents[yParent] = parents[xParent];
}

int main(void) {
	int testCnt;

	scanf(" %d", &testCnt);
	for (int t = 1; t <= testCnt; t++) {
		int eCnt;

		scanf(" %d %d", &vCnt, &eCnt);
		init();
		while (eCnt-- > 0) {
			int a, b;

			scanf(" %d %d", &a, &b);
			group(a, b);
		}

		int checkCnt;

		scanf(" %d", &checkCnt);
		printf("Scenario %d:\n", t);
		while (checkCnt-- > 0){
			int a, b;

			scanf(" %d %d", &a, &b);
			printf("%d\n", getParent(a) == getParent(b));
		}
		printf("\n");
	}
	return 0;
}
