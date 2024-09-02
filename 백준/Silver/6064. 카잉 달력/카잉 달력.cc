#include <iostream>

inline int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    return (a + b);
}

inline int lcm(int a, int b)
{
    return (a * b / gcd(a, b));
}

inline int getOrdinalNum(int m, int n, int x, int y)
{
    int curOrd = x;
    int maxOrdM = lcm(m, n) / m;

    while (maxOrdM--)
    {
        int ordN = curOrd % n;
        if (ordN == 0)
            ordN = n;

        if (ordN == y)
            return (curOrd);

        curOrd += m;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int m, n, x, y;

        std::cin >> m >> n >> x >> y;
        std::cout << getOrdinalNum(m, n, x, y) << '\n';
    }
    return (0);
}
