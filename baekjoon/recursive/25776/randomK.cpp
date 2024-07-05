#include <iostream>

int ans;
int depthLimit, runLimit;

void    findBit(int zeroRun=0, int oneRun=0, int depth=0)
{
    if (zeroRun > runLimit || oneRun > runLimit)
    {
        return ;
    }

    if (depth == depthLimit)
    {
        ++ans;
        return ;
    }

    findBit(zeroRun + 1, 0, depth + 1);
    findBit(0, oneRun + 1, depth + 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> depthLimit >> runLimit;

    findBit();
    std::cout << ans << '\n';
    return (0);
}
