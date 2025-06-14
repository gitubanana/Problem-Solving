#include <iostream>
#include <cstring>
#include <vector>

const int MAX_V = 1001;

int vCnt;
int visited[MAX_V];
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

bool dfs(int cur, int youngest) {
    int &curVisited = visited[cur];
    if (curVisited == youngest) {
        return true;
    }

    curVisited = youngest;
    for (const int &next : edges[cur]) {
        if (dfs(next, youngest)) {
            return true;
        }
    }
    return false;
}

bool containsDiamondInheritance(void) {
    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v] != 0) {
            continue;
        }

        if (dfs(v, v)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"No", "Yes"};

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; t++) {
        std::cin >> vCnt;
        for (int from = 1; from <= vCnt; from++) {
            int toCnt;

            std::cin >> toCnt;
            edges[from].clear();
            for (int i = 0; i < toCnt; i++) {
                int to;

                std::cin >> to;
                indegree[to]++;
                edges[from].push_back(to);
            }
        }

        std::cout << "Case #" << t << ": " << msg[containsDiamondInheritance()] << '\n';
        memset(visited, 0, sizeof(visited));
        memset(indegree, 0, sizeof(indegree));
    }
    return 0;
}
