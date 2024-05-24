#include <iostream>
#include <vector>
#include <cmath>

const int MAX_SIZE = 1e5;
const int MAX_NUM = 1e6;

int cards[MAX_SIZE];
int score[MAX_NUM + 1];

void    countScore(int card)
{
    for (int num = card + card; num <= MAX_NUM; num += card)
    {
        --score[num];
    }

    int sqrtNum = sqrt(card);
    for (int num = 1; num <= sqrtNum; ++num)
    {
        if (card % num == 0)
        {
            score[num] += (card != num);
            int quatient = card / num;
            if (num != quatient)
            {
                score[quatient] += (card != quatient);
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int playerCnt;

    std::cin >> playerCnt;
    for (int i = 0; i < playerCnt; ++i)
    {
        int &curNum = cards[i];

        std::cin >> curNum;
        countScore(curNum);
    }

    for (int i = 0; i < playerCnt; ++i)
    {
        std::cout << score[cards[i]] << ' ';
    }
    std::cout << '\n';
    return (0);
}
