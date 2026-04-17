#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {
    int v;
    int cnt;

    inline bool operator<(const Edge &other) const {
        return this->cnt > other.cnt;
    }
};

const int MAX_V = 1e3;
const int INF = 1e9;
const int START = 0;

int end;
int vCnt;
int cnt[MAX_V];
int edges[MAX_V][MAX_V];
int dists[MAX_V];
bool isWhite[MAX_V];

inline void init(void) {
    for (int v = 0; v < vCnt; v++) {
        dists[v] = cnt[v] = INF;
    }
}

void dijkstra(void) {
    std::priority_queue<Edge> pq;

    init();
    dists[START] = cnt[START] = 0;
    pq.push({START, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curCnt = cnt[cur.v];
        pq.pop();

        if (cur.cnt != curCnt) {
            continue;
        }

        for (int next = 0; next < vCnt; next++) {
            int weight = edges[cur.v][next];
            if (weight == 0) {
                continue;
            }

            int &cmpCnt = cnt[next];
            int nextCnt = cnt[cur.v] + (isWhite[cur.v] ^ isWhite[next]);
            if (cmpCnt < nextCnt) {
                continue;
            }

            int &cmpDist = dists[next];
            int nextDist = dists[cur.v] + weight;
            if (cmpCnt == nextCnt) {
                if (cmpDist > nextDist) {
                    cmpDist = nextDist;
                    pq.push({next, nextCnt});
                }
                continue;
            }

            cmpCnt = nextCnt;
            cmpDist = nextDist;
            pq.push({next, nextCnt});
        }
    }
}

int main(void) {
    fscanf(stdin, " %d %d", &vCnt, &end);
    for (int v = 0; v < vCnt; v++) {
        char ch;

        fscanf(stdin, " %c", &ch);
        isWhite[v] = (ch == '1');
    }

    for (int from = 0; from < vCnt; from++) {
        for (int to = 0; to < vCnt; to++) {
            fscanf(stdin, " %d", &edges[from][to]);
        }
    }

    dijkstra();
    fprintf(stdout, "%d %d\n", cnt[end], dists[end]);
    return 0;

}