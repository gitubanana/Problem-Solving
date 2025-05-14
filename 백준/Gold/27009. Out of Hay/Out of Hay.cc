#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <algorithm>

struct Edge {
    int v;
    int u;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

const int MAX_V =  2e3 + 1;
const int MAX_BUFFER_SIZE = 210016;

int vCnt;
int parents[MAX_V];
std::vector<Edge> edges;
char buffer[MAX_BUFFER_SIZE];

inline void initParents(void) {
    for (int v = 1; v <= vCnt; v++) {
        parents[v] = v;
    }
}

int getParent(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = getParent(parents[x]);
}

inline void group(int y, int x) {
    parents[getParent(y)] = parents[getParent(x)];
}

int nextInt(void) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

int kruskal(void) {
    int madeEcnt = 0;
    int maxWeight = 0;

    initParents();
    std::sort(edges.begin(), edges.end());
    for (const Edge &edge : edges) {
        if (getParent(edge.v) == getParent(edge.u)) {
            continue;
        }

        maxWeight = std::max(maxWeight, edge.w);
        if (++madeEcnt == vCnt - 1) {
            return maxWeight;
        }

        group(edge.v, edge.u);
    }
    return -1;
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    vCnt = nextInt();
    int eCnt = nextInt();

    for (int e = 0; e < eCnt; e++) {
        edges.push_back({nextInt(), nextInt(), nextInt()});
    }

    printf("%d\n", kruskal());
    return 0;
}
