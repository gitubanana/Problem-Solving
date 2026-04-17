#include <iostream>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    int *prefixSum = new int[size+1];
    for (int i = 1; i <= size; i++) {
        std::cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i-1];
    }

    int cmp = 0;
    int ans = 0;
    for (int i = 1; i <= size; i++) {
        int tmp;

        std::cin >> tmp;
        cmp += tmp;
        if (cmp == prefixSum[i]) {
            ans = i;
        }
    }

    std::cout << ans << '\n';
    delete[] prefixSum;
    return 0;
}