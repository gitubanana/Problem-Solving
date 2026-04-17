#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_V = 101;

int vCnt;
bool reachable[MAX_V][MAX_V];

void warshall(void) {
    for (int mid = 1; mid <= vCnt; mid++) {
        for (int from = 1; from <= vCnt; from++) {
            if (!reachable[from][mid]) {
                continue;
            }

            for (int to = 1; to <= vCnt; to++) {
                reachable[from][to] |= reachable[mid][to];
            }
        }
    }
}

int countReachableFrom(int from) {
    int cnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        cnt += reachable[from][v];
    }
    return cnt;
}

int countReachableTo(int to) {
    int cnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        cnt += reachable[v][to];
    }
    return cnt;
}

int countAllReachable(void) {
    int cnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        cnt += (countReachableFrom(v) + countReachableTo(v) == vCnt - 1);
    }
    return cnt;
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to;

        scanf(" %d %d", &from, &to);
        reachable[from][to] = true;
    }

    warshall();
    printf("%d\n", countAllReachable());
    return 0;
}
