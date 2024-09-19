#include <iostream>
#include <unordered_set>
#include <cstring>

template <typename T>
using t_uset = std::unordered_set<T>;

t_uset<char> elemsWithOneLen({
    'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u'
});

t_uset<std::string> elemsWithTwoLen({
	"ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
});

const int MAX_SIZE = 50'000;

char str[MAX_SIZE + 1];
bool visited[MAX_SIZE];

bool dfs(int idx=0)
{
    if (str[idx] == '\0')
    {
        return (true);
    }

    if (visited[idx])
    {
        return (false);
    }

    visited[idx] = true;
    if (elemsWithOneLen.find(str[idx]) != elemsWithOneLen.end())
    {
        if (dfs(idx + 1))
        {
            return (true);
        }
    }

    char tmp = str[idx + 2];

    str[idx + 2] = 0;
    if (elemsWithTwoLen.find(&str[idx]) != elemsWithTwoLen.end())
    {
        str[idx + 2] = tmp;
        if (dfs(idx + 2))
        {
            return (true);
        }
    }
    else
    {
        str[idx + 2] = tmp;
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"NO", "YES"};

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> str;
        memset(visited, false, sizeof(visited));
        std::cout << msg[dfs()] << '\n';
    }
    return (0);
}
