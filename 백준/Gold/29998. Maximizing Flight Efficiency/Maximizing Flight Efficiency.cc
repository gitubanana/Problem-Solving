#include <stdio.h>

const int MAX_V = 1e2;
const int INF = 1e9;

int vCnt;
bool removed[MAX_V][MAX_V];
int dists[MAX_V][MAX_V];

int floydWarshall() {
    int removeCnt = 0;

    for (int mid = 0; mid < vCnt; mid++) {
        for (int from = 0; from < vCnt; from++) {
            if (from == mid) {
                continue;
            }

            for (int to = 0; to < vCnt; to++) {
                if (mid == to) {
                    continue;
                }

                int &cmpDist = dists[from][to];
                int nextDist = dists[from][mid] + dists[mid][to];
                if (cmpDist > nextDist) {
                    return -1;
                }

                if (cmpDist == nextDist) {
                    removeCnt += !removed[from][to];
                    removed[from][to] = removed[to][from] = true;
                }
            }
        }
    }
    return removeCnt;
}

int main(void) {
    scanf(" %d", &vCnt);
    for (int from = 0; from < vCnt; from++) {
        for (int to = 0; to < vCnt; to++) {
            scanf(" %d", &dists[from][to]);
        }
    }

    printf("%d\n", floydWarshall());
    return 0;
}
