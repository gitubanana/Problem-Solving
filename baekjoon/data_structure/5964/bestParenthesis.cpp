#include <iostream>

const char OPEN = '0';
const char CLOSE = '1';
const int MAX_SIZE = 100000;
const uint64_t DIVISOR = 12345678910;

uint64_t ans;
char pl[MAX_SIZE + 1];

uint64_t getScore(int &idx)
{
    if (pl[idx + 1] == CLOSE)
    {
        ++idx;
        return (1);
    }

    uint64_t score = 0;
    while (pl[idx])
    {
        if (pl[++idx] == OPEN)
        {
            score += getScore(idx);
        }
        else
        {
            break ;
        }
    }

    score <<= 1;
    return (score % DIVISOR);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> pl[i];
    }

    for (int i = 0; pl[i]; ++i)
    {
        ans += getScore(i);
    }

    std::cout << ans % DIVISOR << '\n';
    return (0);
}
