#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#define MIN(a, b) (a) > (b) ? (b) : (a)
#define MAX_SIZE 100000
#define ROOT 1

enum e_cmd {
    UPDATE = 1,
    SUM
};


int size;
int arr[MAX_SIZE];
int tree[3 * MAX_SIZE];

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
    tree[node] = MIN(tree[leftChild], tree[rightChild]);
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
    tree[node] = MIN(tree[leftChild], tree[rightChild]);
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
    int leftMin = min(leftChild, left, mid, start, end);
    int rightMin = min(rightChild, mid + 1, right, start, end);

    return MIN(leftMin, rightMin);
}

int main(void) {
    int queryCnt;

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }

    scanf(" %d", &queryCnt);
    init(ROOT, 0, size - 1);
    while (queryCnt-- > 0) {
        int cmd;

        scanf(" %d", &cmd);
        if (cmd == UPDATE) {
            int index;
            int newValue;

            scanf(" %d %d", &index, &newValue);
            update(ROOT, index - 1, newValue, 0, size - 1);
        }
        else if (cmd == SUM) {
            int start;
            int end;

            scanf(" %d %d", &start, &end);
            printf("%d\n", min(ROOT, 0, size - 1, start - 1, end - 1));
        }
    }
    return (0);
}
