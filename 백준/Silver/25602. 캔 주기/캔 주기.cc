#include <iostream>

const int MAX_CAN = 5;
const int MAX_DAY = 4;

int size;
int maxHappy;
int depthLimit;
int cnt[MAX_CAN];
int lang[MAX_DAY][MAX_CAN];
int merry[MAX_DAY][MAX_CAN];

void    backTracking(int curHappy=0, int depth=0)
{
    if (depth == depthLimit)
    {
        maxHappy = std::max(
            maxHappy,
            curHappy
        );
        return ;
    }

    for (int l = 0; l < size; ++l)
    {
        int &lCnt = cnt[l];
        if (lCnt == 0)
            continue ;

        --lCnt;
        for (int m = 0; m < size; ++m)
        {
            int &mCnt = cnt[m];
            if (mCnt == 0)
                continue ;

            --mCnt;
            backTracking(
                curHappy + lang[depth][l] + merry[depth][m],
                depth + 1
            );
            ++mCnt;
        }
        ++lCnt;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> depthLimit;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> cnt[i];
    }
    for (int day = 0; day < depthLimit; ++day)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cin >> lang[day][i];
        }
    }
    for (int day = 0; day < depthLimit; ++day)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cin >> merry[day][i];
        }
    }

    backTracking();
    std::cout << maxHappy << '\n';
    return (0);
}
