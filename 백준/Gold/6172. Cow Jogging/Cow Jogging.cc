#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int END = 1;
const int MAX_V = 1001;
const int INF = 1e9 + 1;
const int MAX_ROUTE = 100;

int vCnt;
int routeCnt;
int dists[MAX_V][MAX_ROUTE];
std::vector<Edge> edges[MAX_V];

void initDists(void) {
    for (int v = 1; v <= vCnt; v++) {
        for (int r = 0; r < routeCnt; r++) {
            dists[v][r] = INF;
        }
    }
}

void dijkstra(int start) {
    std::priority_queue<Edge> pq;

    initDists();
    dists[start][0] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        pq.pop();

        if (cur.w > dists[cur.v][routeCnt - 1]) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v][routeCnt - 1];
            int nextDist = cur.w + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
            std::sort(dists[next.v], dists[next.v] + routeCnt);
        }
    }
}

void printLengths(void) {
    for (int r = 0; r < routeCnt; r++) {
        if (dists[END][r] == INF) {
            fprintf(stdout, "-1\n");
        } else {
            fprintf(stdout, "%d\n", dists[END][r]);
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d %d", &vCnt, &eCnt, &routeCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
    }

    dijkstra(vCnt);
    printLengths();
    return 0;
}
