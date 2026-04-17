#include <stdio.h>
#include <string.h>

// 아래 사이트를 참고해서 풀었습니다.
// https://gsmesie692.tistory.com/113?category=523232

const int KNAPSACK_SIZE = 100 + 1;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int size;
    scanf(" %d", &size);

    int *weights = new int[size + 1];
    for (int i = 1; i <= size; i++) {
        scanf(" %d", &weights[i]);
    }

    int *values = new int[size + 1];
    for (int i = 1; i <= size; i++) {
        scanf(" %d", &values[i]);
    }

    // dp[i][w] : i개의 물건, 배낭의 용량이 w일 때의 최적 이익
    int **dp = new int*[size + 1];
    for (int i = 0; i <= size; i++) {
        dp[i] = new int[KNAPSACK_SIZE];
        memset(dp[i], 0, sizeof(int) * KNAPSACK_SIZE);
    }

    for (int i = 1; i <= size; i++) {
        for (int w = 1; w < KNAPSACK_SIZE; w++) {
            if (w >= weights[i]) { // 물건을 넣을 수 있음
                dp[i][w] = max(dp[i-1][w], values[i]+dp[i-1][w-weights[i]]);
            } else { // 물건을 넣을 수 없음
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("%d\n", dp[size][99]);

    for (int i = 0; i <= size; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] weights;
    delete[] values;
    return 0;
}
