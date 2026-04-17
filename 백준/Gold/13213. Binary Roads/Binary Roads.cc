#include <stdio.h>
#include <vector>
#include <queue>

class Edge {
public:
    int v;
    bool key;
};

const int MAX_V = 2e5;
const int KEY_CNT = 2;

int vCnt;
bool visited[MAX_V][KEY_CNT];
std::vector<Edge> edges[MAX_V];

int bfs(int start=0, int end=vCnt-1) {
    if (start == end) {
        return 0;
    }

    int dist = 1;
    std::queue<Edge> q;

    for (int k = 0; k < KEY_CNT; k++) {
        visited[start][k] = true;
        q.push({start, static_cast<bool>(k)});
    }

    do {
        for (int qSize = q.size(); qSize--; ) {
            const Edge cur = q.front();
            q.pop();
    
            for (const Edge &next : edges[cur.v]) {
                if (next.key != cur.key || visited[next.v][!cur.key]) {
                    continue;
                }

                if (next.v == end) {
                    return dist;
                }

                visited[next.v][!cur.key] = true;
                q.push({next.v, !cur.key});
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
        int a, b, key;

        scanf(" %d %d %d", &a, &b, &key);
        edges[a].push_back({b, static_cast<bool>(key)});
        edges[b].push_back({a, static_cast<bool>(key)});
    }

    printf("%d\n", bfs());
    return 0;
}
