#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1001;
const int INF = 1e9;

int id;
std::vector<Edge> edges[MAX_V];
std::unordered_map<std::string, int> nameIds;

inline void init(void) {
    id = 0;
    for (int v = 1; v <= nameIds.size(); v++) {
        edges[v].clear();
    }
    nameIds.clear();
}

const int &getIdOf(const std::string &name) {
    int &nameId = nameIds[name];
    if (nameId == 0) {
        nameId = ++id;
    }
    return nameId;
}

int dijkstra(int start, int end) {
    static int dists[MAX_V];
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= nameIds.size(); v++) {
        dists[v] = INF;
    }
    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.v == end) {
            return curDist;
        }

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 0; t < testCnt; t++) {
        int eCnt;
        std::string start, end;

        std::cin >> eCnt >> start >> end;
        for (int e = 0; e < eCnt; e++) {
            int w;
            std::string a, b;
            std::cin >> a >> b >> w;

            const int &aId = getIdOf(a);
            const int &bId = getIdOf(b);
            edges[aId].push_back({bId, w});
            edges[bId].push_back({aId, w});
        }

        std::cout << start << ' ' << end << ' ' << dijkstra(getIdOf(start), getIdOf(end)) << '\n';
        init();
    }
    return 0;
}
