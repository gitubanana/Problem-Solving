#include <iostream>

const int MAX_SIZE = 1e6;

int HP;
int size;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cnt = 0;

    std::cin >> size >> HP;
    while (size--)
    {
        int attack;

        std::cin >> attack;
        if (HP > 0)
        {
            ++cnt;
            HP -= attack;
        }
    }

    std::cout << (HP > 0 ? -1 : cnt) << '\n';
    return (0);
}
