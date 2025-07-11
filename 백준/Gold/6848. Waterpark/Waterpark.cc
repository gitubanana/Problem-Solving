#include <stdio.h>
#include <vector>
#define END vCnt
#define EVER ;;

const int MAX_V = 10000;
const int START = 1;
const int NOT_VISITED = -1;

int vCnt;
int dp[MAX_V];
std::vector<int> edges[MAX_V];

int dfs(int cur=START) {
    if (cur == END)
        return 1;

    int &curDp = dp[cur];
    if (curDp != NOT_VISITED)
        return curDp;

    curDp = 0;
    for (const int &next : edges[cur]) {
        curDp += dfs(next);
    }
    return curDp;
}

int main(void) {
    scanf(" %d", &vCnt);
    for (EVER) {
        int from, to;

        scanf(" %d %d", &from, &to);
        if (from == 0) {
            break;
        }

        edges[from].push_back(to);
    }

    for (int v = 1; v <= vCnt; v++) {
        dp[v] = NOT_VISITED;
    }
    printf("%d\n", dfs());
    return 0;
}
