#include <iostream>
#include <cmath>
#include <map>

typedef uint64_t ull;
typedef std::map<int, ull>  t_map;

int c, base, _exp;
t_map map;


ull multiply(ull base, ull _exp)
{
    if (_exp == 1)
        return (base);

    int half = _exp / 2;
    int half2 = half + _exp % 2;

    if (map[half] == 0)
        map[half] = multiply(base, half);

    if (map[half2] == 0)
        map[half2] = multiply(base, half2);

    return ((map[half] * map[half2]) % c);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> base >> _exp >> c;
    base %= c;

    std::cout << multiply(base, _exp) << '\n';
    return (0);
}
