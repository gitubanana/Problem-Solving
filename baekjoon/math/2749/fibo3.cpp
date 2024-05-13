#include <iostream>
#include <unordered_map>

typedef std::unordered_map<int64_t, int> t_umap;

const int DIVISOR = 1000000;

const int PERIOD = DIVISOR / 10 * 15;
int fibo[PERIOD];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int64_t n;

    std::cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < PERIOD; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= DIVISOR;
    }
    std::cout << fibo[n % PERIOD] << '\n';
    return (0);
}
