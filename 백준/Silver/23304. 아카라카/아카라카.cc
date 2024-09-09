#include <iostream>

std::string str;

inline bool isPalindrome(int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return (false);
        }

        ++start, --end;
    }
    return (true);
}

bool isEuiclee(int start, int end)
{
    if (start >= end)
    {
        return (true);
    }

    int halfSize = (end - start + 1) / 2;
    return (isPalindrome(start, end)
            && isEuiclee(start, start + halfSize - 1)
            && isEuiclee(end - halfSize + 1, end));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    const char *msg[] = {"IPSELENTI", "AKARAKA"};

    std::cin >> str;
    std::cout << msg[isEuiclee(0, str.size() - 1)] << '\n';
    return (0);
}
