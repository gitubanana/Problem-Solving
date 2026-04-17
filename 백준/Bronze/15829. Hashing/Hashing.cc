#include <iostream>

const size_t    r = 31;
const size_t    mod = 1234567891;

int main(void)
{
    std::string str;
    size_t      size;
    size_t      hash_value;
    size_t      multi_num;
    size_t      alphabet, power;

    std::cin >> size >> str;
    power = 1;
    hash_value = 0;
    for (size_t i = 0; i < size; ++i)
    {
        alphabet = (str[i] - 'a') + 1;
        multi_num = alphabet * power;
        hash_value += multi_num, hash_value %= mod;
        power *= r, power %= mod;
    }
    std::cout << hash_value << '\n';
    return 0;
}
