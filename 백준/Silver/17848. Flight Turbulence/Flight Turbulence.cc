#include <stdio.h>

const int MAX_V = 201;
const int VISITED = -1;

int vCnt;
int edge[MAX_V];

int changeSeat(int cur) {
    int next = edge[cur];
    if (next == VISITED || next == cur) {
        return 0;
    }

    edge[cur] = VISITED;
    return 1 + changeSeat(next);
}

int main(void) {
    int start;

    fscanf(stdin, " %d %d", &vCnt, &start);
    for (int v = 1; v <= vCnt; v++) {
        fscanf(stdin, " %d", &edge[v]);
    }

    fprintf(stdout, "%d\n", changeSeat(start));
    return 0;
}
