#include <stdio.h>
#include <vector>

const int MAX_V = 1e4 + 1;
const int PAID = 1 << 31; // overflow

int vCnt;
int money[MAX_V];
std::vector<int> edges[MAX_V];

int dfs(int cur) {
    int ret = money[cur];

    money[cur] = PAID;
    for (const int &next : edges[cur]) {
        if (money[next] == PAID) {
            continue;
        }

        ret += dfs(next);
    }
    return ret;
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int v = 0; v < vCnt; v++) {
        scanf(" %d", &money[v]);
    }
    for (int e = 0; e < eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }


    int idx = 1;
    const char *msg[] = {"IMPOSSIBLE", "POSSIBLE"};

    for (int v = 0; v < vCnt; v++) {
        if (money[v] == PAID) {
            continue;
        }

        if (dfs(v) != 0) {
            idx = 0;
            break;
        }
    }

    printf("%s\n", msg[idx]);
    return 0;
}
