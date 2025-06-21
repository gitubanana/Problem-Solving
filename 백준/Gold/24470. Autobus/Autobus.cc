#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

class Edge {
public:
    int v;
    int w;

    Edge(int v, int w) : v(v), w(w) {}
};

class Move : public Edge {
public:
    int transfer;

    Move(int v, int w, int transfer) : Edge(v, w), transfer(transfer) {}

    inline bool operator<(const Move &other) const {
        if (this->w != other.w) {
            return this->w > other.w;
        }

        return this->transfer > other.transfer;
    }
};

using t_umap = std::unordered_map<int, int>;

const int MAX_V = 71;
const int INF = 1e9;
const int START_DIST = 1;

int vCnt;
int transferLimit;
t_umap dists[MAX_V];
int transfers[MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 1; v <= vCnt; v++) {
        dists[v].clear();
    }
}

inline int &getDist(int v, int transfer) {
    int &ret = dists[v][transfer];
    if (ret == 0) {
        ret = INF;
    }

    return ret;
}

int dijkstra(int start, int end) {
    if (start == end) {
        return 0;
    }

    std::priority_queue<Move> pq;

    init();
    dists[start][0] = START_DIST;
    pq.push(Move(start, START_DIST, 0));
    while (!pq.empty()) {
        const Move cur = pq.top();
        const int &curDist = getDist(cur.v, cur.transfer);
        pq.pop();

        if (cur.v == end) {
            return curDist - START_DIST;
        }

        if (cur.w != curDist
            || cur.transfer == transferLimit) {
            continue;
        }

        int nextTransfer = cur.transfer + 1;
        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = getDist(next.v, nextTransfer);
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push(Move(next.v, nextDist, nextTransfer));
        }
    }
    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt, qCnt;

    std::cin >> vCnt >> eCnt;
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        std::cin >> from >> to >> w;
        edges[from].push_back(Edge(to, w));
    }

    std::cin >> transferLimit >> qCnt;
    for (int q = 0; q < qCnt; q++) {
        int start, end;

        std::cin >> start >> end;
        std::cout << dijkstra(start, end) << '\n';
    }
    return 0;
}
