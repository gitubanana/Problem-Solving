#include <stdio.h>

typedef enum {
    POSSIBLE,
    LEFT_HEAVY,
    RIGHT_HEAVY
} e_state;

const int MAX_WEIGHT = 2 * 1e5;
const int MAX_SIZE = 1e5;

int size;
int weights[MAX_SIZE];

e_state santaMissionState(int balance) {
    int sum[2] = {0, 0};

    for (int i = 0; i < size; i++) {
        const int &curWeight = weights[i];
        if (curWeight == balance) {
            continue;
        }

        sum[curWeight > balance] += curWeight;
    }

    if (sum[0] == sum[1]) {
        return POSSIBLE;
    }

    if (sum[0] > sum[1]) {
        return LEFT_HEAVY;
    }

    return RIGHT_HEAVY;
}

int binarySearch() {
    int left = 1;
    int right = MAX_WEIGHT;
    int min = -1;

    do {
        int mid = (left + right) / 2;
        switch (santaMissionState(mid)) {
            case RIGHT_HEAVY:
                left = mid + 1;
                break;
            case POSSIBLE: // switch fallthrough
                min = mid;
            case LEFT_HEAVY:
                right = mid - 1;
                break;
        }
    } while (left <= right);

    return min;
}

int main() {
    scanf(" %d", &size);
    for (int i = 0; i < size; i++) {
        scanf(" %d", &weights[i]);
    }

    printf("%d\n", binarySearch());
    return 0;
}