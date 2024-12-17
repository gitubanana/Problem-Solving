#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

enum e_cmd {
    UPDATE = 1,
    QUERY
};

const int ROOT = 1;
const int MAX_SIZE = 100'000;
const int MAX_TREE_SIZE = (1 << (static_cast<int>(ceil(log2(MAX_SIZE))) + 1));
const int DIVISOR = 1e9 + 7;

int size;
int arr[MAX_SIZE];
int tree[MAX_TREE_SIZE + 1];

inline int getMin(int a, int b) {
    return a > b ? b : a;
}

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
    tree[node] = getMin(tree[leftChild], tree[rightChild]);
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
    tree[node] = getMin(tree[leftChild], tree[rightChild]);
}

int min(int node, int left, int right, int start, int end) {
    if (end < left || right < start) {
        return INT_MAX;
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    return getMin(
        min(leftChild, left, mid, start, end),
        min(rightChild, mid + 1, right, start, end)
    );
}

int main(void) {
    int queryCnt;

    scanf(" %d %d", &size, &queryCnt);
    for (int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }

    init(ROOT, 0, size - 1);
    while (queryCnt-- > 0) {
        int start, end;

        scanf(" %d %d", &start, &end);
        printf("%d\n", min(ROOT, 0, size - 1, start - 1, end - 1));
    }
    return (0);
}
