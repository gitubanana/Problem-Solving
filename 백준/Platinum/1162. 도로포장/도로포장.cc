#include <iostream>
#include <queue>

struct t_edge {
    int v;
    long w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

struct t_elem : public t_edge {
    int pave;

    t_elem(int v, long w, int pave) {
        this->v = v;
        this->w = w;
        this->pave = pave;
    }
};

const int START = 1;
const int MAX_V = 1e4 + 1;
const int MAX_PAVE = 20 + 1;
const long INF = 1e10 + 1;

int vCnt;
long dists[MAX_V][MAX_PAVE];
std::vector<t_edge> edges[MAX_V];

void dijkstra(int start, int pave) {
    std::priority_queue<t_elem> pq;

    for (int v = 1; v <= vCnt; v++) {
        for (int p = 0; p <= pave; p++) {
            dists[v][p] = INF;
        }
    }

    dists[start][pave] = 0;
    pq.push(t_elem(start, 0, pave));
    while (!pq.empty()) {
        const t_elem cur = pq.top();
        const long &curDist = dists[cur.v][cur.pave];
        pq.pop();

        if (curDist != cur.w) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            for (int use = 0; use <= 1; use++) {
                int nextPave = cur.pave - use;
                if (nextPave < 0) {
                    continue;
                }

                long &nextDist = dists[next.v][nextPave];
                long cmpDist = curDist + (next.w * (use == 0));
                if (nextDist <= cmpDist) {
                    continue;
                }

                nextDist = cmpDist;
                pq.push(t_elem(next.v, nextDist, nextPave));
            }
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt, pave;

    std::cin >> vCnt >> eCnt >> pave;
    while (eCnt-- > 0) {
        int a, b, w;

        std::cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra(START, pave);

    long ans = INF;
    for (int p = 0; p <= pave; p++) {
        ans = std::min(ans, dists[vCnt][p]);
    }

    std::cout << ans << '\n';
    return 0;
}
