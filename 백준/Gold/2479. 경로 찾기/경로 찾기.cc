#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

using t_map = std::map<int, int>;

const int MAX_BIT = 30 + 1;
const int MAX_V = 1e4 + 1;
const int PATH_END = -1;

int vCnt;
int bits[MAX_V];
int prevs[MAX_V];
std::vector<int> edges[MAX_V];

void bfs(int start) {
    std::queue<int> q;

    prevs[start] = PATH_END;
    q.push(start);
    while (!q.empty()) {
        const int cur = q.front();
        q.pop();

        for (const int &next : edges[cur]) {
            if (prevs[next])  {
                continue;
            }

            prevs[next] = cur;
            q.push(next);
        }
    }
}

void printPath(int cur) {
    static std::vector<int> path(vCnt);

    path.clear();
    while (cur != PATH_END) {
        path.push_back(cur);
        cur = prevs[cur];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main(void) {
    int bitCnt;
    char num[MAX_BIT];
    t_map idxByBits;

    scanf(" %d %d", &vCnt, &bitCnt);
    for (int v = 1; v <= vCnt; v++) {
        int &curBit = bits[v];

        scanf(" %s", num);
        for (int i = 0; i < bitCnt; i++) {
            curBit <<= 1;
            curBit |= (num[i] == '1');
        }

        idxByBits[curBit] = v;
    }

    for (int v = 1; v <= vCnt; v++) {
        for (int i = 0; i < bitCnt; i++) {
            int nextBit = bits[v] ^ 1 << i;
            t_map::iterator it = idxByBits.lower_bound(nextBit);
            if (it == idxByBits.end() || bits[it->second] != nextBit) {
                continue;
            }

            edges[v].push_back(it->second);
        }
    }

    int start, end;

    scanf(" %d %d", &start, &end);
    bfs(start);
    if (prevs[end]) {
        printPath(end);
    } else {
        printf("-1\n");
    }
    return 0;
}
