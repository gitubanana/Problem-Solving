#include <iostream>

const int MAX_V = 1e2 + 1;

int dists[MAX_V][MAX_V];

void floydWarshall(int vCnt) {
    for (int mid = 1; mid <= vCnt; mid++) {
        for (int from = 1; from <= vCnt; from++) {
            if (dists[from][mid] == 0) {
                continue;
            }

            for (int to = 1; to <= vCnt; to++) {
                if (dists[mid][to] == 0) {
                    continue;
                }

                int &cmpDist = dists[from][to];
                int nextDist = dists[from][mid] + dists[mid][to];
                if (cmpDist == 0 || cmpDist > nextDist) {
                    cmpDist = nextDist;
                }
            }
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt, qCnt;

    std::cin >> vCnt >> eCnt >> qCnt;
    for (int e = 0; e < eCnt; e++) {
        int a, b;

        std::cin >> a >> b >> dists[a][b];
        dists[b][a] = dists[a][b];
    }

    floydWarshall(vCnt);
    for (int q = 0; q < qCnt; q++) {
        int from, to;

        std::cin >> from >> to;
        std::cout << dists[from][to] << '\n';
    }
    return 0;
} 
