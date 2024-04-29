#include <iostream>

const int MAX = 20;

char str[MAX + 1];

bool isGlobal[3];
const char *checkStr = "lkp";

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int input = 0; input < 3; ++input)
    {
        std::cin >> str;
        for (int i = 0; i < 3; ++i)
        {
            isGlobal[i] |= (str[0] == checkStr[i]);
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (!isGlobal[i])
        {
            std::cout << "PONIX" <<'\n';
            return (0);
        }
    }
    std::cout << "GLOBAL" << '\n';
    return (0);
}
