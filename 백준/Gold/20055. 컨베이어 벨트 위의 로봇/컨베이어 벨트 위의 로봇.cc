#include <iostream>

const int MAX = 200;

int belt[MAX];
bool isRobot[MAX / 2];
int size, downPos, ok;

void    moveBelt(void)
{
    int last = belt[size - 1];
    for (int i = size - 1; i >= 1; --i)
        belt[i] = belt[i - 1];
    belt[0] = last;

    for (int i = downPos; i >= 1; --i)
    {
        isRobot[i] = isRobot[i - 1];
    }
    isRobot[0] = false;
    isRobot[downPos] = false;
}

void    moveRobot(void)
{
    for (int cur = downPos - 1; cur >= 0; --cur)
    {
        int next = cur + 1;

        if (isRobot[cur] && !isRobot[next] && belt[next] > 0)
        {
            --belt[next];
            ok -= (belt[next] == 0);
            isRobot[cur] = false;
            isRobot[next] = true;
        }
    }
    isRobot[downPos] = false;
}

void    putRobot(void)
{
    if (belt[0] > 0)
    {
        --belt[0];
        ok -= (belt[0] == 0);
        isRobot[0] = true;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> ok;
    downPos = size  - 1;
    size *= 2;
    for (int i = 0; i < size; ++i)
        std::cin >> belt[i];

    int ans = 0;
    while (ok > 0)
    {
        moveBelt();
        moveRobot();
        putRobot();
        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
