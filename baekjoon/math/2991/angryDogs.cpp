#include <iostream>

inline bool isAttacking(int curTime, int attackTime, int restTime)
{ 
    int t = curTime % (attackTime + restTime);

    return (1 <= t && t <= attackTime);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int a, b, c, d;
    int testCnt = 3;

    std::cin >> a >> b >> c >> d;
    while (testCnt--)
    {
        int t;

        std::cin >> t;
        std::cout << isAttacking(t, a, b) + isAttacking(t, c, d) << '\n';
    }
    return (0);
}
