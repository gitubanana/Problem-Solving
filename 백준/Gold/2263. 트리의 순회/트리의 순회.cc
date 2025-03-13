// 풀이방법을 참고했습니다.
// 후위순회(postorder)
//    왼쪽 서브트리 - 오른쪽 서브트리 - 부모
// 중위순회(inorder)
//    왼쪽 서브트리 - 부모 - 오른쪽 서브트리

// 후위순회를 통해서, 부모를 찾고
// 중위순회를 통해서, 왼쪽 서브트리와 오른쪽 서브트리의 크기를 찾는 걸 반복한다.

#include <stdio.h>

enum e_idx {
    IN,
    POST
};

const int MAX_V = 1e5;

int vCnt;
int inOrderIndex[MAX_V + 1];
int orders[2][MAX_V];

void preOrder(int postLeft, int postRight, int inLeft, int inRight) {
    if (postLeft > postRight) {
        return;
    }

    const int &root = orders[POST][postRight];
    int rootIndex = inOrderIndex[root];
    int leftTreeSize = rootIndex - inLeft;
    int rightTreeSize = inRight - rootIndex;    
    
    fprintf(stdout, "%d ", root);
    preOrder(postLeft, postLeft + leftTreeSize - 1, inLeft, inLeft + leftTreeSize - 1);
    preOrder(postRight - rightTreeSize, postRight - 1, inRight - rightTreeSize + 1, inRight);
}

int main(void) {
    fscanf(stdin, " %d", &vCnt);
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < vCnt; x++) {
            fscanf(stdin, " %d", &orders[y][x]);
        }
    }

    for (int i = 0; i < vCnt; i++) {
        inOrderIndex[orders[IN][i]] = i;
    }

    preOrder(0, vCnt - 1, 0, vCnt - 1);
    fprintf(stdout, "\n");
    return 0;
}
