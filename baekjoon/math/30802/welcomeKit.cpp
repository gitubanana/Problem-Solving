#include <iostream>

const int SIZE_CNT = 6;

int shirtNum[SIZE_CNT];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int totalPeople;
    std::cin >> totalPeople;

    for (int i = 0; i < SIZE_CNT; ++i)
    {
        std::cin >> shirtNum[i];
    }

    int shirtBundle, penBundle;
    std::cin >> shirtBundle >> penBundle;

    int shirtOrder = 0;
    int penOrder = totalPeople / penBundle;
    int onePen = totalPeople % penBundle;
    for (int i = 0; i < SIZE_CNT; ++i)
    {
        const int &cur = shirtNum[i];

        shirtOrder += (cur / shirtBundle + (cur % shirtBundle != 0));
    }

    std::cout << shirtOrder << '\n';
    std::cout << penOrder << ' ' << onePen << '\n';
    return (0);
}
