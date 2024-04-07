#include <iostream>
#include <deque>

enum e_cmd
{
    FIRST = 1,
    SECOND,
    LAST
};

const int MAX = 1e6;

int cardSize;
int originCards[MAX];
std::deque<int> cardIndices;

inline void putDown(int cmd, int cardNum)
{
    int cardIdx;

    switch (cmd)
    {
    case FIRST:
        cardIdx = cardIndices[0];
        cardIndices.pop_front();
        break;
    case SECOND:
        cardIdx = cardIndices[1];
        cardIndices.erase(cardIndices.begin() + 1);
        break;
    case LAST:
        cardIdx = cardIndices.back();
        cardIndices.pop_back();
        break;
    }
    originCards[cardIdx] = cardNum;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> cardSize;
    for (int i = 0; i < cardSize; ++i)
    {
        cardIndices.push_back(i);
    }
    for (int i = 0, cmd; i < cardSize; ++i)
    {
        std::cin >> cmd;
        putDown(cmd, cardSize - i);
    }

    for (int i = 0; i < cardSize; ++i)
    {
        std::cout << originCards[i] << ' ';
    }
    std::cout << '\n';
    return (0);
}
