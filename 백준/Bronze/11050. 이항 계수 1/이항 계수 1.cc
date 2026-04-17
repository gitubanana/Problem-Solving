#include <iostream>

int fact(int n)
{
    int ret;
    
    ret = 1;
    for (int i = 2; i <= n; i++)
        ret *= i;
    return (ret);
}

int main(void)
{
    int n, k;
    
    std::cin >> n >> k;
    std::cout << fact(n) / (fact(k) * fact(n - k));
    return (0);
}
