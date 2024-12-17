#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 1000000
#define MAX_TREE_SIZE 2097152
#define ROOT 1

enum e_cmd {
    UPDATE = 1,
    QUERY
};

const int DIVISOR = 1e9 + 7;


int size;
int arr[MAX_SIZE];
long long tree[MAX_TREE_SIZE + 1];

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
    tree[node] = tree[leftChild] * tree[rightChild];
    tree[node] %= DIVISOR;
}

void update(int node, int index, int newValue, int left, int right) {
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
    tree[node] = tree[leftChild] * tree[rightChild];
    tree[node] %= DIVISOR;
}

long long mul(int node, int left, int right, int start, int end) {
    if (end < left || right < start) {
        return 1;
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    return mul(leftChild, left, mid, start, end)
            * mul(rightChild, mid + 1, right, start, end)
            % DIVISOR;
}

int main(void) {
    int add;
    int queryCnt;

    scanf(" %d %d %d", &size, &add, &queryCnt);
    for (int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }

    init(ROOT, 0, size - 1);
    queryCnt += add;
    while (queryCnt-- > 0) {
        int cmd;

        scanf(" %d", &cmd);
        if (cmd == UPDATE) {
            int index, newValue;

            scanf(" %d %d", &index, &newValue);
            update(ROOT, index - 1, newValue, 0, size - 1);
        } else if (cmd == QUERY) {
            int start, end;

            scanf(" %d %d", &start, &end);
            printf("%lld\n", mul(ROOT, 0, size - 1, start - 1, end - 1));
        }
    }
    return (0);
}
