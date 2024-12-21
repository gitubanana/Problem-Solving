#include <iostream>
#include <unordered_map>

using t_umap = std::unordered_map<std::string, std::string>;

t_umap umap;

std::string makeAns(std::string str) {
    std::string ans;

    for (int start = 0; start < str.size(); start++) {
        for (int end = start + 1; end <= str.size(); end++) {
            char saved = str[end];

            str[end] = 0;
            t_umap::iterator it = umap.find(&str[start]);
            if (it != umap.end()) {
                ans.append(it->second);
            }
            str[end] = saved;
        }
    }
    return (ans.empty() ? "-1" : ans);
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int qCnt;
    int wordCnt;

    std::cin >> wordCnt >> qCnt;
    while (wordCnt-- > 0) {
        std::string key, value;

        std::cin >> key >> value;
        umap[key] = value;
    }

    while (qCnt-- > 0) {
        std::string str;

        std::cin >> str;
        std::cout << makeAns(str) << '\n';
    }

    return 0;
}
