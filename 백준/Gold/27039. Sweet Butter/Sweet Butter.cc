#include <stdio.h>
#include <vector>
#include <queue>

class Edge {
public:
    int v, w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 8e2 + 1;
const int INF = 1e9;

int vCnt, cowCnt;
int cowIn[MAX_V];
std::vector<Edge> edges[MAX_V];

int dijkstra(int start) {
    static int dists[MAX_V];
    std::priority_queue<Edge> pq;
    int totalCowDist = 0;
    int cnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        dists[v] = INF;
    }

    dists[start] = 0;
    pq.push({start, 0});
    do {
        const Edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        if (cowIn[cur.v]) {
            cnt += cowIn[cur.v];
            totalCowDist += curDist * cowIn[cur.v];
            if (cnt == cowCnt) {
                return totalCowDist;
            }
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }

    } while (!pq.empty());

    return INF;
}

int main(void) {
    int eCnt;

    scanf(" %d %d %d", &cowCnt, &vCnt, &eCnt);
    for (int c = 0; c < cowCnt; c++) {
        int v;

        scanf(" %d", &v);
        cowIn[v]++;
    }
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;

        scanf(" %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    int ans = INF;
    for (int v = 1; v <= vCnt; v++) {
        ans = std::min(ans, dijkstra(v));
    }

    printf("%d\n", ans);
    return 0;
}
