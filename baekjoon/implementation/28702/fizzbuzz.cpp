#include <iostream>

void    fizzbuzz(int num)
{
    bool fromFive = !(num % 5);
    bool fromThree = !(num % 3);

    if (fromThree)
    {
        std::cout << "Fizz";
    }

    if (fromFive)
    {
        std::cout << "Buzz";
    }

    if (!fromFive && !fromThree)
    {
        std::cout << num;
    }

    std::cout << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 3; ++i)
    {
        std::string str;

        std::cin >> str;
        if (std::isdigit(str[0]))
        {
            fizzbuzz(std::stoi(str) + 3 - i);
            break ;
        }
    }

    return (0);
}
