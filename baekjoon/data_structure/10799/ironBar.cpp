#include <iostream>
#include <stack>

int ans;
std::string str;

int    getLaserCnt(int &idx)
{
    int laserCnt = 0;

    if (str[idx + 1] == ')')
    {
        ++idx;
        return (1);
    }

    while (str[idx])
    {
        if (str[++idx] == '(')
        {
            laserCnt += getLaserCnt(idx);
        }
        else
        {
            break ;
        }
    }
    ans += laserCnt + 1;
    return (laserCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> str;
    for (int i = 0; str[i]; ++i)
    {
        getLaserCnt(i);
    }

    std::cout << ans << '\n';
    return (0);
}
