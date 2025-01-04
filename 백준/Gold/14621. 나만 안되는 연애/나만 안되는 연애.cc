#include <iostream>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1000 + 1;
const int START = 1;

int vCnt;
bool type[MAX_V];
bool visited[MAX_V];
std::vector<t_edge> edges[MAX_V];

int prim() {
    int madeEcnt = 0;
    int totalWeight = 0;
    std::priority_queue<t_edge> pq;

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
            return totalWeight;
        }

        for (const t_edge &next : edges[cur.v]) {
            if (visited[next.v] || type[cur.v] == type[next.v]) {
                continue;
            }

            pq.push(next);
        }
    }
    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; v++) {
        char ch;

        std::cin >> ch;
        type[v] = (ch == 'M');
    }

    while (eCnt-- > 0) {
        int a, b, w;

        std::cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    std::cout << prim() << '\n';
    return 0;
}
