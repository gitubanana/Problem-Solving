#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 26 + 1;
const int START = 0;

int vCnt;
bool visited[MAX_V];
std::vector<t_edge> edges[MAX_V];

int prim() {
    int madeEcnt = 0;
    int totalWeight = 0;
    std::priority_queue<t_edge> pq;

    memset(visited, false, sizeof(visited));
    pq.push({START, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v]) {
            continue;
        }

        visited[cur.v] = true;
        totalWeight += cur.w;
        if (++madeEcnt == vCnt) {
            break;
        }

        for (const t_edge &next : edges[cur.v]) {
            if (visited[next.v]) {
                continue;
            }

            pq.push(next);
        }
    }
    return totalWeight;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    while (true) {
        std::cin >> vCnt;
        if (vCnt == 0) {
            break;
        }

        for (int v = 0; v < vCnt; v++) {
            edges[v].clear();
        }

        for (int v = 1; v < vCnt; v++) {
            int toCnt;
            char fromCh;
            std::cin >> fromCh >> toCnt;

            int from = fromCh - 'A';
            while (toCnt-- > 0) {
                char toCh;
                int w;
                std::cin >> toCh >> w;

                int to = toCh - 'A';
                edges[from].push_back({to, w});
                edges[to].push_back({from, w});
            }
        }

        std::cout << prim() << '\n';
    }
    return 0;
}
