#include <iostream>

const int MAX = 100001;

char s[MAX];
char t[MAX];

int main(void)
{
    const char *msg[] = {"No", "Yes"};

    while (std::cin >> s >> t)
    {
        int sIdx = 0;
        int tIdx = 0;

        while (t[tIdx] && s[sIdx])
        {
            if (t[tIdx] == s[sIdx])
                ++sIdx;
            ++tIdx;
        }

        std::cout << msg[s[sIdx] == 0] << '\n';
    }
    return (0);
}
