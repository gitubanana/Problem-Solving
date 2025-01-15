#include <iostream>
#include <regex>

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string str;
    const char *msg[] = {"NO", "YES"};
    std::regex regex("((100+1+)|(01))+");

    std::cin >> testCnt;
    while (testCnt-- > 0) {
        std::cin >> str;
        std::cout << msg[std::regex_match(str, regex)] << '\n';
    }
    return (0);
}
