#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100000
#define MAX_TREE_SIZE 262144
#define ROOT 1

enum e_cmd {
    UPDATE = 1,
    SUM
};

typedef struct s_node {
    int max;
    int min;
} t_node;


int size;
int arr[MAX_SIZE];
t_node tree[MAX_TREE_SIZE + 1];

inline int getMax(int a, int b) {
    return a > b ? a : b;
}

inline int getMin(int a, int b) {
    return a > b ? b : a;
}

void init(int node, int left, int right) {
    if (left == right) {
        tree[node].max = tree[node].min = arr[left];
        return;
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    init(leftChild, left, mid);
    init(rightChild, mid + 1, right);
    tree[node].max = getMax(tree[leftChild].max, tree[rightChild].max);
    tree[node].min = getMin(tree[leftChild].min, tree[rightChild].min);
}

void update(int node, int index, int newValue, int left, int right) {
    if (index < left || index > right) {
        return;
    }

    if (left == right) {
        tree[node].max = tree[node].min = arr[index] = newValue;
        return;
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;

    update(leftChild, index, newValue, left, mid);
    update(rightChild, index, newValue, mid + 1, right);
    tree[node].max = getMax(tree[leftChild].max, tree[rightChild].max);
    tree[node].min = getMin(tree[leftChild].min, tree[rightChild].min);
}

t_node maxAndMin(int node, int left, int right, int start, int end) {
    if (end < left || right < start) {
        return {INT_MIN, INT_MAX};
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    int leftChild = node * 2;
    int rightChild = leftChild + 1;
    t_node leftNode = maxAndMin(leftChild, left, mid, start, end);
    t_node rightNode = maxAndMin(rightChild, mid + 1, right, start, end);

    return {
        getMax(leftNode.max, rightNode.max),
        getMin(leftNode.min, rightNode.min),
    };
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

        t_node node = maxAndMin(ROOT, 0, size - 1, start - 1, end - 1);
        printf("%d %d\n", node.min, node.max);
    }
    return (0);
}
