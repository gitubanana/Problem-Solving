#include <iostream>

const int MAX_V = 301;
const int INF = 1e9;

int heights[MAX_V][MAX_V];

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt, testCount;

    std::cin >> vCnt >> eCnt >> testCount;
    for (int from = 1; from <= vCnt; from++) {
        for (int to = 1; to <= vCnt; to++) {
            heights[from][to] = INF;
        }
    }

    while (eCnt-- > 0) {
        int from, to, h;
        std::cin >> from >> to >> h;

        int &cmpHeight = heights[from][to];
        cmpHeight = std::min(cmpHeight, h);
    }

    for (int mid = 1; mid <= vCnt; mid++) {
        for (int from = 1; from <= vCnt; from++) {
            for (int to = 1; to <= vCnt; to++) {
                const int &fromToMid = heights[from][mid];
                const int &midToTo = heights[mid][to];
                int &fromToTo = heights[from][to];

                if (fromToMid == INF || midToTo == INF) {
                    continue;
                }

                fromToTo = std::min(
                    fromToTo,
                    std::max(
                        fromToMid,
                        midToTo
                    )
                );
            }
        }
    }

    while (testCount-- > 0) {
        int from, to;
        std::cin >> from >> to;

        const int &h = heights[from][to];
        std::cout << (h == INF ? -1 : h) << '\n';
    }
    return 0;
}
