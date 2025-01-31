#include <iostream>

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt-- > 0) {
        int playerCnt;
        int maxPrice = -1;
        std::string maxPlayer;

        std::cin >> playerCnt;
        while (playerCnt-- > 0) {
            int cmpPrice;
            std::string player;

            std::cin >> cmpPrice >> player;
            if (maxPrice < cmpPrice) {
                maxPrice = cmpPrice;
                maxPlayer = player;
            }
        }

        std::cout << maxPlayer << '\n';
    }

    return 0;
}
