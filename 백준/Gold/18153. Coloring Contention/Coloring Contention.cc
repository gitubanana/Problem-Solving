#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_V = 1e5 + 1;

int vCnt;
bool visited[MAX_V];
std::vector<int> edges[MAX_V];

int bfs(int start=1, int end=vCnt) {
    int dist = 0;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const int cur = q.front();
            q.pop();

            for (const int &next : edges[cur]) {
                if (visited[next]) {
                    continue;
                }

                if (next == end) {
                    return dist;
                }

                visited[next] = true;
                q.push(next);
            }
        }

        ++dist;
    } while (!q.empty());
    return -1;
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    printf("%d\n", bfs());
    return 0;
}
