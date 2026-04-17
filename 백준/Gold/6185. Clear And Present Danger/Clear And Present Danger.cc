#include <stdio.h>
#include <vector>

const int MAX_V = 1e2 + 1;
const int INF = 1e9;

int vCnt;
int danger[MAX_V][MAX_V];

void floydWarshall() {
    for (int mid = 1; mid <= vCnt; mid++) {
        for (int from = 1; from <= vCnt; from++) {
            for (int to = 1; to <= vCnt; to++) {
                danger[from][to] = std::min(
                    danger[from][to],
                    danger[from][mid] + danger[mid][to]
                );
            }
        }
    }
}

int main(void) {
    int pathLength;
    scanf(" %d %d", &vCnt, &pathLength);

    std::vector<int> path(pathLength);
    for (int i = 0; i < pathLength; i++) {
        scanf(" %d", &path[i]);
    }

    for (int from = 1; from <= vCnt; from++) {
        for (int to = 1; to <= vCnt; to++) {
            scanf(" %d", &danger[from][to]);
        }
    }

    floydWarshall();

    int ans = 0;
    for (int i = 1; i < pathLength; i++) {
        ans += danger[path[i - 1]][path[i]];
    }

    printf("%d\n", ans);
    return 0;
}
