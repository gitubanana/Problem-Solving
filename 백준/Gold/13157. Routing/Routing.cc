#include <iostream>
#include <vector>
#include <queue>
#define END vCnt

class Edge {
private:
    static int edgeCnt;

public:
    int v;
    int id;

    Edge(int v) : v(v), id(edgeCnt++) { }
};

class Move {
public:
    int prev;
    int cur;
    int w;

    inline bool operator<(const Move &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 101;
const int MAX_E = 9901;
const int START = 1;
const int INF = 1e9;

int Edge::edgeCnt = 1;

int vCnt;
int times[MAX_V];
int dists[MAX_V][MAX_V];
bool isDenied[MAX_E][MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int cur = 1; cur <= vCnt; cur++) {
        for (int prev = 1; prev <= vCnt; prev++) {
            dists[cur][prev] = INF;
        }
    }
}

int dijkstra(void) {
    std::priority_queue<Move> pq;

    init();
    dists[START][0] = times[START];
    pq.push({0, START, times[START]});
    while (!pq.empty()) {
        const Move cur = pq.top();
        const int &curDist = dists[cur.cur][cur.prev];
        pq.pop();

        if (cur.cur == END) {
            return curDist;
        }

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.cur]) {
            if (isDenied[next.id][cur.prev]) {
                continue;
            }

            int &cmpDist = dists[next.v][cur.cur];
            int nextDist = curDist + times[next.v];
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({cur.cur, next.v, nextDist});
        }
    }
    return INF;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int from = 1; from <= vCnt; from++) {
        int outgoingCnt;

        std::cin >> outgoingCnt >> times[from];
        for (int o = 0; o < outgoingCnt; o++) {
            int denyCnt, to;

            std::cin >> denyCnt >> to;
            edges[from].push_back(Edge(to));

            const int &eId = edges[from].back().id;
            for (int d = 0; d < denyCnt; d++) {
                int denied;

                std::cin >> denied;
                isDenied[eId][denied] = true;
            }
        }
    }

    int ans = dijkstra();
    if (ans == INF) {
        std::cout << "impossible" << '\n';
    } else {
        std::cout << ans << '\n';
    }
    return 0;
}
