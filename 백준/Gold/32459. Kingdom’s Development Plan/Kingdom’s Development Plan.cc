#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_V = 1e5 + 1;

int vCnt;
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

void topologicalSort(void) {
    std::vector<int> order;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v]) {
            continue;
        }

        pq.push(v);
    }

    while (!pq.empty()) {
        const int cur = pq.top();
        pq.pop();

        order.push_back(cur);
        for (const int &next : edges[cur]) {
            if (--indegree[next]) {
                continue;
            }

            pq.push(next);
        }
    }

    if (order.size() != vCnt) {
        fprintf(stdout, "IMPOSSIBLE\n");
        return;
    }

    for (const int &v : order) {
        fprintf(stdout, "%d ", v);
    }
    fprintf(stdout, "\n");
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to;

        fscanf(stdin, " %d %d", &from, &to);
        indegree[to]++;
        edges[from].push_back(to);
    }

    topologicalSort();
    return 0;
}
