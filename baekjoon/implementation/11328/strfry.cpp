#include <iostream>

const int MAX = 1000;
const int ALPHA_SIZE = 26;

int alphaCnt[ALPHA_SIZE];
char str[MAX + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"Impossible", "Possible"};
    std::cin >> testCnt;

    while (testCnt--)
    {
        std::cin >> str;
        for (int i = 0; str[i]; ++i)
        {
            ++alphaCnt[str[i] - 'a'];
        }

        std::cin >> str;
        for (int i = 0; str[i]; ++i)
        {
            --alphaCnt[str[i] - 'a'];
        }

        bool isPossible = true;
        for (int i = 0; i < ALPHA_SIZE; ++i)
        {
            if (alphaCnt[i])
            {
                alphaCnt[i] = 0;
                isPossible = false;
            }
        }

        std::cout << msg[isPossible] << '\n';
    }
    return (0);
}
