#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {
    int v;
    int w;
};

struct Move : public Edge {
    int filled;

    Move(int v, int w, int filled) : Edge({v, w}) {
        this->filled = filled;
    }

    inline bool operator<(const Move &other) const {
        return this->w > other.w;
    }
};

const int INF = 1e9;
const int MAX_V = 1e3;
const int MAX_CAPACITY = 1e2 + 1;

int vCnt;
int capacity;
int start, end;
int price[MAX_V];
int cost[MAX_V][MAX_CAPACITY];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 0; v < vCnt; v++) {
        for (int c = 0; c <= capacity; c++) {
            cost[v][c] = INF;
        }
    }
}

void dijkstra() {
    std::priority_queue<Move> pq;

    init();
    cost[start][0] = 0;
    pq.push(Move(start, 0, 0));
    while (!pq.empty()) {
        const Move cur = pq.top();
        const int &curCost = cost[cur.v][cur.filled];
        pq.pop();

        if (cur.v == end) {
            return;
        }

        if (cur.w != curCost) {
            continue;
        }

        if (cur.filled < capacity) {
            int &cmpCost = cost[cur.v][cur.filled + 1];
            int nextCost = curCost + price[cur.v];
            if (cmpCost > nextCost) {
                cmpCost = nextCost;
                pq.push(Move(cur.v, nextCost, cur.filled + 1));
            }
        }

        for (const Edge &next : edges[cur.v]) {
            int nextFilled = cur.filled - next.w;
            if (nextFilled < 0) {
                continue;
            }

            int &cmpCost = cost[next.v][nextFilled];
            if (cmpCost <= curCost) {
                continue;
            }

            cmpCost = curCost;
            pq.push(Move(next.v, curCost, nextFilled));
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int v = 0; v < vCnt; v++) {
        fscanf(stdin, " %d", &price[v]);
    }
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    int qCnt;

    fscanf(stdin, " %d", &qCnt);
    for (int q = 0; q < qCnt; q++) {
        fscanf(stdin, " %d %d %d", &capacity, &start, &end);
        dijkstra();

        int &ans = cost[end][0];
        if (ans == INF) {
            fprintf(stdout, "impossible\n");
        } else {
            fprintf(stdout, "%d\n", ans);
        }
    }
    return 0;
}
