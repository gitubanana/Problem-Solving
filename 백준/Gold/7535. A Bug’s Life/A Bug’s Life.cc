#include <iostream>
#include <vector>

const int MAX_V = 2001;

int vCnt;
int eCnt;
bool isMale[MAX_V];
bool visited[MAX_V];
std::vector<int> edges[MAX_V];

inline void init() {
    for (int v = 1; v <= vCnt; v++) {
        isMale[v] = visited[v] = false;
        edges[v].clear();
    }
}

inline void takeInput() {
    for (int e = 0; e < eCnt; e++) {
        int a, b;
    
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

bool searchHomoSexual(int cur, bool itIs=true) {
    isMale[cur] = itIs;
    visited[cur] = true;
    for (const int &next : edges[cur]) {
        if (visited[next]) {
            if (itIs == isMale[next]) {
                return true;
            }

            continue;
        }

        if (searchHomoSexual(next, !itIs)) {
            return true;
        }
    }
    return false;
}

bool isAllHeteroSexual() {
    for (int v = 1; v <= vCnt; v++) {
        if (visited[v]) {
            continue;
        }

        if (searchHomoSexual(v)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"Suspicious bugs found!", "No suspicious bugs found!"};

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; t++) {
        std::cin >> vCnt >> eCnt;
        init();
        takeInput();

        std::cout << "Scenario #" << t << ":\n";
        std::cout << msg[isAllHeteroSexual()] << '\n' << '\n';
    }
    return 0;
}
