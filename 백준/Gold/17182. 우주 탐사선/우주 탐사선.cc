#include <stdio.h>

const int MAX_V = 10;

int vCnt;
bool visited[MAX_V];
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

void backTracking(int cur, int curDist=0, int depth=0) {
    static const int depthLimit = vCnt - 1;

    if (depth == depthLimit) {
        if (ans > curDist) {
            ans = curDist;
        }
        return;
    }

    visited[cur] = true;
    for (int next = 0; next < vCnt; next++) {
        if (visited[next]) {
            continue;
        }

        backTracking(next, curDist + dists[cur][next], depth + 1);
    }
    visited[cur] = false;
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
