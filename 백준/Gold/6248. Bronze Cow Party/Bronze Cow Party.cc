#include <iostream>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1000 + 1;
const int INF = 1e9;

int vCnt;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

void dijkstra(int start) {
    std::priority_queue<t_edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v] = INF;
    }

    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt, start;

    std::cin >> vCnt >> eCnt >> start;
    while (eCnt-- > 0) {
        int a, b, w;

        std::cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra(start);

    int maxTime = 0;
    for (int v = 1; v <= vCnt; v++) {
        if (dists[v] == INF) {
            continue;
        }

        maxTime = std::max(maxTime, dists[v]);
    }

    std::cout << (maxTime << 1) << '\n';
    return 0;
}
