#include <iostream>

enum e_ch {
    OPEN = '(',
    CLOSE = ')'
};

int i = -1;
std::string str;

int countLength() {
    int length = 0;

    while (str[++i]) {
        switch (str[i])
        {
        case OPEN:
            length--;
            length += (str[i - 1] - '0') * countLength();
            break;
        case CLOSE:
            return length;
        default:
            length++;
            break;
        }
    }
    return length;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> str;
    std::cout << countLength() << '\n';
    return 0;
}
