#include <stdio.h>
#include <vector>

const int MAX_V = 2 * 1e5 + 1;
const int START = 1;

int vCnt;
bool hasNut[MAX_V];
bool beenTo[MAX_V];
bool visited[MAX_V][2];
std::vector<int> edges[MAX_V];

void dfs(int cur, int prev, bool withNut=false) {
    if (visited[cur][withNut]) {
        return ;
    }

    visited[cur][withNut] = true;
    if (!withNut && !hasNut[cur]) {
        beenTo[cur] = true;
    }

    int nextCnt = 0;
    int pushNutInto;

    withNut |= hasNut[cur];
    for (const int &next : edges[cur]) {
        if (next == prev || (withNut && hasNut[next])) {
            continue;
        }

        ++nextCnt;
        pushNutInto = next;
        beenTo[cur] = true;
        dfs(next, cur, withNut);
    }

    if (!beenTo[cur]) {
        return;
    }

    for (const int &next : edges[cur]) {
        if (next == prev || (nextCnt == 1 && pushNutInto == next)) {
            continue;
        }

        dfs(next, cur);
    }
}

int main(void) {
    int nutCnt;

    fscanf(stdin, " %d %d", &vCnt, &nutCnt);
    for (int e = 1; e < vCnt; e++) {
        int a, b;

        fscanf(stdin, " %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < nutCnt; i++) {
        int v;

        fscanf(stdin, " %d", &v);
        hasNut[v] = true;
    }

    dfs(START, 0);

    int ans = 0;
    for (int v = 1; v <= vCnt; v++) {
        if (beenTo[v]) {
            ans++;
        }
    }
    fprintf(stdout, "%d\n", ans);
    return 0;
}
