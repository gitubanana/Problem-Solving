#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll goal;
ll left, right;

void hanoi(int n, int from=1, int via=2, int to=3) {
    ll mid = (left + right) / 2;

    if (goal == mid) {
        printf("%d %d", from, to);
        exit(0);
    }

    if (goal < mid) {
        right = mid - 1;
        hanoi(n - 1, from, to, via);
    } else {
        left = mid + 1;
        hanoi(n - 1, via, from, to);
    }
}

int main(void) {
    int n;

    scanf(" %d %lld", &n, &goal);

    left = 1;
    right = ((ll)1 << n) - 1;
    hanoi(n);
    return 0;
}
