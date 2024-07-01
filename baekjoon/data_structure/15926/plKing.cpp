#include <iostream>

const int MAX_SIZE = 200000;

int ans;
char str[MAX_SIZE + 2];

int getRightLen(int &idx)
{
    int ret = 0;

    while (str[++idx])
    {
        if (str[idx] == '(')
        {
            int nextLen = getRightLen(idx);
            if (nextLen == 0)
                return (0);

            ret += nextLen;
            ans = std::max(ans, ret);
        }
        else
        {
            ret += 2;
            break ;
        }
    }

    return (ret * (str[idx] != 0));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    int prevLen = 0;

    std::cin >> size >> str;
    for (int i = 0; str[i]; ++i)
    {
        if (str[i] == ')')
        {
            prevLen = 0;
            continue ;
        }

        int newLen = getRightLen(i);
        if (newLen == 0)
            break ;

        ans = std::max(ans, prevLen += newLen);
    }

    std::cout << ans << '\n';
    return (0);
}