#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000
#define ROOT 1

enum e_cmd {
    UPDATE = 1,
    SUM
};

int size;
long long arr[MAX_SIZE];
long long tree[3 * MAX_SIZE];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = arr[left];
        return;
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    init(leftChild, left, mid);
    init(rightChild, mid + 1, right);
    tree[node] = tree[leftChild] + tree[rightChild];
}

void update(int node, int index, long long newValue, int left, int right) {
    if (index < left || index > right) {
        return;
    }

    if (left == right) {
        tree[node] = arr[index] = newValue;
        return;
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    update(leftChild, index, newValue, left, mid);
    update(rightChild, index, newValue, mid + 1, right);
    tree[node] = tree[leftChild] + tree[rightChild];
}

long long sum(int node, int left, int right, int start, int end) {
    if (end < left || right < start) {
        return 0;
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    return sum(leftChild, left, mid, start, end)
            + sum(rightChild, mid + 1, right, start, end);
}

int main(void) {
    int changeCnt;
    int queryCnt;

    scanf(" %d %d %d", &size, &changeCnt, &queryCnt);
    for (int i = 0; i < size; i++) {
        scanf(" %lld", &arr[i]);
    }

    init(ROOT, 0, size - 1);
    queryCnt += changeCnt;
    while (queryCnt-- > 0) {
        int cmd;

        scanf(" %d", &cmd);
        if (cmd == UPDATE) {
            int index;
            long long newValue;

            scanf(" %d %lld", &index, &newValue);
            update(ROOT, index - 1, newValue, 0, size - 1);
        }
        else if (cmd == SUM) {
            int start;
            int end;

            scanf(" %d %d", &start, &end);
            printf("%lld\n", sum(ROOT, 0, size - 1, start - 1, end - 1));
        }
    }
    return (0);
}
