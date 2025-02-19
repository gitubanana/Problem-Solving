#include <stdio.h>
#include <vector>
#include <queue>

struct t_edge {
    long long w;
    int v;
    bool isFlight;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 5e4;
const long long INF = 1e11;

int vCnt;
long long dists[MAX_V][2];
std::vector<t_edge> edges[MAX_V];

void dijkstra(int start) {
    std::priority_queue<t_edge> pq;

    for (int v = 0; v < vCnt; v++) {
        dists[v][0] = dists[v][1] = INF;
    }

    dists[start][0] = 0;
    pq.push({0, start, false});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const long long &curDist = dists[cur.v][cur.isFlight];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            if (next.isFlight & cur.isFlight) {
                break;
            }

            bool isFlight = cur.isFlight | next.isFlight;
            long long &nextDist = dists[next.v][isFlight];
            long long cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({nextDist, next.v, isFlight});
        }
    }
}

int main(void) {
    int roadCnt, flightCnt, start, end;

    fscanf(stdin, " %d %d %d %d %d", &vCnt, &roadCnt, &flightCnt, &start, &end);
    while (roadCnt-- > 0) {
        int from, to, w;

        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({w, to, false});
        edges[to].push_back({w, from, false});
    }
    while (flightCnt-- > 0) {
        int from, to;

        fscanf(stdin, " %d %d", &from, &to);
        edges[from].push_back({0, to, true});
    }

    dijkstra(start);
    fprintf(stdout, "%lld\n", std::min(dists[end][0], dists[end][1]));
    return 0;
}
