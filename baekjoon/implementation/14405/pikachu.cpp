#include <iostream>

const int   MAX = 5000;

int main(void)
{
    const char *msg[] = {"YES", "NO"};
    const char *available[] = {"pi", "ka", "chu"};
    char str[MAX + 1];

    std::cin >> str;
    int i = 0;
    while (str[i])
    {
        int idx = 0;

        for (; idx < 3; ++idx)
        {
            if (str[i] == available[idx][0])
                break ;
        }
        if (idx == 3)
            break ;

        const char *toPronounce = available[idx];

        idx = 0;
        while (toPronounce[idx] && str[i] == toPronounce[idx])
            ++i, ++idx;

        if (toPronounce[idx] != 0)
        {
            i = 0;
            break ;
        }
    }

    std::cout << msg[str[i] != 0] << '\n';
    return (0);
}
