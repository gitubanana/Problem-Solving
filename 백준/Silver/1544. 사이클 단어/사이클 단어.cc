#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

void rotate(std::string &str) {
    char first = str[0];

    for (int i = 1; i < str.size(); i++) {
        str[i - 1] = str[i];
    }
    str[str.size() - 1] = first;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    int wordCnt;
    std::string word;
    std::unordered_set<std::string> alreadyCounted;

    std::cin >> wordCnt;
    while (wordCnt-- > 0) {
        bool counted = false;
        std::cin >> word;

        for (int i = word.size(); i >= 1; i--) {
            if (alreadyCounted.find(word) != alreadyCounted.end()) {
                counted = true;
                break;
            }
            rotate(word);
        }

        if (!counted) {
            ans++;
            alreadyCounted.insert(word);
        }
    }

    std::cout << ans << '\n';
    return (0);
}
