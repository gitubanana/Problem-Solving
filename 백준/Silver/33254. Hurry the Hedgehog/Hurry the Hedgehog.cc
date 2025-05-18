#include <stdio.h>
#include <vector>
#include <queue>
#define END vCnt

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1e5 + 1;
const int START = 1;
const int INF = 1e9;

int vCnt;
int passed[MAX_V];
bool isMushroom[MAX_V];
std::vector<int> edges[MAX_V];

int dijkstra(void) {
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        passed[v] = INF;
    }

    passed[START] = 1;
    pq.push({START, 1});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curPassed = passed[cur.v];
        pq.pop();

        if (cur.v == END) {
            return curPassed;
        }

        if (curPassed != cur.w) {
            continue;
        }

        for (const int &next : edges[cur.v]) {
            int &cmpPassed = passed[next];
            int nextPassed = curPassed + 1;
            if (cmpPassed <= nextPassed || !isMushroom[next]) {
                continue;
            }

            cmpPassed = nextPassed;
            pq.push({next, nextPassed});
        }
    }
    return -1;
}

int main(void) {
    int eCnt, mushroomCnt;

    scanf(" %d %d %d", &vCnt, &eCnt, &mushroomCnt);
    isMushroom[START] = isMushroom[END] = true;
    for (int m = 2; m < mushroomCnt; m++) {
        int v;

        scanf(" %d", &v);
        isMushroom[v] = true;
    }
    for (int e = 0; e < eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    printf("%d\n", dijkstra());
    return 0;
}
