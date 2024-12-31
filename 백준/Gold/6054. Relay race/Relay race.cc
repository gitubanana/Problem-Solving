#include <iostream>
#include <algorithm>
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
const int START = 1;
const int INF = 1e9;

int vCnt;
int dists[MAX_V];
int weights[MAX_V];
std::vector<int> edges[MAX_V];

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

        for (const int &next : edges[cur.v]) {
            int &cmpDist = dists[next];
            int nextDist = curDist + weights[cur.v];
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next, nextDist});
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int from = 1; from <= vCnt; from++) {
        int toCnt;

        std::cin >> weights[from] >> toCnt;
        while (toCnt-- > 0) {
            int to;

            std::cin >> to;
            edges[from].push_back(to);
        }
    }

    dijkstra(START);

    int ans = 0;
    for (int v = 1; v <= vCnt; v++) {
        if (dists[v] == INF) {
            continue;
        }

        ans = std::max(ans, dists[v] + weights[v]);
    }

    std::cout << ans << '\n';
    return 0;
}
