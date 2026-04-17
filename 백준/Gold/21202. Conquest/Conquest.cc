#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_V = 2e5 + 1;
const int START = 1;
const int CONQUERED = -1;

int vCnt;
int army[MAX_V];
std::vector<int> edges[MAX_V];

class Comp {
public:
    inline bool operator()(const int &a, const int &b) const {
        return army[a] > army[b];
    }
};

int prim(int start=START) {
    std::priority_queue<int, std::vector<int>, Comp> pq;
    int ourArmy = army[START];

    army[START] = CONQUERED;
    for (const int &next : edges[START]) {
        pq.push(next);
    }

    while (!pq.empty()) {
        const int cur = pq.top();
        int &curArmy = army[cur];
        pq.pop();

        if (curArmy == CONQUERED) {
            continue;
        }

        if (ourArmy <= curArmy) {
            break;
        }

        ourArmy += curArmy;
        curArmy = CONQUERED;
        for (const int &next : edges[cur]) {
            if (army[next] == CONQUERED) {
                continue;
            }

            pq.push(next);
        }
    }
    return ourArmy;
}

int main(void) {
    int vCnt, eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int v = 1; v <= vCnt; v++) {
        scanf(" %d", &army[v]);
    }

    printf("%d\n", prim());
    return 0;
}
