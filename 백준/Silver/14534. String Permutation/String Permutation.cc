#include <iostream>
#include <cstring>
#include <algorithm>

const int   MAX = 6;

char    permutation[MAX];
int     visited[MAX];

void    back_tracking(std::string &str, int idx)
{
    if (idx == str.size())
    {
        permutation[idx] = 0;
        std::cout << permutation << '\n';
        return ;
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (visited[i] == 0)
        {
            permutation[idx] = str[i];
            visited[i] = 1;
            back_tracking(str, idx + 1);
            visited[i] = 0;
        }
    }
}

int    main(void)
{
    int test_cnt;
    std::string str;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> test_cnt;
    for (int i = 1; i <= test_cnt; ++i)
    {
        std::cin >> str;
        std::cout << "Case # " << i << ":\n";
        back_tracking(str, 0);
    }
    return (0);
}