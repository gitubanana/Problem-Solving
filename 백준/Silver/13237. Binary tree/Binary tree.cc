#include <iostream>
#include <vector>

const int MAX_V = 21;

int vCnt;
int heights[MAX_V];
std::vector<int> edges[MAX_V];

void dfs(int cur, int depth=0) {
    heights[cur] = depth;
    for (const int &next : edges[cur]) {
        dfs(next, depth + 1);
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int root = 0;

    std::cin >> vCnt;
    for (int cur = 1; cur <= vCnt; cur++) {
        int parent;

        std::cin >> parent;
        if (parent == -1) {
            root = cur;
        } else {
            edges[parent].push_back(cur);
        }
    }

    dfs(root);
    for (int v = 1; v <= vCnt; v++) {
        std::cout << heights[v] << '\n';
    }
    return 0;
}