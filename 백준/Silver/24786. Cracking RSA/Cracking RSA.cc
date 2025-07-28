#include <stdio.h>

inline bool isPrime(int number) {
    if (number == 1)
        return false;

    for (int i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int findEuler(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (!isPrime(i)) {
            continue;
        }

        int quotient = n / i;
        if (i * quotient == n) {
            return (i - 1) * (quotient - 1);
        }
    }
    return -1;
}

int crackPrivateKey(int e, int mod) {
    for (int d = 2; d < mod; d++) {
        long long mul = static_cast<long long>(e) * d;
        if (mul % mod == 1) {
            return d;
        }
    }
    return -1;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int n, e;

        scanf(" %d %d", &n, &e);
        printf("%d\n", crackPrivateKey(e, findEuler(n)));
    }
    return 0;
} 
