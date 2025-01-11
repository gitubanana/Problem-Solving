#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_V = 100 + 1;

enum e_color {
    NONE,
    WHITE = 2,
    BLUE,
    COLOR_CNT
};

int vCnt;
char colors[MAX_V];
std::vector<int> edges[MAX_V];
std::vector<int> teams[COLOR_CNT];

void dfs(int cur, int supposedToBe) {
    if (colors[cur] != NONE) {
        return;
    }

    int nextColor = supposedToBe ^ 1;

    colors[cur] = supposedToBe;
    teams[supposedToBe].push_back(cur);
    for (const int &next : edges[cur]) {
        dfs(next, nextColor);
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int from = 1; from <= vCnt; from++) {
        int toCnt;

        std::cin >> toCnt;
        while (toCnt-- > 0) {
            int to;

            std::cin >> to;
            edges[from].push_back(to);
        }
    }

    for (int v = 1; v <= vCnt; v++) {
        dfs(v, WHITE);
    }

    for (int color = WHITE; color <= BLUE; color++) {
        std::vector<int> &team = teams[color];

        std::cout << team.size() << '\n';
        std::sort(team.begin(), team.end());
        for (const int &v : team) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }
    return (0);
}
