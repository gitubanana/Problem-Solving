#include <iostream>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int pos;
    int carCnt, carSize;

    std::cin >> pos >> carCnt >> carSize;
    std::cout << ((carCnt * carSize >= pos) ? "yes" : "no"); 
    return 0;
}