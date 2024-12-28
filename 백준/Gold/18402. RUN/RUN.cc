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

const int MAX_V = 100 + 1;
const int INF = 1e9;

int vCnt;
int start;
int escapeTime;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

int dijkstra() {
    int escapeCnt = 0;
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

        if (dists[cur.v] != curDist
            || curDist > escapeTime) {
            continue;
        }

        escapeCnt++;
        for (const t_edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            const int nextDist = curDist + next.w;

            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
    return escapeCnt - (start > vCnt);
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> start >> escapeTime >> eCnt;
    while (eCnt-- > 0) {
        int from, to, w;

        std::cin >> from >> to >> w;
        edges[to].push_back({from, w});
    }

    std::cout << dijkstra() << '\n';
    return 0;
}
