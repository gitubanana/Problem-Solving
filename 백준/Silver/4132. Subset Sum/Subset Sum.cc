#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>

const int MAX_SIZE = 20;

typedef long long ll;

ll ans = __INT_MAX__;
ll goal;
int size;
ll arr[MAX_SIZE];
std::unordered_set<ll> visited;

void backTracking(ll cur=0, int depth=0) {
    if (depth == size) {
        if (cur >= goal) {
            ans = std::min(ans, cur);
        }
        return;
    }

    int nextDepth = depth + 1;

    backTracking(cur, nextDepth);
    backTracking(cur + arr[depth], nextDepth);
}

int main(void) {
    fscanf(stdin, " %lld %d", &goal, &size);
    for (int i = 0; i < size; i++) {
        fscanf(stdin, " %lld", &arr[i]);
    }

    backTracking();
    if (ans >= goal) {
        fprintf(stdout, "%lld\n", ans);
    } else {
        fprintf(stdout, "IMPOSSIBLE\n");
    }
    return 0;
}
