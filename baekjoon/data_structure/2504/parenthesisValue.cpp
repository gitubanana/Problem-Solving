#include <iostream>
#include <unordered_map>

std::unordered_map<char, int> plScore;
std::unordered_map<char, char> plPair;

int ans;
std::string str;

int getPlScore(int &idx)
{
    int mul = 0;
    const int &curScore = plScore[str[idx]];
    const char &curPair = plPair[str[idx]];

    if (str[idx + 1] == curPair)
    {
        ++idx;
        return curScore;
    }

    while (str[idx])
    {
        if (str[++idx] == '(' || str[idx] == '[')
        {
            mul += getPlScore(idx);
        }
        else if (str[idx] == curPair)
        {
            break ;
        }
        else
        {
            throw std::exception();
        }
    }
    return (mul * curScore);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    plScore.insert({'(', 2});
    plScore.insert({'[', 3});
    plPair.insert({'(', ')'});
    plPair.insert({'[', ']'});

    std::cin >> str;
    try
    {
        for (int i = 0; str[i]; ++i)
        {
            if (!(str[i] == '(' || str[i] == '['))
                throw std::exception();

            ans += getPlScore(i);
        }

        std::cout << ans << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << 0 << '\n';
    }
    return (0);
}
