#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll goal;

template <typename T>
inline void swap(T &a, T &b) {
    T tmp = a;

    a = b;
    b = tmp;
}

void hanoi(int n, char from='A', char via='B', char to='C') {
    ll left = 1;
    ll right = (1LL << n) - 1;

    do {
        ll mid = (left + right) / 2;

        if (goal == mid) {
            printf("%d %c %c\n", n, from, to);
            return;
        }

        if (goal < mid) {
            right = mid - 1;
            swap(via, to);
        } else {
            left = mid + 1;
            swap(from, via);
        }
    } while (n--);
}

int main(void) {
    for (int t = 1; ; t++) {
        int n;
    
        scanf(" %lld %d", &goal, &n);
        if (n == 0) {
            break;
        }

        printf("Case %d: ", t);
        hanoi(n);
    }
    return 0;
}
