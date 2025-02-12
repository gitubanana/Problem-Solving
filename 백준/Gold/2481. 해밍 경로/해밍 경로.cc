#include <stdio.h>

#include <vector>

#include <queue>

#include <unordered_map>

const int MAX_V = 1e5 + 1;

const int START = 1;

int vCnt;

int bits[MAX_V];

int prevs[MAX_V];

std::vector<int> edges[MAX_V];

void bfs(int start) {

    std::queue<int> q;

    prevs[start] = -1;

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

    static std::vector<int> path;

    path.clear();

    while (cur != -1) {

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

    char num[31];

    std::unordered_map<int, int> idxByBits;

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

            int nextBit = bits[v] ^ (1 << i);

            std::unordered_map<int, int>::iterator it = idxByBits.find(nextBit);

            if (it == idxByBits.end()) {

                continue;

            }

            

            edges[v].push_back(it->second);

        }

    }

    bfs(START);

    int qCnt;

    scanf(" %d", &qCnt);

    while (qCnt-- > 0) {

        int end;

        scanf(" %d", &end);

        if (!prevs[end]) {

            printf("-1\n");

        } else {

            printPath(end);

        }

    }

    return 0;

}

