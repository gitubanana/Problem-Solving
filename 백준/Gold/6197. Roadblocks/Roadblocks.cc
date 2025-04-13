#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#define END vCnt

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge& other) const {
        return this->w > other.w;
    }
};

const int START = 1;
const int INF = 1e9; // mabye overflow? -> use long
const int PATH_COUNT = 2;
const int MAX_V = 5e3 + 1;

int vCnt;
int dists[MAX_V][PATH_COUNT];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 1; v <= vCnt; v++) {
        for (int p = 0; p < PATH_COUNT; p++) {
            dists[v][p] = INF;
        }
    }
}

void dijkstra(void) {
    std::priority_queue<Edge> pq;

    init();
    dists[START][0] = 0;
    pq.push({START, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        pq.pop();

        for (const Edge &next : edges[cur.v]) {
            int nextDist = cur.w + next.w;
            if (dists[next.v][0] == nextDist
                || dists[next.v][1] <= nextDist) {
                continue;
            }

            dists[next.v][1] = nextDist;
            std::sort(dists[next.v], dists[next.v] + PATH_COUNT);
            pq.push({next.v, nextDist});
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra();
    fprintf(stdout, "%d\n", dists[END][1]);
    return 0;
}
