#include <iostream>
#include <queue>
#include <vector>
#define EVER ;;

const int V_CNT = 8;

int indegree[V_CNT] = {
    0,
    1,
    0,
    0,
    2,
    1,
    0,
    1
};
std::vector<int> edges[V_CNT] = {
    {},
    {4, 7},
    {1},
    {4, 5},
};

void topologicalSort() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int v = 1; v < V_CNT; v++) {
        if (indegree[v]) {
            continue;
        }

        pq.push(v);
    }

    std::vector<int> order;

    order.reserve(V_CNT);
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

    if (order.size() != V_CNT - 1) {
        std::cout << "Cannot complete these tasks. Going to bed." << '\n';
        return ;
    }

    for (const int &v : order) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}


int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    for (EVER) {
        int from, to;

        std::cin >> from >> to;
        if (from == 0) {
            break;
        }

        indegree[to]++;
        edges[from].push_back(to);
    }

    topologicalSort();
    return 0;
}
