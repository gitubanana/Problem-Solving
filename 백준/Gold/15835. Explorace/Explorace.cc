#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 21;

int vCnt;
bool visited[MAX_V];
std::vector<Edge> edges[MAX_V];

int prim(int start=1) {
    int madeCnt = 0;
    int totalWeight = 0;
    std::priority_queue<Edge> pq;

    pq.push({start, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        pq.pop();

        if (visited[cur.v]) {
            continue;
        }

        totalWeight += cur.w;
        if (++madeCnt == vCnt) {
            return totalWeight;
        }

        visited[cur.v] = true;
        for (const Edge &next : edges[cur.v]) {
            if (visited[next.v]) {
                continue;
            }

            pq.push({next.v, next.w});
        }
    }
    return -1;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 1; t <= testCnt; t++) {
        int eCnt;

        scanf(" %d %d", &vCnt, &eCnt);
        for (int v = 1; v <= vCnt; v++) {
            edges[v].clear();
            visited[v] = false;
        }
        for (int e = 0; e < eCnt; e++) {
            int a, b, w;

            scanf(" %d %d %d", &a, &b, &w);
            edges[a].push_back({b, w});
            edges[b].push_back({a, w});
        }
        printf("Case #%d: %d meters\n", t, prim());
    }
    return 0;
}
