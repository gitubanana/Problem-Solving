#include <iostream>
#include <algorithm>
#include <unordered_set>

using t_uset = std::unordered_set<std::string>;

inline bool isPalindrome(const std::string &str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return (false);
        }

        ++start, --end;
    }
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int strCnt;
    t_uset uset;
    std::string str;

    std::cin >> strCnt;
    while (strCnt--)
    {
        std::cin >> str;

        if (uset.find(str) != uset.end()
            || isPalindrome(str))
        {
            std::cout << str.size() << ' ' << str[str.size() / 2] << '\n';
            break ;
        }
        else
        {
            std::reverse(str.begin(), str.end());
            uset.insert(str);
        }
    }
    return (0);
}
