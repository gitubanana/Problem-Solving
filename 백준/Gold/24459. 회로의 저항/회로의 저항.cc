#include <stdio.h>
#include <limits.h>
#include <vector>

struct t_edge {
    int v;
    int w;
};

const int MAX_V = 1e5;
const int INF = 1e9 + 1;
const int START = 0;

int vCnt;
int nextMin, nextMax;
int maxAns, minAns = INF;
std::vector<t_edge> edges[MAX_V];

void dfs(int cur, int prev) {
    int max1 = 0, max2 = 0;
    int min1 = INF, min2 = INF;

    for (const t_edge &next : edges[cur]) {
        if (next.v == prev) {
            continue;
        }

        dfs(next.v, cur);
        int maxCmp = nextMax + next.w;
        int minCmp = nextMin + next.w;

        if (max1 < maxCmp) {
            max2 = max1;
            max1 = maxCmp;
        } else if (max2 < maxCmp) {
            max2 = maxCmp;
        }

        if (min1 > minCmp) {
            min2 = min1;
            min1 = minCmp;
        } else if (min2 > minCmp) {
            min2 = minCmp;
        }
    }

    maxAns = std::max(maxAns, max1 + max2);
    nextMax = max1;

    if (min1 == INF) {
        nextMin = 0;
        return;
    }

    nextMin = min1;
    if (min2 == INF) {
        return;
    }

    minAns = std::min(minAns, min1 + min2);
}

int main(void) {
    fscanf(stdin, " %d", &vCnt);
    for (int e = 1; e < vCnt; e++) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dfs(START, -1);
    if (edges[START].size() == 1) {
        minAns = std::min(minAns, nextMin);
    }

    fprintf(stdout, "%d\n", maxAns);
    fprintf(stdout, "%d\n", minAns);
    return 0;
}
