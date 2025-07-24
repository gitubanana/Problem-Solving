#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>

using Comp = int (*)(int, int);

const int MAX_V = 1e5 + 1;

int vCnt;
int nodeValues[MAX_V];
std::vector<int> edges[MAX_V];

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

void makeMinimaxTree(int cur, int prev=-1, int idx=0) {
    static const Comp funcs[] = {&max, &min};
    static const int initValues[] = {INT_MIN, INT_MAX};

    // if (edges[cur].size() == 1) { // -> 노드가 2개일 때, 오류 ㅜㅜ
    //     return;
    // }

    int &curValue = nodeValues[cur];
    if (curValue != -1) {
        return;
    }

    const Comp &choose = funcs[idx];
    int nextIdx = idx ^ 1;

    curValue = initValues[idx];
    for (const int &next : edges[cur]) {
        if (next == prev) {
            continue;
        }

        makeMinimaxTree(next, cur, nextIdx);
        curValue = choose(curValue, nodeValues[next]);
    }
}

int main(void) {
    int root;
    int leafCnt;
    int queryCnt;

    scanf(" %d %d", &vCnt, &root);
    for (int e = 1; e < vCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int v = 1; v <= vCnt; v++) {
        nodeValues[v] = -1;
    }

    scanf(" %d", &leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        int leaf;

        scanf(" %d", &leaf);
        scanf(" %d", &nodeValues[leaf]);
    }

    makeMinimaxTree(root);

    scanf(" %d", &queryCnt);
    for (int q = 0; q < queryCnt; q++) {
        int node;

        scanf(" %d", &node);
        printf("%d\n", nodeValues[node]);
    }
    return 0;
}
