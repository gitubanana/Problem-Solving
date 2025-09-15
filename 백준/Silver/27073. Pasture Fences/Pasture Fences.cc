#include <stdio.h>
#include <math.h>

int main(void) {
    int size;
    scanf(" %d", &size);

    int *prefixSum = new int[size + 1];
    for (int i = 1; i <= size; i++) {
        scanf(" %d", &prefixSum[i]);
        prefixSum[i] += prefixSum[i - 1];
    }

    int minS;
    int minE;
    int minAbs = (static_cast<long long>(1) << 31) - 1;
    for (int s = 1; s <= size; s++) {
        for (int e = s; e <= size; e++) {
            int cmp = abs(prefixSum[e] - prefixSum[s - 1]);
            if (minAbs > cmp) {
                minAbs = cmp;
                minS = s;
                minE = e;
            } else if (minAbs == cmp && minE - minS < e - s) {
                minS = s;
                minE = e;
            }
        }
    }

    printf("%d %d %d\n", minS, minE, minAbs);
    delete[] prefixSum;
    return 0;
}
