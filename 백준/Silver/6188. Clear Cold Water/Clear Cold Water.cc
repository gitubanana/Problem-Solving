#include <iostream>
#include <vector>

const int MAX_SIZE = 99'999 + 1;
const int CHILD_COUNT = 2;
const int ROOT = 1;
const int EMPTY = 0;

int dists[MAX_SIZE];
int edges[MAX_SIZE][CHILD_COUNT];

void dfs(int cur, int dist) {
    dists[cur] = dist;
    if (edges[cur][0] == EMPTY) {
        return;
    }

    ++dist;
    for (const int &next : edges[cur]) {
        dfs(next, dist);
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;
    std::cin >> vCnt >> eCnt;

    while (eCnt-- > 0) {
        int parent;

        std::cin >> parent;
        for (int i = 0; i < CHILD_COUNT; i++) {
            std::cin >> edges[parent][i];
        }
    }

    dfs(ROOT, 1);

    for (int v = 1; v <= vCnt; ++v) {
        std::cout << dists[v] << '\n';
    }
	return 0;
}