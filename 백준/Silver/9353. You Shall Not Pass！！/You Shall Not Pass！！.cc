#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const int MAX_V = 1e4;

bool visited[MAX_V];
std::vector<int> edges[MAX_V];

int dfs(int cur) {
    int cnt = 1;

    visited[cur] = true;
    for (const int &next : edges[cur]) {
        if (visited[next]) {
            continue;
        }

        cnt += dfs(next);
    }
    return cnt;
}

int getMaxGandalf(int vCnt, int forestCnt) {
    std::priority_queue<int> pq;

    for (int v = 0; v < vCnt; v++) {
        if (visited[v]) {
            continue;
        }

        pq.push(dfs(v));
    }

    int maxGandalf = 0;

    while (!pq.empty() && forestCnt--) {
        maxGandalf += pq.top();
        pq.pop();
    }
    return maxGandalf;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt-- > 0) {
        int vCnt, eCnt, forestCnt;

        std::cin >> vCnt >> eCnt >> forestCnt;
        for (int v = 0; v < vCnt; v++) {
            edges[v].clear();
            visited[v] = false;
        }
        while (eCnt-- > 0) {
            int from, to;

            std::cin >> from >> to;
            edges[from].push_back(to);
            edges[to].push_back(from);
        }

        std::cout << getMaxGandalf(vCnt, forestCnt) << '\n';
    }
    return 0;
}
