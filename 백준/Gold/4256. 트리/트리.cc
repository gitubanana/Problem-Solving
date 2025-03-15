#include <stdio.h>

enum e_idx {
    PRE,
    IN
};

const int V_CNT = 1000;
const int MAX_V = V_CNT + 1;

int vCnt;
int orders[2][V_CNT];
int inOrderIndex[MAX_V];

void postOrder(int preLeft, int preRight, int inLeft, int inRight) {
    if (preLeft > preRight) {
        return;
    }

    const int &root = orders[PRE][preLeft];
    const int &rootIndex = inOrderIndex[root];
    const int leftTreeSize = rootIndex - inLeft;
    const int rightTreeSize = inRight - rootIndex;

    postOrder(preLeft + 1, preLeft + leftTreeSize, inLeft, inLeft + leftTreeSize - 1);
    postOrder(preRight - rightTreeSize + 1, preRight, inRight - rightTreeSize + 1, inRight);
    fprintf(stdout, "%d ", root);
}

int main(void) {
    int testCnt;

    fscanf(stdin, " %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        fscanf(stdin, " %d", &vCnt);
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < vCnt; x++) {
                fscanf(stdin, " %d", &orders[y][x]);
            }
        }

        for (int x = 0; x < vCnt; x++) {
            inOrderIndex[orders[IN][x]] = x;
        }

        postOrder(0, vCnt - 1, 0, vCnt - 1);
        fprintf(stdout, "\n");
    }
    return 0;
}
