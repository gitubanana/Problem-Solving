#include <stdio.h>
#include <algorithm>
#include <vector>

enum e_color {
    NONE,
    WHITE = 0b10,
    BLACK = 0b11
};

const int MAX_V = 1e5 + 1;

int vCnt;
int eCnt;
int whiteCnt, blackCnt;
int color[MAX_V];
std::vector<int> edges[MAX_V];

void dfs(int cur, int curColor=WHITE) {
    if (curColor == WHITE) {
        whiteCnt++;
    } else {
        blackCnt++;
    }

    color[cur] = curColor;
    for (const int &next : edges[cur]) {
        if (color[next] != NONE) {
            continue;
        }

        dfs(next, curColor ^ 1);
    }
}

int countPairs(void) {
    int pair = vCnt / 2;

    if (whiteCnt + blackCnt == vCnt && whiteCnt * blackCnt == eCnt && (whiteCnt & 1)) {
        pair--;
    }
    return pair;
}

int main(void) {
    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    if (vCnt & 1) {
        fprintf(stdout, "%d\n", vCnt / 2);
        return 0;
    }

    for (int e = 0; e < eCnt; e++) {
        int a, b;

        fscanf(stdin, " %d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);
    fprintf(stdout, "%d\n", countPairs());
    return 0;
}
