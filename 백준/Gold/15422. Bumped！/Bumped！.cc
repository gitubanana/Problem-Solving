#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

struct t_edge {
    unsigned int w;
    int v;
    bool isFlight;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 5e4;

int vCnt;
unsigned int dists[MAX_V][2];
std::vector<t_edge> edges[MAX_V];

unsigned int dijkstra(int start, int end) {
    std::priority_queue<t_edge> pq;

    memset(dists, 255, sizeof(dists));
    dists[start][0] = 0;
    pq.push({0, start, false});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const unsigned int &curDist = dists[cur.v][cur.isFlight];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        if (cur.v == end) {
            return curDist;
        }

        for (const t_edge &next : edges[cur.v]) {
            if (next.isFlight & cur.isFlight) {
                break;
            }

            bool isFlight = cur.isFlight | next.isFlight;
            unsigned int &nextDist = dists[next.v][isFlight];
            unsigned int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({nextDist, next.v, isFlight});
        }
    }
    return -1;
}

int main(void) {
    int roadCnt, flightCnt, start, end;

    fscanf(stdin, " %d %d %d %d %d", &vCnt, &roadCnt, &flightCnt, &start, &end);
    while (roadCnt-- > 0) {
        int from, to;
        unsigned int w;

        fscanf(stdin, " %d %d %u", &from, &to, &w);
        edges[from].push_back({w, to, false});
        edges[to].push_back({w, from, false});
    }
    while (flightCnt-- > 0) {
        int from, to;

        fscanf(stdin, " %d %d", &from, &to);
        edges[from].push_back({0, to, true});
    }

    fprintf(stdout, "%u\n", dijkstra(start, end));
    return 0;
}
