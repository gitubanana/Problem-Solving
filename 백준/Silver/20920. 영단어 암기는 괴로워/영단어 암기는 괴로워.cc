#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define EMPTY 0

struct t_word
{
    std::string str;
    int freq;

    inline bool operator<(const t_word &other) const
    {
        if (this->freq != other.freq)
            return (this->freq > other.freq);

        if (this->str.size() != other.str.size())
            return (this->str.size() > other.str.size());

        return (this->str < other.str);
    }
};

std::unordered_map<std::string, int> strToInt;
std::vector<t_word> words;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    int wordCnt, wordLen;

    std::cin >> wordCnt >> wordLen;
    while (wordCnt--)
    {
        std::cin >> str;
        if (str.size() < wordLen)
            continue ;

        int &idx = strToInt[str];
        if (idx == EMPTY)
        {
            words.push_back({str, 0});
            idx = words.size();
        }

        ++words[idx - 1].freq;
    }

    std::sort(words.begin(), words.end());
    for (const t_word &word : words)
    {
        std::cout << word.str << '\n';
    }
    return (0);
}
