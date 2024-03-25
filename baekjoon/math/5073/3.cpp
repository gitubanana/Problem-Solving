#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a == 0)
            break ;

        if (a + b <= c || b + c <= a || c + a <= b)
            std::cout << "Invalid" << '\n';
        else if (a == b && b == c)
            std::cout << "Equilateral" << '\n';
        else if (a == b || b == c || a == c)
            std::cout << "Isosceles" << '\n';
        else
            std::cout << "Scalene" << '\n';
    }
    return (0);
}
