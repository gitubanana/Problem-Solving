#include <stdio.h>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;
    int coin;

    inline bool operator<(const t_edge &other) const {
        if (this->w == other.w) {
            return this->coin > other.coin;
        }
        return this->w > other.w;
    }
};

const int MAX_V = 1e2 + 1;
const int MAX_COIN = 1e4 + 1;
const int START = 1;
const int INF = 1e9;

int vCnt;
int coinIgot;
int dists[MAX_V][MAX_COIN];
std::vector<t_edge> edges[MAX_V];

int dijkstra() {
    std::priority_queue<t_edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        for (int c = 0; c <= coinIgot; c++) {
            dists[v][c] = INF;
        }
    }

    dists[START][0] = 0;
    pq.push({START, 0, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v][cur.coin];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        if (cur.v == vCnt) {
            return curDist;
        }

        for (const t_edge &next : edges[cur.v]) {
            int nextCoin = cur.coin + next.coin;
            if (nextCoin > coinIgot) {
                continue;
            }

            int &nextDist = dists[next.v][nextCoin];
            int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({next.v, nextDist, nextCoin});
        }
    }
    return -1;
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d %d", &coinIgot, &vCnt, &eCnt);
    while (eCnt-- > 0) {
        int from, to, w, coin;

        fscanf(stdin, " %d %d %d %d", &from, &to, &w, &coin);
        edges[from].push_back({to, w, coin});
    }

    fprintf(stdout, "%d\n", dijkstra());
    return 0;
}
