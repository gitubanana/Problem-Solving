#include <iostream>
#include <string>

// maxDepth가 홀수 -> 루트가 AND
// maxDepth가 짝수 -> 루트가 OR
int calculateMaxDepth(const std::string &str) {
    int maxDepth = 0;
    int curDepth = 0;

    for (int i = 0; i < str.size(); i++) {
        switch (str[i])
        {
        case '(':
            maxDepth = std::max(maxDepth, ++curDepth);
            break;
        case ')':
            --curDepth;
            break;
        }
    }
    return maxDepth;
}

inline bool logicalOperation(bool a, bool isAnd, bool b) {
    return isAnd ? (a & b) : (a | b);
}

bool andOrTree(const std::string &str, int &i, bool isAnd) {
    bool result = (isAnd ? true : false);
    bool nextIsAnd = !isAnd;

    while (str[++i] != ')') {
        switch (str[i])
        {
        case 'T':
            result = logicalOperation(result, isAnd, true);
            break;
        case 'F':
            result = logicalOperation(result, isAnd, false);
            break;
        case '(':
            result = logicalOperation(result, isAnd, andOrTree(str, i, nextIsAnd));
        }
    }
    return result;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    // bool을 문자열로 출력하게 설정 (std::noboolalpha로 재설정하지 않는 이상, 유지)
    std::cout << std::boolalpha;
    for (int t = 1; ; t++) {
        std::string str;

        std::cin >> str;
        if (str == "()") {
            break;
        }

        int i = 0;

        std::cout << t << ". "
                    << andOrTree(str, i, calculateMaxDepth(str) & 1)
                    << '\n';
    }
    return 0;
}
