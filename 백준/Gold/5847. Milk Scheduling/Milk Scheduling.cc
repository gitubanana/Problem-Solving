#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_V = 1e4 + 1;

int vCnt;
int prevMax[MAX_V];
int milkTime[MAX_V];
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

void topologicalSort(void) {
    std::queue<int> q;

    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v]) {
            continue;
        }
        q.push(v);
    }

    int ans = 0;
    while (!q.empty()) {
        const int cur = q.front();
        const int curTime = milkTime[cur] + prevMax[cur];
        q.pop();
    
        ans = std::max(ans, curTime);
        for (const int &next : edges[cur]) {
            prevMax[next] = std::max(prevMax[next], curTime);
            if (--indegree[next]) {
                continue;
            }

            q.push(next);
        }
    }

    printf("%d\n", ans);
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int v = 1; v <= vCnt; v++) {
        scanf(" %d", &milkTime[v]);
    }
    for (int e = 0; e < eCnt; e++) {
        int from, to;

        scanf(" %d %d", &from, &to);
        indegree[to]++;
        edges[from].push_back(to);
    }

    topologicalSort();
    return 0;
}
