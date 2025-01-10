#include <iostream>
#include <vector>

enum e_color {
    NONE,
    WHITE = 2,
    BLACK
};

const int MAX_V = 30;

int vCnt;
int colors[MAX_V];
std::vector<int> edges[MAX_V];

bool dfs(int cur, int supposedToBe) {
    int &curColor = colors[cur];

    if (curColor != NONE) {
        return curColor == supposedToBe;
    }

    int nextColor = supposedToBe ^ 1;

    curColor = supposedToBe;
    for (const int &next : edges[cur]) {
        if (!dfs(next, nextColor)) {
            return false;
        }
    }
    return true;
}

int getAns() {
    int componentCnt = 0;

    for (int v = 0; v < vCnt; v++) {
        if (colors[v] != NONE) {
            continue;
        }

        if (!dfs(v, WHITE)) {
            return -1;
        }

        componentCnt++;
    }

    return 1 << componentCnt;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt-- > 0) {
        int eCnt;

        std::cin >> vCnt >> eCnt;
        for (int v = 0; v < vCnt; v++) {
            colors[v] = NONE;
            edges[v].clear();
        }
        while (eCnt-- > 0) {
            int a, b;

            std::cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        std::cout << getAns() << '\n';
    }
    return (0);
}
