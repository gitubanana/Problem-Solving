#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int sum = 0;
        std::string str;
    
        while (str == "")
        {
            std::getline(std::cin, str, '\n');
        }

        int num = 0;
        for (int i = 0; i <= str.size(); ++i)
        {
            const char &cur = str[i];

            if (!std::isdigit(cur))
            {
                sum += num;
                num = 0;
            }
            else
            {
                num = num * 10 + (cur - '0');
            }
        }

        std::cout << sum << '\n';
    }
    return (0);
}
