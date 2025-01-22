#include <iostream>
#include <unordered_map>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1001;

int vCnt;
int size;
bool visited[MAX_V];
std::string words[MAX_V];

int getWeight(int a, int b) {
    int weight = 0;

    for (int i = 0; i < size; i++) {
        weight += std::abs(words[a][i] - words[b][i]);
    }
    return weight;
}

int prim(int start=1) {
    int madeEcnt = 0;
    int maxWeight = 0;
    std::priority_queue<t_edge> pq;

    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v]) {
            continue;
        }

        visited[cur.v] = true;
        maxWeight = std::max(maxWeight, cur.w);
        if (++madeEcnt == vCnt) {
            return maxWeight;
        }

        for (int next = 1; next <= vCnt; next++) {
            if (visited[next]) {
                continue;
            }

            pq.push({next, getWeight(cur.v, next)});
        }
    }

    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt >> size;
    for (int v = 1; v <= vCnt; v++) {
        std::string &curWord = words[v];

        std::cin >> curWord;
    }

    std::cout << prim() << '\n';
    return (0);
}
