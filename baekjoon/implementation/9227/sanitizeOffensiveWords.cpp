#include <iostream>
#include <unordered_set>

template <typename T>
using t_uset = std::unordered_set<T>;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_uset<std::string> offensiveWords;

    while (true)
    {
        std::string str;

        std::cin >> str;
        if (str[0] == '#')
            break ;

        offensiveWords.insert(str);
    }

    while (true)
    {
        std::string str;
        do
        {
            std::getline(std::cin, str);
        } while (str == "");

        if (str == "#")
            break ;

        int s = 0;
        int e = s + 3;
        char check[3] = "";
        while (e < str.size())
        {
            check[0] = str[s];
            check[1] = str[e];
            if (offensiveWords.find(check) != offensiveWords.end())
            {
                str[s + 1] = str[s + 2] = '*';
                s = e + 1;
                e = s + 3;
            }
            else
            {
                ++s, ++e;
            }
        }

        std::cout << str << '\n';
    }
    return (0);
}
