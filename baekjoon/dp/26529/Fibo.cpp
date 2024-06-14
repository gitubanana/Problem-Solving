#include <iostream>

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int fibo[46];

    fibo[0] = fibo[1] = 1;
    for (int n = 2; n <= 45; ++n)
    {
        fibo[n] = fibo[n - 1] + fibo[n - 2];
    }
    
    int n;
    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> n;
        std::cout << fibo[n] << '\n';
    }
    return 0;
}
