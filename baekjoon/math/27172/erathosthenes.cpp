#include <iostream>
#include <unordered_set>

const int MAX_SIZE = 1e5;
const int MAX_NUM = 1e6;

int cards[MAX_SIZE];
bool isCard[MAX_NUM + 1];
int score[MAX_NUM + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int &curCard = cards[i];

        std::cin >> curCard;
        isCard[curCard] = true;
    }

    for (int divisor = 1; divisor <= MAX_NUM; ++divisor)
    {
        if (!isCard[divisor])
            continue ;

        for (int dividend = divisor + divisor; dividend <= MAX_NUM; dividend += divisor)
        {
            if (!isCard[dividend])
                continue ;

            --score[dividend];
            ++score[divisor];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << score[cards[i]] << ' ';
    }
    std::cout << '\n';
    return (0);
}
