#include <iostream>

const int MAX_SIZE = 50;

int cur;
int maxCatch, catchLimit, R, size;
int catchCnt[MAX_SIZE];

using t_func = void (*)(void);

inline void clockWise(void)
{
    cur = (cur + R) % size;
}

inline void counterClockWise(void)
{
    cur -= R;
    if (cur < 0)
    {
        cur = size + cur;
    }
}

t_func rotate[] = {
    &counterClockWise,
    &clockWise
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> catchLimit >> R;

    int ans = 0;

    catchCnt[0] = maxCatch = 1;
    while (maxCatch < catchLimit)
    {
        int &curCnt = catchCnt[cur];

        rotate[curCnt & 1]();
        maxCatch = std::max(maxCatch, ++catchCnt[cur]);
        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
