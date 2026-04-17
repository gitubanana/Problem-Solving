#include <iostream>

int main(void)
{
    int test_cnt;
    int width, height, n;
    int y, x;
    
    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> height >> width >> n;
        if (n > height)
            y = n % height + (n % height ? 0 : height), x = n / height + (n % height ? 1 : 0);
        else
            y = n, x = 1;
        std::cout << y;
        if (x < 10)
            std::cout << 0;
        std::cout << x << std::endl;
    }
    return (0);
}