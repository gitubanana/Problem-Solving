#include <stdio.h>
#include <vector>
#include <queue>

class Edge {
public:
    int v;
    int w;
};

const int MAX_V = 1e5 + 1;

int vCnt;
int indegree[MAX_V];
int startTime[MAX_V];
std::vector<Edge> edges[MAX_V];

void topologicalSort(void) {
    std::queue<int> q;

    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v]) {
            continue;
        }

        q.push(v);
    }

    while (!q.empty()) {
        const int cur = q.front();
        const int &curTime = startTime[cur];
        q.pop();

        for (const Edge &next : edges[cur]) {
            int &nextTime = startTime[next.v];

            nextTime = std::max(nextTime, curTime+next.w);
            if (--indegree[next.v] == 0) {
                q.push(next.v);
            }
        }
    }
}

int main(void) {
    int maxTime, eCnt;

    fscanf(stdin, " %d %d %d", &vCnt, &maxTime, &eCnt);
    for (int v = 1; v <= vCnt; v++) {
        fscanf(stdin, " %d", &startTime[v]);
    }
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
        indegree[to]++;
    }

    topologicalSort();

    for (int v = 1; v <= vCnt; v++) {
        fprintf(stdout, "%d\n", startTime[v]);
    }
    return 0;
}
