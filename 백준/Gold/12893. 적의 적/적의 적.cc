#include <iostream>
#include <vector>

enum e_status {
    UNMARKED = 0,
    FRIEND = 2,
    ENEMY = 3
};

const int MAX_V = 2000 + 1;

int status[MAX_V];
std::vector<int> edges[MAX_V];

int dfs(int cur, int supposedToBe) {
    if (status[cur] != UNMARKED) {
        return (status[cur] == supposedToBe);
    }

    status[cur] = supposedToBe;
    for (const int &next : edges[cur]) {
        if (!dfs(next, supposedToBe ^ 1)) {
            return 0;
        }
    }
    return 1;
}

int getAns(int vCnt) {
    for (int v = 1; v <= vCnt; v++) {
        if (status[v] != UNMARKED) {
            continue;
        }

        if (!dfs(v, FRIEND)) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt-- > 0) {
        int a, b;

        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    std::cout << getAns(vCnt) << '\n';
    return 0;
}
