#include <stdio.h>

const int MAX_V = 10;

int vCnt;
int dists[MAX_V][MAX_V];
int ans = (1L << 31) - 1;

void floydWarshall(void) {
    for (int mid = 0; mid < vCnt; mid++) {
        for (int from = 0; from < vCnt; from++) {
            for (int to = 0; to < vCnt; to++) {
                int &cmpDist = dists[from][to];
                int nextDist = dists[from][mid] + dists[mid][to];

                if (cmpDist <= nextDist) {
                    continue;
                }
                
                cmpDist = nextDist;
            }
        }
    }
}

void backTracking(int cur, int curDist=0, int visited=0) {
    static const int endVisited = (1 << vCnt) - 1;

    visited |= (1 << cur);
    if (visited == endVisited) {
        if (ans > curDist) {
            ans = curDist;
        }
        return;
    }

    for (int next = 0; next < vCnt; next++) {
        if (visited & (1 << next)) {
            continue;
        }

        backTracking(next, curDist + dists[cur][next], visited);
    }
}

int main(void) {
    int start;

    fscanf(stdin, " %d %d", &vCnt, &start);
    for (int from = 0; from < vCnt; from++) {
        for (int to = 0; to < vCnt; to++) {
            fscanf(stdin, " %d", &dists[from][to]);
        }
    }

    floydWarshall();
    backTracking(start);

    fprintf(stdout, "%d\n", ans);
    return 0;
}
