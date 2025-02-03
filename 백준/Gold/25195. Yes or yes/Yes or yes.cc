#include <stdio.h>
#include <vector>

const int MAX_V = 1e5 + 1;
const int START = 1;

int vCnt;
bool isFan[MAX_V];
std::vector<int> edges[MAX_V];

bool canAvoidFans(int cur=START) {
    if (isFan[cur]) {
        return false;
    }

    for (const int &next : edges[cur]) {
        if (canAvoidFans(next)) {
            return true;
        }
    }
    return edges[cur].empty();
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    while (eCnt-- > 0) {
        int from, to;

        fscanf(stdin, " %d %d", &from, &to);
        edges[from].push_back(to);
    }

    int fanCnt;

    fscanf(stdin, " %d", &fanCnt);
    while (fanCnt-- > 0) {
        int pos;

        fscanf(stdin, " %d", &pos);
        isFan[pos] = true;
    }

    const char *msg[] = {"Yes", "yes"};

    fprintf(stdout, "%s\n", msg[canAvoidFans()]);
    return 0;
}