#include <iostream>
#include <queue>
#include <vector>

const int MAX_V = 1e5;

int vCnt;
bool visited[MAX_V];
std::vector<int> edges[MAX_V];

int bfs(int start, int end) {
    int dist = 0;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        for (int qSize = q.size(); qSize--; ) {
            const int cur = q.front();
            q.pop();

            for (const int &next : edges[cur]) {
                if (next == end) {
                    return dist;
                }

                visited[next] = true;
                q.push(next);
            }
        }

        ++dist;
    }
    
    return -1;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int i = 0; i < vCnt; i++) {
        int from, toCnt;

        std::cin >> from >> toCnt;
        for (int i = 0; i < toCnt; i++) {
            int to;

            std::cin >> to;
            edges[from].push_back(to);
        }
    }

    int start, end;

    std::cin >> start >> end;
    std::cout << start << ' ' << end << ' ' << bfs(start, end);
    return 0;
}