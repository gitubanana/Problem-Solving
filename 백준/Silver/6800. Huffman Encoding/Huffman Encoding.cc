#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, char> huffmanCode;

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    char ch;
    int codeCnt;
    std::string code;

    std::cin >> codeCnt;
    while (codeCnt-- > 0) {
        std::cin >> ch >> code;
        huffmanCode[code] = ch;
    }

    std::string str;
    std::string ans;

    code = "";
    std::cin >> str;
    for (const char &ch : str) {
        code += ch;
        if (huffmanCode.find(code) == huffmanCode.end()) {
            continue;
        }

        ans += huffmanCode[code];
        code.clear();
    }

    std::cout << ans << '\n';
    return (0);
}
